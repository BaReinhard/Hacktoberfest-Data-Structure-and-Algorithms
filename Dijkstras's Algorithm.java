import java.util.*;

// Data structure to store graph edges
class Edge
{
	int source, dest, weight;

	public Edge(int source, int dest, int weight) {
		this.source = source;
		this.dest = dest;
		this.weight = weight;
	}
}

// Data structure to store heap nodes
class Node {
	int vertex, weight;

	public Node(int vertex, int weight) {
		this.vertex = vertex;
		this.weight = weight;
	}
}

// class to represent a graph object
class Graph
{
	// A List of Lists to represent an adjacency list
	List<List<Edge>> adjList = null;

	// Constructor
	Graph(List<Edge> edges, int N)
	{
		adjList = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			adjList.add(new ArrayList<>());
		}

		// add edges to the undirected graph
		for (Edge edge: edges) {
			adjList.get(edge.source).add(edge);
		}
	}
}

class Main
{
	private static void getRoute(int[] prev, int i, List<Integer> route)
	{
		if (i >= 0) {
			getRoute(prev, prev[i], route);
			route.add(i);
		}
	}

	// Run Dijkstra's algorithm on given graph
	public static void shortestPath(Graph graph, int source, int N)
	{
		// create min heap and push source node having distance 0
		PriorityQueue<Node> minHeap = new PriorityQueue<>(Comparator.comparingInt(node -> node.weight));
		minHeap.add(new Node(source, 0));

		// set infinite distance from source to v initially
		List<Integer> dist = new ArrayList<>(Collections.nCopies(N, Integer.MAX_VALUE));

		// distance from source to itself is zero
		dist.set(source, 0);

		// boolean array to track vertices for which minimum
		// cost is already found
		boolean[] done = new boolean[N];
		done[source] = true;

		// stores predecessor of a vertex (to print path)
		int[] prev = new int[N];
		prev[source] = -1;

		List<Integer> route = new ArrayList<>();

		// run till minHeap is empty
		while (!minHeap.isEmpty())
		{
			// Remove and return best vertex
			Node node = minHeap.poll();

			// get vertex number
			int u = node.vertex;

			// do for each neighbor v of u
			for (Edge edge: graph.adjList.get(u))
			{
				int v = edge.dest;
				int weight = edge.weight;

				// Relaxation step
				if (!done[v] && (dist.get(u) + weight) < dist.get(v))
				{
					dist.set(v, dist.get(u) + weight);
					prev[v] = u;
					minHeap.add(new Node(v, dist.get(v)));
				}
			}

			// marked vertex u as done so it will not get picked up again
			done[u] = true;
		}

		for (int i = 1; i < N; ++i)
		{
			if (i != source && dist.get(i) != Integer.MAX_VALUE) {
				getRoute(prev, i, route);
				System.out.printf("Path (%d -> %d): Minimum Cost = %d and Route is %s\n", source, i, dist.get(i), route);
				route.clear();
			}
		}
	}

	public static void main(String[] args)
	{
		// initialize edges as per above diagram
		// (u, v, w) triplet represent undirected edge from
		// vertex u to vertex v having weight w
		List<Edge> edges = Arrays.asList(
				new Edge(0, 1, 10), new Edge(0, 4, 3),
				new Edge(1, 2, 2), new Edge(1, 4, 4),
				new Edge(2, 3, 9), new Edge(3, 2, 7),
				new Edge(4, 1, 1), new Edge(4, 2, 8),
				new Edge(4, 3, 2)
		);

		// Set number of vertices in the graph
		final int N = 5;

		// construct graph
		Graph graph = new Graph(edges, N);

		int source = 0;
		shortestPath(graph, source, N);
	}
}
