import java.util.*;

class Graph
{
	private class Edge {
		int src, dest, weight;
		private Edge(int src, int dest, int weight) {
			this.src = src;
			this.dest = dest;
			this.weight = weight;
		}
	};

	private int V;
	private LinkedList<Edge> edgeList;
	public Graph(int v)
	{
		this.V = v;
		edgeList = new LinkedList<Edge>();
	}

	public void bellmanFord(int src) {
		if (src < 0 || src > (V - 1)) {
			System.out.println("Invalid starting vertex");
			return;
		}
		
		int dist[] = new int[V];

		for (int i=0; i<V; ++i)
			dist[i] = Integer.MAX_VALUE;
		dist[src] = 0;

		for (int i=1; i < V; ++i) {
			for (int j=0; j <  edgeList.size(); ++j) {		
				int u = edgeList.get(j).src;
				int v = edgeList.get(j).dest;
				int weight = edgeList.get(j).weight;
				
				if (dist[u] != Integer.MAX_VALUE && dist[u] + weight<dist[v]) {
					dist[v]=dist[u]+weight;
				}
			}
		}

		for (int j = 0; j < edgeList.size(); ++j) {
			int u = edgeList.get(j).src;
			int v = edgeList.get(j).dest;
			int weight = edgeList.get(j).weight;
			
			if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
				System.out.println("Graph contains negative weight cycle");
				return;
			}
			
		}
		
		printArr(dist, V);
	}

	private void printArr(int dist[], int V)
	{
		System.out.println("Vertex Distance from Source");
		for (int i=0; i<V; ++i)
			System.out.println(i+"tt"+dist[i]);
	}
	
	public boolean addEdge(int src, int dest, int weight) {
		if (src < 0 || dest < 0 || src > (V - 1) || dest > (V - 1)) {
			return false;
		}
		
		Edge edge = new Edge(src, dest, weight);
		edgeList.add(edge);
		return true;
	}

	public static void main(String[] args)
	{
		int V = 5;

		Graph graph = new Graph(V);
		
		graph.addEdge(0, 1, -1);
		graph.addEdge(0, 2, 4);
		graph.addEdge(1, 2, 3);
		graph.addEdge(1, 3, 2);
		graph.addEdge(1, 4, 2);
		graph.addEdge(3, 2, 5);
		graph.addEdge(3, 1, 1);
		graph.addEdge(4, 3, -3);

		graph.bellmanFord(1);
	}
}
