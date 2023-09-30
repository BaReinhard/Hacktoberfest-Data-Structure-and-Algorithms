// Add Package path

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Set;
import java.util.Stack;

public class Graph2 {
	private class Vertex {
		String name;
		HashMap<Vertex, Integer> neighbors;

		public Vertex(String name) {
			this.name = name;
			this.neighbors = new HashMap<>();
		}

		public boolean equals(Object other) {
			Vertex ov = (Vertex) other;
			return this.name.equals(ov.name);
		}

		public int hashCode() {
			return this.name.hashCode();
		}

		public void display() {
			String rv = "";
			rv = rv + this.name + "=>";
			Set<Vertex> nbrs = this.neighbors.keySet();
			for (Vertex nbr : nbrs) {
				rv = rv + nbr.name + "(" + this.neighbors.get(nbr) + "),";
			}
			rv = rv + "END";
			System.out.println(rv);

		}
	}

	HashMap<String, Vertex> vertices;

	public Graph2() {
		this.vertices = new HashMap<>();
	}


	public void addVertex(String name) {
		if (vertices.containsKey(name)) {
			return;
		}
		Vertex vtx = new Vertex(name);
		this.vertices.put(name, vtx);
	}

	public void removeVertex(String name) {
		if (!vertices.containsKey(name)) {
			return;
		}
		Vertex vtx = this.vertices.get(name);
		Set<Vertex> nbrs = vtx.neighbors.keySet();
		for (Vertex nbr : nbrs) {
			nbr.neighbors.remove(vtx);
		}
		this.vertices.remove(name);
	}

	public int numEdges() {
		int rv = 0;
		Collection<Vertex> values = this.vertices.values();
		for (Vertex value : values) {
			rv = rv + value.neighbors.size();
		}
		rv = rv / 2;
		return rv;
	}

	public void addEdge(String v1, String v2, int weight) {
		Vertex vtx1 = this.vertices.get(v1);
		Vertex vtx2 = this.vertices.get(v2);
		if (vtx1 == null || vtx2 == null || vtx1.neighbors.containsKey(vtx2)) {
			return;
		}
		vtx1.neighbors.put(vtx2, weight);
		vtx2.neighbors.put(vtx1, weight);
	}

	public void removeEdge(String v1, String v2) {
		Vertex vtx1 = this.vertices.get(v1);
		Vertex vtx2 = this.vertices.get(v2);
		if (vtx1 == null || vtx2 == null || !vtx1.neighbors.containsKey(vtx2)) {
			return;
		}
		vtx1.neighbors.remove(vtx2);
		vtx2.neighbors.remove(vtx1);
	}

	public void display() {
		Set<String> vtces = this.vertices.keySet();
		for (String str : vtces) {
			Vertex vtx = this.vertices.get(str);
			vtx.display();
		}
		System.out.println("******************");
	}

public static void main(String[] args) {
		Graph2 g = new Graph2();
		g.addVertex("A");
		g.addVertex("B");
		g.addVertex("C");
		g.addVertex("D");
		g.addVertex("E");
		g.addVertex("F");
		g.addVertex("G");
		g.addEdge("A", "B", 10);
		g.addEdge("B", "C", 10);
		g.addEdge("A", "D", 40);
		g.addEdge("C", "D", 10);
		g.addEdge("D", "E", 2);
		g.addEdge("F", "G", 3);
		g.addEdge("E", "G", 3);
		g.display();
   }
}
