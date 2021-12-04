import java.util.AbstractMap;
import java.util.AbstractSet;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Optional;
import java.util.TreeSet;
import java.util.Set;

import javafx.geometry.Point3D;

/**
 * Octree implementation of the Map interface which maps points in a certain region of 3-dimensional
 * space (represented using the javafx.geometry.Point3D class) to Objects of a specified type. For
 * the sake of convenience, most methods are overloaded to accept three double arguments in place of
 * a Point3D.
 * 
 * By default, the region of space includes point with x, y, and z coordinates ranging from
 * Long.MIN_VALUE to Long.MAX_VALUE; this should be a large enough region of space to accommodate
 * most applications without making any operations excessively slow. The boundaries of the region
 * can also be specified in the constructor. Note that Octree operations perform best when points
 * are well distributed throughout the space, so it is best to set the boundaries to include only
 * the region of space that will actually be used.
 * 
 * This implementation provides all of the optional map operations and permits null values but not
 * the null key.
 * 
 * The programmer may provide a DistFunction to the constructor to use in calculating distances for
 * nearest neighbor searches. If no DistFunction is provided, the standard Euclidean distance
 * formula will be used.
 * 
 * This implementation provides expected log(n) time cost for the containsKey, get, getNearestKey,
 * getNearestValue, getNearestEntry, put, and remove operations, assuming points are reasonably well
 * distributed within the space.
 */
public class Octree<T> extends AbstractMap<Point3D, T> {
	private Node root;
	private double xMin, xMax, yMin, yMax, zMin, zMax;
	private long size = 0;
	private Set<Map.Entry<Point3D, T>> entrySet = new EntrySet();
	private DistFunction distFunction;

	// error messages for exceptions thrown
	private static final String OUT_OF_BOUNDS = "The specified location is out of bounds.";
	private static final String NULL_KEY = "This map does not support null keys.";
	private static final String CLASS_CAST = "The key must be a Point3D.";
	private static final String INVALID_BOUNDS = "Invalid bounds. The minimum value of a coordinate cannot be greater than the maximum value.";

	/**
	 * Constructs an empty Octree where x, y, and z can be any double values between Long.MIN_VALUE
	 * and Long.MAX_VALUE.
	 */
	public Octree() {
		this(Long.MIN_VALUE, Long.MAX_VALUE);
	}

	/**
	 * Constructs an empty Octree with the specified minimum and maximum values for x, y, and z.
	 * 
	 * @param min the minimum value for x, y, and z
	 * @param max the maximum value for x, y, and z
	 * @throws IllegalArgumentException if min > max
	 */
	public Octree(double min, double max) {
		this(min, max, min, max, min, max);
	}

	/**
	 * Constructs an empty Octree with the specified minimum and maximum values for x, y, and z.
	 * 
	 * @param xMin the minimum x value
	 * @param xMax the maximum x value
	 * @param yMin the minimum y value
	 * @param yMax the maximum y value
	 * @param zMin the minimum z value
	 * @param zMax the maximum z value
	 * @throws IllegalArgumentException if xMin > xMax, yMin > yMax, or zMin > zMax
	 */
	public Octree(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax) {
		this(xMin, xMax, yMin, yMax, zMin, zMax, (xDiff, yDiff, zDiff) -> Math
				.sqrt((xDiff * xDiff) + (yDiff * yDiff) + (zDiff * zDiff)));
	}

	/**
	 * Constructs an Octree with the same mappings as the specified map where x, y, and z can be any
	 * double values between Long.MIN_VALUE and Long.MAX_VALUE.
	 * 
	 * @param map the map whose mappings are to be placed in this map
	 */
	public Octree(Map<? extends Point3D, ? extends T> map) {
		this(Long.MIN_VALUE, Long.MAX_VALUE, map);
	}

	/**
	 * Constructs an Octree with the specified minimum and maximum values for x, y, and z and the
	 * same mappings as the specified map.
	 * 
	 * @param min the minimum value for x, y, and z
	 * @param max the maximum value for x, y, and z
	 * @param map the map whose mappings are to be placed in this map
	 * @throws IllegalArgumentException if min > max
	 */
	public Octree(double min, double max, Map<? extends Point3D, ? extends T> map) {
		this(min, max, min, max, min, max, map);
	}

	/**
	 * Constructs an Octree with the specified minimum and maximum values for x, y, and z and the
	 * same mappings as the specified map.
	 * 
	 * @param xMin the minimum x value
	 * @param xMax the maximum x value
	 * @param yMin the minimum y value
	 * @param yMax the maximum y value
	 * @param zMin the minimum z value
	 * @param zMax the maximum z value
	 * @param map  the map whose mappings are to be placed in this map
	 * @throws IllegalArgumentException if xMin > xMax, yMin > yMax, or zMin > zMax
	 */
	public Octree(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax,
			Map<? extends Point3D, ? extends T> map) {
		this(xMin, xMax, yMin, yMax, zMin, zMax);
		this.putAll(map);
	}

	/**
	 * Constructs an empty Octree where x, y, and z can be any double values between Long.MIN_VALUE
	 * and Long.MAX_VALUE.
	 * 
	 * @param distFunction the function used to calculate distances for nearest neighbor searches
	 */
	public Octree(DistFunction distFunction) {
		this(Long.MIN_VALUE, Long.MAX_VALUE, distFunction);
	}

	/**
	 * Constructs an empty Octree with the specified minimum and maximum values for x, y, and z.
	 * 
	 * @param min          the minimum value for x, y, and z
	 * @param max          the maximum value for x, y, and z
	 * @param distFunction the function used to calculate distances for nearest neighbor searches
	 * @throws IllegalArgumentException if min > max
	 */
	public Octree(double min, double max, DistFunction distFunction) {
		this(min, max, min, max, min, max, distFunction);
	}

	/**
	 * Constructs an empty Octree with the specified minimum and maximum values for x, y, and z.
	 * 
	 * @param xMin         the minimum x value
	 * @param xMax         the maximum x value
	 * @param yMin         the minimum y value
	 * @param yMax         the maximum y value
	 * @param zMin         the minimum z value
	 * @param zMax         the maximum z value
	 * @param distFunction the function used to calculate distances for nearest neighbor searches
	 * @throws IllegalArgumentException if xMin > xMax, yMin > yMax, or zMin > zMax
	 */
	public Octree(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax,
			DistFunction distFunction) {
		if ((xMin > xMax) || (yMin > yMax) || (zMin > zMax))
			throw new IllegalArgumentException(INVALID_BOUNDS);
		this.xMin = xMin;
		this.xMax = xMax;
		this.yMin = yMin;
		this.yMax = yMax;
		this.zMin = zMin;
		this.zMax = zMax;
		this.distFunction = distFunction;
	}

	/**
	 * Constructs an Octree with the same mappings as the specified map where x, y, and z can be any
	 * double values between Long.MIN_VALUE and Long.MAX_VALUE.
	 * 
	 * @param map          the map whose mappings are to be placed in this map
	 * @param distFunction the function used to calculate distances for nearest neighbor searches
	 */
	public Octree(Map<? extends Point3D, ? extends T> map, DistFunction distFunction) {
		this(Long.MIN_VALUE, Long.MAX_VALUE, map, distFunction);
	}

	/**
	 * Constructs an Octree with the specified minimum and maximum values for x, y, and z and the
	 * same mappings as the specified map.
	 * 
	 * @param min          the minimum value for x, y, and z
	 * @param max          the maximum value for x, y, and z
	 * @param map          the map whose mappings are to be placed in this map
	 * @param distFunction the function used to calculate distances for nearest neighbor searches
	 * @throws IllegalArgumentException if min > max
	 */
	public Octree(double min, double max, Map<? extends Point3D, ? extends T> map,
			DistFunction distFunction) {
		this(min, max, min, max, min, max, map, distFunction);
	}

	/**
	 * Constructs an Octree with the specified minimum and maximum values for x, y, and z and the
	 * same mappings as the specified map.
	 * 
	 * @param xMin         the minimum x value
	 * @param xMax         the maximum x value
	 * @param yMin         the minimum y value
	 * @param yMax         the maximum y value
	 * @param zMin         the minimum z value
	 * @param zMax         the maximum z value
	 * @param map          the map whose mappings are to be placed in this map
	 * @param distFunction the function used to calculate distances for nearest neighbor searches
	 * @throws IllegalArgumentException if xMin > xMax, yMin > yMax, or zMin > zMax
	 */
	public Octree(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax,
			Map<? extends Point3D, ? extends T> map, DistFunction distFunction) {
		this(xMin, xMax, yMin, yMax, zMin, zMax, distFunction);
		this.putAll(map);
	}

	/**
	 * Removes all of the mappings from this map. The map will be empty after this call returns.
	 */
	@Override
	public void clear() {
		root = null;
		size = 0;
	}

	@Override
	public Set<Map.Entry<Point3D, T>> entrySet() {
		return entrySet;
	}

	/**
	 * Removes the mapping for a key from this map if it is present. More formally, if this map
	 * contains a mapping from key k to value v such that key.equals(k), that mapping is removed.
	 * (The map can contain at most one such mapping.) Returns the value to which this map
	 * previously associated the key, or null if the map contained no mapping for the key.
	 * 
	 * The map will not contain a mapping for the specified key once the call returns.
	 * 
	 * @param key key whose mapping is to be removed from the map
	 * @return the previous value associated with key, or null if there was no mapping for key
	 * @throws ClassCastException   if the key is of an inappropriate type for this map
	 * @throws NullPointerException if the specified key is null
	 */
	@Override
	public T remove(Object key) {
		if (key == null)
			throw new NullPointerException(NULL_KEY);
		if (key instanceof Point3D) {
			Point3D point = (Point3D) key;
			return remove(point.getX(), point.getY(), point.getZ());
		} else {
			throw new ClassCastException(CLASS_CAST);
		}
	}

	/**
	 * Removes the mapping for a location from this map if it is present. Returns the value to which
	 * this map previously associated the location, or null if the map contained no mapping for the
	 * location.
	 * 
	 * The map will not contain a mapping for the specified location once the call returns.
	 * 
	 * @param x the x coordinate of the location
	 * @param y the y coordinate of the location
	 * @param z the z coordinate of the location
	 * @return the previous value associated with the location, or null if there was no mapping for
	 *         the location
	 */
	public T remove(double x, double y, double z) {
		// return null if the Octree is empty
		if (root == null)
			return null;

		// otherwise pass the location to the root for handling
		return root.remove(x, y, z);
	}

	/**
	 * Returns the number of key-value mappings in this map. If the map contains more than
	 * Integer.MAX_VALUE elements, returns Integer.MAX_VALUE.
	 * 
	 * @return the number of key-value mappings in this map
	 */
	@Override
	public int size() {
		return (size > Integer.MAX_VALUE) ? Integer.MAX_VALUE : (int) size;
	}

	/**
	 * Associates the specified value with the specified key in this map. If the map previously
	 * contained a mapping for the key, the old value is replaced by the specified value. (A map m
	 * is said to contain a mapping for a key k if and only if m.containsKey(k) would return true.)
	 * 
	 * @param key   key with which the specified value is to be associated
	 * @param value value to be associated with the specified key
	 * @return the previous value associated with key, or null if there was no mapping for key.
	 * @throws NullPointerException     if the specified key is null
	 * @throws IllegalArgumentException if some property of the specified key or value prevents it
	 *                                  from being stored in this map
	 */
	@Override
	public T put(Point3D key, T value) {
		if (key == null)
			throw new NullPointerException(NULL_KEY);
		return put(key.getX(), key.getY(), key.getZ(), value);
	}

	/**
	 * Associates the specified value with the specified key in this map. If the map previously
	 * contained a mapping for the key, the old value is replaced by the specified value. (A map m
	 * is said to contain a mapping for a key k if and only if m.containsKey(k) would return true.)
	 * 
	 * @param keyX  the x coordinate of the key
	 * @param keyY  the y coordinate of the key
	 * @param keyZ  the z coordinate of the key
	 * @param value value to be associated with the specified key
	 * @return the previous value associated with key, or null if there was no mapping for key.
	 * @throws NullPointerException     if the specified key is null
	 * @throws IllegalArgumentException if some property of the specified key or value prevents it
	 *                                  from being stored in this map
	 */
	public T put(double keyX, double keyY, double keyZ, T value) {
		// throw exception if coordinates are out of bounds
		if ((keyX < xMin) || (keyX > xMax) || (keyY < yMin) || (keyY > yMax) || (keyZ < zMin)
				|| (keyZ > zMax))
			throw new IllegalArgumentException(OUT_OF_BOUNDS);

		if (root == null) {
			root = new Node(xMin, xMax, yMin, yMax, zMin, zMax, value, keyX, keyY, keyZ, null, 0);
			size++;
			return null;
		} else {
			return root.insert(value, keyX, keyY, keyZ);
		}
	}

	/**
	 * Returns the value to which the specified key is mapped, or null if this map contains no
	 * mapping for the key. More formally, if this map contains a mapping from a key k to a value v
	 * such that key.equals(k)), then this method returns v; otherwise it returns null. (There can
	 * be at most one such mapping.)
	 * 
	 * @param key the key whose associated value is to be returned
	 * @return the value to which the specified key is mapped, or null if this map contains no
	 *         mapping for the key
	 * @throws ClassCastException   if the key is of an inappropriate type for this map
	 * @throws NullPointerException - if the specified key is null
	 */
	@Override
	public T get(Object key) {
		if (key == null)
			throw new NullPointerException(NULL_KEY);
		if (key instanceof Point3D) {
			Point3D point = (Point3D) key;
			return get(point.getX(), point.getY(), point.getZ());
		} else {
			throw new ClassCastException(CLASS_CAST);
		}
	}

	/**
	 * Returns the value to which the specified key is mapped, or null if this map contains no
	 * mapping for the key. More formally, if this map contains a mapping from a key k to a value v
	 * such that key.equals(k), then this method returns v; otherwise it returns null. (There can be
	 * at most one such mapping.)
	 * 
	 * @param x the x coordinate of the key
	 * @param y the y coordinate of the key
	 * @param z the z coordinate of the key
	 * @return the value to which the specified key is mapped, or null if this map contains no
	 *         mapping for the key
	 */
	public T get(double x, double y, double z) {
		// return null if the Octree is empty
		if (root == null)
			return null;

		// otherwise pass the location to the root for handling
		return root.get(x, y, z);
	}

	/**
	 * Returns true if this map contains a mapping for the specified key. More formally, returns
	 * true if and only if this map contains a mapping for a key k such that key.equals(k). (There
	 * can be at most one such mapping.)
	 * 
	 * @param key key whose presence in this map is to be tested
	 * @return true if this map contains a mapping for the specified key
	 * @throws ClassCastException   if the key is of an inappropriate type for this map
	 * @throws NullPointerException if the specified key is null
	 */
	@Override
	public boolean containsKey(Object key) {
		if (key == null)
			throw new NullPointerException(NULL_KEY);
		if (key instanceof Point3D) {
			Point3D point = (Point3D) key;
			return containsKey(point.getX(), point.getY(), point.getZ());
		} else {
			throw new ClassCastException(CLASS_CAST);
		}
	}

	/**
	 * Returns true if this map contains a mapping for the specified key. More formally, returns
	 * true if and only if this map contains a mapping for a key k such that key.equals(k). (There
	 * can be at most one such mapping.)
	 * 
	 * @param x the x coordinate of the key
	 * @param y the y coordinate of the key
	 * @param z the z coordinate of the key
	 * @return true if this map contains a mapping for the specified key
	 */
	public boolean containsKey(double x, double y, double z) {
		// return false if the Octree is empty
		if (root == null)
			return false;

		// otherwise pass the location to the root for handling
		return root.containsKey(x, y, z);
	}

	/**
	 * Returns the key nearest to the specified location, or null if this map is empty.
	 * 
	 * @param key key whose nearest neighbor is being found
	 * @return the key nearest to the specified location
	 * @throws NullPointerException if the specified key is null
	 */
	public Point3D getNearestKey(Point3D key) {
		if (key == null)
			throw new NullPointerException(NULL_KEY);
		return getNearestKey(key.getX(), key.getY(), key.getZ());
	}

	/**
	 * Returns the key nearest to the specified location, or null if this map is empty.
	 * 
	 * @param x the x coordinate of the key
	 * @param y the y coordinate of the key
	 * @param z the z coordinate of the key
	 * @return the key nearest to the specified location
	 */
	public Point3D getNearestKey(double x, double y, double z) {
		List<Point3D> list = getNearestKeys(x, y, z, 1);
		return list.isEmpty() ? null : list.get(0);
	}

	/**
	 * Returns the entry nearest to the specified location, or null if this map is empty.
	 * 
	 * @param key key whose nearest neighbor is being found
	 * @return the entry nearest to the specified location
	 * @throws NullPointerException if the specified key is null
	 */
	public Map.Entry<Point3D, T> getNearestEntry(Point3D key) {
		if (key == null)
			throw new NullPointerException(NULL_KEY);
		return getNearestEntry(key.getX(), key.getY(), key.getZ());
	}

	/**
	 * Returns the entry nearest to the specified location, or null if this map is empty.
	 * 
	 * @param x the x coordinate of the key
	 * @param y the y coordinate of the key
	 * @param z the z coordinate of the key
	 * @return the entry nearest to the specified location
	 */
	public Map.Entry<Point3D, T> getNearestEntry(double x, double y, double z) {
		List<Map.Entry<Point3D, T>> list = getNearestEntries(x, y, z, 1);
		return list.isEmpty() ? null : list.get(0);
	}

	/**
	 * Returns a list of the n keys nearest to the specified location, or all keys in the map if the
	 * size of the map is less than n, sorted by distance from the specified location.
	 * 
	 * @param key key whose nearest neighbors are being found
	 * @param n   the number of keys to get
	 * @return the n keys nearest to the specified location
	 * @throws NullPointerException if the specified key is null
	 */
	public List<Point3D> getNearestKeys(Point3D key, int n) {
		if (key == null)
			throw new NullPointerException(NULL_KEY);
		return getNearestKeys(key.getX(), key.getY(), key.getZ(), n);
	}

	/**
	 * Returns a list of the n keys nearest to the specified location, or all keys in the map if the
	 * size of the map is less than n, sorted by distance from the specified location.
	 * 
	 * @param x the x coordinate of the key
	 * @param y the y coordinate of the key
	 * @param z the z coordinate of the key
	 * @param n the number of keys to get
	 * @return the n keys nearest to the specified location
	 */
	public List<Point3D> getNearestKeys(double x, double y, double z, int n) {
		if (root == null)
			return new ArrayList<>();
		return root.getNearestKeys(x, y, z, n);
	}

	/**
	 * Returns a list of the n entries nearest to the specified location, or all entries in the map
	 * if the size of the map is less than n, sorted by distance from the specified location.
	 * 
	 * @param key key whose nearest neighbors are being found
	 * @param n   the number of entries to get
	 * @return the n entries nearest to the specified location
	 * @throws NullPointerException if the specified key is null
	 */
	public List<Map.Entry<Point3D, T>> getNearestEntries(Point3D key, int n) {
		if (key == null)
			throw new NullPointerException(NULL_KEY);
		return getNearestEntries(key.getX(), key.getY(), key.getZ(), n);
	}

	/**
	 * Returns a list of the n entries nearest to the specified location, or all entries in the map
	 * if the size of the map is less than n, sorted by distance from the specified location.
	 * 
	 * @param x the x coordinate of the key
	 * @param y the y coordinate of the key
	 * @param z the z coordinate of the key
	 * @param n the number of entries to get
	 * @return the n entries nearest to the specified location
	 */
	public List<Map.Entry<Point3D, T>> getNearestEntries(double x, double y, double z, int n) {
		if (root == null)
			return new ArrayList<>();
		return root.getNearestEntries(x, y, z, n);
	}

	/**
	 * This method returns the distance between two specified points.
	 * 
	 * @param x1 the x coordinate of the first point
	 * @param y1 the y coordinate of the first point
	 * @param z1 the z coordinate of the first point
	 * @param x2 the x coordinate of the second point
	 * @param y2 the y coordinate of the second point
	 * @param z2 the z coordinate of the second point
	 * @return the distance between the two points
	 */
	private double getDist(double x1, double y1, double z1, double x2, double y2, double z2) {
		double xDiff = Math.abs(x1 - x2);
		double yDiff = Math.abs(y1 - y2);
		double zDiff = Math.abs(z1 - z2);
		return distFunction.getDist(xDiff, yDiff, zDiff);
	}

	/**
	 * This method returns the distance between the boundary of the specified node and the given
	 * point.
	 * 
	 * @param node the node to check
	 * @param x    the x coordinate of the point
	 * @param y    the y coordinate of the point
	 * @param z    the z coordinate of the point
	 * @return the distance between the boundary of the node and the given point
	 */
	private double getDist(Node node, double x, double y, double z) {
		double xDiff = (x > node.xMax) ? (x - node.xMax) : ((x < node.xMin) ? (node.xMin - x) : 0);
		double yDiff = (y > node.yMax) ? (y - node.yMax) : ((y < node.yMin) ? (node.yMin - y) : 0);
		double zDiff = (z > node.zMax) ? (z - node.zMax) : ((z < node.zMin) ? (node.zMin - z) : 0);
		return distFunction.getDist(xDiff, yDiff, zDiff);
	}

	/**
	 * This class represents a node in the Octree
	 */
	private class Node {
		private double xMin, x, xMax, yMin, y, yMax, zMin, z, zMax;
		private Optional<T> element;
		private double elemX, elemY, elemZ;
		private ChildNodes children;// = new ChildNodes();
		private Node parent;
		private int position;

		/**
		 * This method creates a node which covers the specified areas and contains the given
		 * element.
		 * 
		 * @param xMin     the minimum x coordinate this node covers
		 * @param xMax     the maximum x coordinate this node covers
		 * @param yMin     the minimum y coordinate this node covers
		 * @param yMax     the maximum y coordinate this node covers
		 * @param zMin     the minimum z coordinate this node covers
		 * @param zMax     the maximum z coordinate this node covers
		 * @param element  the element this node contains
		 * @param elemX    the x coordinate of the element
		 * @param elemY    the y coordinate of the element
		 * @param elemZ    the z coordinate of the element
		 * @param parent   the parent of this node, or null if this node is the root
		 * @param position the node's index within it's parent's ChildNodes object
		 */
		public Node(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax,
				T element, double elemX, double elemY, double elemZ, Node parent, int position) {
			this.xMin = xMin;
			this.xMax = xMax;
			this.x = (xMin + xMax) / 2;
			this.yMin = yMin;
			this.yMax = yMax;
			this.y = (yMin + yMax) / 2;
			this.zMin = zMin;
			this.zMax = zMax;
			this.z = (zMin + zMax) / 2;
			this.element = Optional.ofNullable(element);
			this.elemX = elemX;
			this.elemY = elemY;
			this.elemZ = elemZ;
			this.parent = parent;
			this.position = position;
		}

		/**
		 * This method checks whether this node has any non-null children.
		 * 
		 * @return true if any child nodes exist and false otherwise
		 */
		private boolean hasChildren() {
			return (children != null) && children.hasChildren();
		}

		/**
		 * This method finds the specified child if it exists.
		 * 
		 * @param xGreater true if the child's x value is greater than the parent's
		 * @param yGreater true if the child's y value is greater than the parent's
		 * @param zGreater true if the child's z value is greater than the parent's
		 * @return the specified child node
		 */
		private Node getChild(boolean xGreater, boolean yGreater, boolean zGreater) {
			return (children == null) ? null : children.getChild(xGreater, yGreater, zGreater);
		}

		/**
		 * This method inserts the given element into this node or one of its children at the given
		 * coordinates. If the given element is null, or if another element with the same
		 * coordinates is already in the Octree, this element is not inserted.
		 * 
		 * @param element the element to insert
		 * @param elemX   the x coordinate of the element
		 * @param elemY   the y coordinate of the element
		 * @param elemZ   the z coordinate of the element
		 * @return the element that was replaced, or null if there was no element at this location
		 */
		public T insert(T element, double elemX, double elemY, double elemZ) {
			// if an element at the same coordinates exists in this node, replace it with the new
			// element
			if ((this.element != null) && (this.elemX == elemX) && (this.elemY == elemY)
					&& (this.elemZ == elemZ)) {
				T retval = this.element.orElse(null);
				this.element = Optional.ofNullable(element);
				return retval;
			}

			// if coordinates match center of this node, add element to this node, reinserting
			// current element if necessary
			if ((elemX == x) && (elemY == y) && (elemZ == z)) {
				Optional<T> origElement = this.element;
				if (origElement != null) {
					this.element = null;
					size--;
					this.insert(origElement.orElse(null), this.elemX, this.elemY, this.elemZ);
				}
				this.element = Optional.ofNullable(element);
				this.elemX = elemX;
				this.elemY = elemY;
				this.elemZ = elemZ;
				size++;
				return null;
			}

			// if this point is reached, element needs to be inserted in a child node determine
			// where to insert it
			boolean xGreater = elemX > x;
			boolean yGreater = elemY > y;
			boolean zGreater = elemZ > z;
			Node child = getChild(xGreater, yGreater, zGreater);

			// if child is not null, insert the element into the appropriate child
			if (child != null) {
				return child.insert(element, elemX, elemY, elemZ);
			}

			// if child is null, create child node
			boolean hasChildren = hasChildren();
			double childXMin = xGreater ? x : xMin;
			double childXMax = xGreater ? xMax : x;
			double childYMin = yGreater ? y : yMin;
			double childYMax = yGreater ? yMax : y;
			double childZMin = zGreater ? z : zMin;
			double childZMax = zGreater ? zMax : z;
			if (children == null)
				children = new ChildNodes();
			int index = children.getIndex(xGreater, yGreater, zGreater);
			child = new Node(childXMin, childXMax, childYMin, childYMax, childZMin, childZMax,
					element, elemX, elemY, elemZ, this, index);

			// add child in appropriate place
			children.setChild(xGreater, yGreater, zGreater, child);
			size++;

			// if this was the first child node created, move root element to child node if
			// necessary
			if (!hasChildren) {
				// if the element belongs in a child node, remove it from this node then reinsert it
				if ((this.elemX != this.x) || (this.elemY != this.y) || (this.elemZ != elemZ)) {
					Optional<T> root = this.element;
					if (root != null) {
						this.element = null;
						size--;
						insert(root.orElse(null), this.elemX, this.elemY, this.elemZ);
					}
				}
			}
			return null;
		}

		/**
		 * Removes the mapping for a location from this node or its descendants if it is present.
		 * Returns the value to which this map previously associated the location, or null if the
		 * map contains no mapping for the location.
		 * 
		 * The map will not contain a mapping for the specified location once the call returns.
		 * 
		 * @param x the x coordinate of the location
		 * @param y the y coordinate of the location
		 * @param z the z coordinate of the location
		 * @return the previous value associated with the location, or null if there was no mapping
		 *         for the location
		 */
		public T remove(double x, double y, double z) {
			// find the node containing the element at the specified location
			Node n = getNode(x, y, z);

			// if there is no element at that location, return null
			if (n == null)
				return null;

			// if there is an element at that location, remove and return it
			T result = n.element.orElse(null);
			n.element = null;
			size--;
			n.removeEmptyNodes();
			return result;
		}

		/**
		 * If the current node does not contain an element and has no children, this method removes
		 * the current node from the tree and then recursively calls removeEmptyNodes() on the
		 * current node's parent.
		 */
		private void removeEmptyNodes() {
			if (!hasChildren() && (element == null)) {
				if (parent == null) {
					root = null;
				} else {
					parent.children.remove(this.position);
					parent.removeEmptyNodes();
				}
			}
		}

		/**
		 * Returns the value to which the specified key is mapped, or null if this map contains no
		 * mapping for the key. More formally, if this map contains a mapping from a key k to a
		 * value v such that key.equals(k), then this method returns v; otherwise it returns null.
		 * (There can be at most one such mapping.)
		 * 
		 * @param x the x coordinate of the key
		 * @param y the y coordinate of the key
		 * @param z the z coordinate of the key
		 * @return the value to which the specified key is mapped, or null if this map contains no
		 *         mapping for the key
		 */
		public T get(double x, double y, double z) {
			// find the node containing the element at the specified location
			Node n = getNode(x, y, z);

			// if there is an element at that location, return it, otherwise return null
			return (n != null) ? n.element.orElse(null) : null;
		}

		/**
		 * Returns true if this map contains a mapping for the specified key. More formally, returns
		 * true if and only if this map contains a mapping for a key k such that key.equals(k).
		 * (There can be at most one such mapping.)
		 * 
		 * @param x the x coordinate of the key
		 * @param y the y coordinate of the key
		 * @param z the z coordinate of the key
		 * @return true if this map contains a mapping for the specified key
		 */
		public boolean containsKey(double x, double y, double z) {
			return getNode(x, y, z) != null;
		}

		/**
		 * Returns the node containing the value to which the specified key is mapped, or null if
		 * this map contains no mapping for the key.
		 * 
		 * @param x the x coordinate of the key
		 * @param y the y coordinate of the key
		 * @param z the z coordinate of the key
		 * @return the node containing the value to which the specified key is mapped, or null if
		 *         this map contains no mapping for the key
		 */
		private Node getNode(double x, double y, double z) {
			// return null if the given coordinate is out of bounds
			if ((x < xMin) || (x > xMax) || (y < yMin) || (y > yMax) || (z < zMin) || (z > zMax))
				return null;

			// if the current node contains an element with the specified location, return the
			// current node
			if ((x == elemX) && (y == elemY) && (z == elemZ) && (element != null)) {
				return this;
			}

			// if the location of this node matches the element's location but this node does not
			// contain an element, there is no element at the specified location
			if ((x == this.x) && (y == this.y) && (z == this.z))
				return null;

			// if this point is reached, a child node must be checked
			boolean xGreater = x > this.x;
			boolean yGreater = y > this.y;
			boolean zGreater = z > this.z;
			Node child = getChild(xGreater, yGreater, zGreater);

			// if the child is null, there is no element at the specified location
			if (child == null)
				return null;

			// otherwise search in the child
			return child.getNode(x, y, z);
		}

		/**
		 * This method adds all elements in this node and its descendants to the given TreeSet (used
		 * as a priority queue) if they are potentially close enough to be among the nearest n
		 * points.
		 * 
		 * @param targetX  the x coordinate of the target point
		 * @param targetY  the y coordinate of the target point
		 * @param targetZ  the z coordinate of the target point
		 * @param n        the number of entries needed
		 * @param q        the priority queue to use
		 * @param bestDist the nth smallest dist in the queue, or Double.MAX_VALUE if the queue
		 *                 contains less than n elements
		 */
		private void addToQueue(double targetX, double targetY, double targetZ, int n,
				TreeSet<EntryDist> q, Dist bestDist, Node alreadyChecked) {
			double thisDist;
			if ((element != null) && ((thisDist = getDist(elemX, elemY, elemZ, targetX, targetY,
					targetZ)) < bestDist.dist)) {
				Map.Entry<Point3D, T> entry = new OctreeEntry(new Point3D(elemX, elemY, elemZ),
						element.orElse(null));
				q.add(new EntryDist(entry, thisDist));
				if (q.size() > n)
					q.pollLast();
				if (q.size() == n)
					bestDist.dist = q.last().dist;
			}
			if (children != null) {
				for (Node node : children.getChildren()) {
					if ((node != null) && (node != alreadyChecked)
							&& (getDist(node, targetX, targetY, targetZ) < bestDist.dist)) {
						node.addToQueue(targetX, targetY, targetZ, n, q, bestDist, null);
					}
				}
			}
		}

		/**
		 * This method returns a TreeSet containing the nearest n entries to the target point.
		 * 
		 * @param targetX the x coordinate of the target point
		 * @param targetY the y coordinate of the target point
		 * @param targetZ the z coordinate of the target point
		 * @param n       the number of entries to find
		 * @return a TreeSet containing the nearest n entries to the target point
		 */
		private TreeSet<EntryDist> findNearestEntries(double targetX, double targetY,
				double targetZ, int n) {
			TreeSet<EntryDist> q = new TreeSet<>((a, b) -> (int) Math.signum(a.dist - b.dist));
			return findNearestEntries(targetX, targetY, targetZ, n, q, new Dist(), null);
		}

		/**
		 * This method returns a TreeSet containing the nearest n entries to the target point.
		 * 
		 * @param targetX        the x coordinate of the target point
		 * @param targetY        the y coordinate of the target point
		 * @param targetZ        the z coordinate of the target point
		 * @param n              the number of entries to find
		 * @param q              a TreeSet (acting as a priority queue) to hold the entries
		 * @param bestDist       the best distance found so far
		 * @param alreadyChecked the child node which has already been explored
		 * @return a TreeSet containing the nearest n entries to the target point
		 */
		private TreeSet<EntryDist> findNearestEntries(double targetX, double targetY,
				double targetZ, int n, TreeSet<EntryDist> q, Dist bestDist, Node alreadyChecked) {
			// add entries in this node and children to queue
			addToQueue(targetX, targetY, targetZ, n, q, bestDist, alreadyChecked);

			// if this is the root node, we are done
			if (parent == null)
				return q;

			// if q has fewer than n elements, we need to check the parent
			if (q.size() < n)
				return parent.findNearestEntries(targetX, targetY, targetZ, n, q, bestDist, this);

			// compare target's distance from nth closest element in queue to target's distance from
			// the nearest boundary
			List<Double> boundaryDists = new ArrayList<>(6);
			boundaryDists.add(targetX - xMin);
			boundaryDists.add(xMax - targetX);
			boundaryDists.add(targetY - yMin);
			boundaryDists.add(yMax - targetY);
			boundaryDists.add(targetZ - zMin);
			boundaryDists.add(zMax - targetZ);
			double boundaryDist = Collections.min(boundaryDists);

			// if bestDist.dist is smaller than boundaryDist, we have found the nearest elements
			if (bestDist.dist <= boundaryDist)
				return q;

			// otherwise we have to check in the parent
			return parent.findNearestEntries(targetX, targetY, targetZ, n, q, bestDist, this);
		}

		/**
		 * This method finds and returns the n nearest entries to the target point in a TreeSet.
		 * 
		 * @param targetX the x coordinate of the target point
		 * @param targetY the y coordinate of the target point
		 * @param targetZ the z coordinate of the target point
		 * @param n       the number of entries to get
		 * @return a TreeSet containing the n nearest entries to the target point
		 */
		public TreeSet<EntryDist> getNearest(double targetX, double targetY, double targetZ,
				int n) {
			TreeSet<EntryDist> q;

			// if target coordinate is center of this node, search this node and its children
			if ((targetX == x) && (targetY == y) && (targetZ == z)) {
				q = findNearestEntries(targetX, targetY, targetZ, n);
			}
			// if target coordinate is in a child, find matching child
			else {
				boolean xGreater = targetX > x;
				boolean yGreater = targetY > y;
				boolean zGreater = targetZ > z;
				Node child = getChild(xGreater, yGreater, zGreater);

				// if child is not null, search in the child
				if (child != null)
					return child.getNearest(targetX, targetY, targetZ, n);

				// if child is null, search in children
				q = findNearestEntries(targetX, targetY, targetZ, n);
			}

			// return the queue
			return q;
		}

		/**
		 * This method finds and returns the n nearest entries to the target point as a list, sorted
		 * by distance from the target point.
		 * 
		 * @param targetX the x coordinate of the target point
		 * @param targetY the y coordinate of the target point
		 * @param targetZ the z coordinate of the target point
		 * @param n       the number of entries to get
		 * @return a list containing the n nearest entries to the target point
		 */
		public List<Map.Entry<Point3D, T>> getNearestEntries(double targetX, double targetY,
				double targetZ, int n) {
			// get a TreeSet containing the n nearest entries
			TreeSet<EntryDist> q = getNearest(targetX, targetY, targetZ, n);

			// copy entries from queue to a list and return the list
			List<Map.Entry<Point3D, T>> list = new ArrayList<>(Math.min(q.size(), n));
			int count = 0;
			for (EntryDist entryDist : q) {
				list.add(entryDist.entry);
				if (++count == n)
					break;
			}
			return list;
		}

		/**
		 * This method finds and returns the n nearest keys to the target point as a list, sorted by
		 * distance from the target point.
		 * 
		 * @param targetX the x coordinate of the target point
		 * @param targetY the y coordinate of the target point
		 * @param targetZ the z coordinate of the target point
		 * @param n       the number of keys to get
		 * @return a list containing the n nearest keys to the target point
		 */
		public List<Point3D> getNearestKeys(double targetX, double targetY, double targetZ, int n) {
			// get a TreeSet containing the n nearest entries
			TreeSet<EntryDist> q = getNearest(targetX, targetY, targetZ, n);

			// copy values from queue to a list and return the list
			List<Point3D> list = new ArrayList<>(Math.min(q.size(), n));
			int count = 0;
			for (EntryDist entryDist : q) {
				list.add(entryDist.entry.getKey());
				if (++count == n)
					break;
			}
			return list;
		}
	}

	/**
	 * This class holds a list of child nodes.
	 */
	private class ChildNodes {
		private List<Node> children = new ArrayList<>(8);

		/**
		 * Constructs an empty ChildNodes object.
		 */
		public ChildNodes() {
			for (int i = 0; i < 8; i++) {
				children.add(null);
			}
		}

		/**
		 * If the given node is null or does not appear in the list of children, this method returns
		 * the first non-null node in the list of children. If the given node is in the list of
		 * children, this method returns the first non-null node after the given node in the list.
		 * If no more non-null elements remain, this method returns null.
		 * 
		 * @param current the node to search after
		 * @return the first non-null node in the list of children after the given node, or the
		 *         first non-null node in the list if the given node is null or not in the list, or
		 *         null if no non-null nodes remain after the given node
		 */
		public Node getNext(Node current) {
			// find the index at which to start searching
			int start;
			if (current == null) {
				start = 0;
			} else {
//				start = children.indexOf(current) + 1;
				start = current.position + 1;
			}

			// search starting at the start index and return the first non-null node encountered
			for (int i = start; i < 8; i++) {
				Node next = children.get(i);
				if (next != null)
					return next;
			}

			// if the end of the list was reached and no non-null element was found, return null
			return null;
		}

		/**
		 * This method checks whether the ChildNodes object contains any non-null nodes.
		 * 
		 * @return true if any child nodes exist and false otherwise
		 */
		public boolean hasChildren() {
			for (Node node : children) {
				if (node != null)
					return true;
			}
			return false;
		}

		/**
		 * This method returns the index of the specified child node.
		 * 
		 * @param xGreater true if the child's x value is greater than the parent's x value and
		 *                 false otherwise
		 * @param yGreater true if the child's y value is greater than the parent's y value and
		 *                 false otherwise
		 * @param zGreater true if the child's z value is greater than the parent's z value and
		 *                 false otherwise
		 * @return the index of the specified child node
		 */
		public int getIndex(boolean xGreater, boolean yGreater, boolean zGreater) {
			return (xGreater ? 4 : 0) + (yGreater ? 2 : 0) + (zGreater ? 1 : 0);
		}

		/**
		 * This method returns the specified child node.
		 * 
		 * @param xGreater true if the child's x value is greater than the parent's x value and
		 *                 false otherwise
		 * @param yGreater true if the child's y value is greater than the parent's y value and
		 *                 false otherwise
		 * @param zGreater true if the child's z value is greater than the parent's z value and
		 *                 false otherwise
		 * @return the specified child node
		 */
		public Node getChild(boolean xGreater, boolean yGreater, boolean zGreater) {
			return children.get(getIndex(xGreater, yGreater, zGreater));
		}

		/**
		 * This method returns a list of all 8 children.
		 * 
		 * @return the list of children
		 */
		public List<Node> getChildren() {
			return children;
		}

		/**
		 * This method sets the specified child to the given node.
		 * 
		 * @param xGreater true if the child's x value is greater than the parent's x value and
		 *                 false otherwise
		 * @param yGreater true if the child's y value is greater than the parent's y value and
		 *                 false otherwise
		 * @param zGreater true if the child's z value is greater than the parent's z value and
		 *                 false otherwise
		 * @param child    the child node to set
		 */
		public void setChild(boolean xGreater, boolean yGreater, boolean zGreater, Node child) {
			children.set(getIndex(xGreater, yGreater, zGreater), child);
		}

		/**
		 * This method removes the given node from the ChildNodes object.
		 * 
		 * @param index the index of the node to remove
		 */
		public void remove(int index) {
			children.set(index, null);
		}
	}

	/**
	 * This class is a mutable wrapper for a double.
	 */
	private class Dist {
		double dist = Double.MAX_VALUE;
	}

	/**
	 * This class is a mutable wrapper for a map entry and a double.
	 */
	private class EntryDist {
		Map.Entry<Point3D, T> entry;
		double dist;

		/**
		 * Constructs an EntryDist containing the specified entry and double value.
		 * 
		 * @param entry the map entry to wrap
		 * @param dist  the double to wrap
		 */
		public EntryDist(Map.Entry<Point3D, T> entry, double dist) {
			this.entry = entry;
			this.dist = dist;
		}
	}

	/**
	 * Set view of the mappings contained in this map. The set is backed by the map, so changes to
	 * the map are reflected in the set, and vice-versa. If the map is modified while an iteration
	 * over the set is in progress (except through the iterator's own remove operation, or through
	 * the setValue operation on a map entry returned by the iterator) the results of the iteration
	 * are undefined. The set supports element removal, which removes the corresponding mapping from
	 * the map, via the Iterator.remove, Set.remove, removeAll, retainAll and clear operations. It
	 * does not support the add or addAll operations.
	 */
	private class EntrySet extends AbstractSet<Map.Entry<Point3D, T>> {
		private static final String SET_CLASS_CAST = "The element must be a Map.Entry<Point3D,T>.";
		private static final String NULL_ENTRY = "This set does not support null elements.";

		@Override
		public Iterator<Map.Entry<Point3D, T>> iterator() {
			return new OctreeIterator();
		}

		@Override
		public int size() {
			return Octree.this.size();
		}

		@Override
		public boolean contains(Object o) {
			// check whether the input is valid
			check(o);

			// check whether the given mapping exists in the Octree
			Map.Entry<?, ?> entry = (Map.Entry<?, ?>) o;
			Point3D key = (Point3D) entry.getKey();
			Object value = entry.getValue();
			T element = Octree.this.get(key);
			return value.equals(element);
		}

		@Override
		public boolean remove(Object o) {
			// if the Octree contains the object, remove it and return true
			if (contains(o)) {
				Octree.this.remove((Point3D) ((Map.Entry<?, ?>) o).getKey());
				return true;
			}
			// otherwise return false
			return false;
		}

		/**
		 * This method checks whether the given object is a non-null Map.Entry with a non-null
		 * Point3D key. If any of the tests fail, this method throws an exception.
		 * 
		 * @param o the object to check
		 */
		private void check(Object o) {
			// null entries are not allowed
			if (o == null)
				throw new NullPointerException(NULL_ENTRY);
			// if the input is a map entry, throw an exception if its key is null
			if (o instanceof Map.Entry<?, ?>) {
				Map.Entry<?, ?> entry = (Map.Entry<?, ?>) o;
				Object key = entry.getKey();
				if (key == null)
					throw new NullPointerException(NULL_KEY);

				// if the key is not a Point3D, throw an exception
				if (!(key instanceof Point3D)) {
					throw new ClassCastException(CLASS_CAST);
				}
			}
			// if the input is not a map entry, throw an exception
			else {
				throw new ClassCastException(SET_CLASS_CAST);
			}
		}

		@Override
		public void clear() {
			Octree.this.clear();
		}
	}

	/**
	 * A map entry (key-value pair) for an Octree.
	 */
	private class OctreeEntry extends AbstractMap.SimpleEntry<Point3D, T> {
		private static final long serialVersionUID = 1L;

		/**
		 * Constructs an OctreeEntry with the given key and value.
		 * 
		 * @param key   the key of the entry
		 * @param value the value of the entry
		 */
		public OctreeEntry(Point3D key, T value) {
			super(key, value);
		}

		@Override
		public T setValue(T value) {
			Octree.this.put(getKey(), value);
			return super.setValue(value);
		}
	}

	/**
	 * An iterator for an Octree's entry set. The iterator explores the Octree using DFS starting at
	 * the root.
	 */
	private class OctreeIterator implements Iterator<Map.Entry<Point3D, T>> {
		private Map.Entry<Point3D, T> lastReturned = null;
		private Node nextNode;

		/**
		 * Constructs an OctreeIterator.
		 */
		public OctreeIterator() {
			nextNode = root;
		}

		@Override
		public boolean hasNext() {
			// every Octree node must either contain an element or have a descendant that contains
			// an element, so if nextNode is not null, there exists an unexplored entry either in
			// nextNode or in one of its descendants
			return nextNode != null;
		}

		@Override
		public Map.Entry<Point3D, T> next() {
			// if nextNode is null, iteration has finished
			if (nextNode == null)
				throw new NoSuchElementException("The iteration has no more elements.");

			// if nextNode does not contain an element, one of its descendants does, so we can
			// advance until we find a node containing an element
			while (nextNode.element == null)
				advance();

			// once we have found an element, create an OctreeEntry for that element
			lastReturned = new OctreeEntry(
					new Point3D(nextNode.elemX, nextNode.elemY, nextNode.elemZ),
					nextNode.element.orElse(null));

			// advance to the next unexplored node if it exists
			advance();

			// return the OctreeEntry that was created
			return lastReturned;
		}

		/**
		 * If the given child node has no parent, this method sets nextNode to null. Otherwise, this
		 * method sets nextNode to the child's next sibling, if any. If the child has a parent but
		 * no unexplored siblings, this method recurses on the child's parent.
		 * 
		 * @param child the child node from which to advance
		 */
		private void advanceToSibling(Node child) {
			Node parent = child.parent;

			// if the child is the root node, iteration has finished
			if (parent == null) {
				nextNode = null;
				return;
			}

			// otherwise advance to the parent's next child after the given child
			Node nextChild = parent.children.getNext(child);
			if (nextChild != null) {
				nextNode = nextChild;
				return;
			}

			// if the parent has no more children, advance to the next sibling of the parent node
			advanceToSibling(parent);
		}

		/**
		 * This method sets nextNode to the first child of the current nextNode, if any. If nextNode
		 * has no children, this method calls advanceToSibling() to advance to nextNode's next
		 * sibling node.
		 */
		private void advance() {
			// if the current node has any children, return its first child
			Node nextChild = (nextNode.children == null) ? null : nextNode.children.getNext(null);
			if (nextChild != null) {
				nextNode = nextChild;
				return;
			}

			// otherwise advance to the next sibling of the current node
			advanceToSibling(nextNode);
		}

		/**
		 * Removes from the underlying collection the last element returned by this iterator. This
		 * method can be called only once per call to next(). The behavior of an iterator is
		 * unspecified if the underlying collection is modified while the iteration is in progress
		 * in any way other than by calling this method.
		 * 
		 * @throw IllegalStateException if the next() method has not yet been called, or the
		 *        remove() method has already been called after the last call to the next() method
		 */
		@Override
		public void remove() {
			// throw an exception if next() has not yet been called or if remove() has already been
			// called since the last call to next()
			if (lastReturned == null)
				throw new IllegalStateException(
						"The remove() method can only be called once after each call to next().");

			// remove the last returned element from the Octree and set lastReturned to null
			Octree.this.remove(lastReturned.getKey());
			lastReturned = null;
		}
	}

	/**
	 * This functional interface is used to calculate distances between two points.
	 */
	@FunctionalInterface
	public static interface DistFunction {
		/**
		 * This method is used to calculate the distance between two points. Any implementation
		 * should ensure that the calculated distance never decreases when the differences increase;
		 * in other words, for any xDiff1, yDiff1, zDiff1, xDiff2, yDiff2, and zDiff2 such that
		 * xDiff1 >= xDiff2, yDiff1 >= yDiff2, and zDiff1 >= zDiff2, it should be the case that
		 * getDist(xDiff1, yDiff1, zDiff1) >= getDist(xDiff2, yDiff2, zDiff2). Implementations which
		 * do not follow this rule may result in unexpected behavior.
		 * 
		 * @param xDiff the absolute value of the difference between the x coordinates of the two
		 *              points
		 * @param yDiff the absolute value of the difference between the y coordinates of the two
		 *              points
		 * @param zDiff the absolute value of the difference between the z coordinates of the two
		 *              points
		 * @return the distance between the two points
		 */
		double getDist(double xDiff, double yDiff, double zDiff);
	}
}
