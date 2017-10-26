import java.util.*;

/**
 * Represents a directed graph using adjacency list
 */
public class Graph {
    private int vertexNumber;
    private LinkedList[] adj;

    /**
     *
     * @param v number of vertex
     */
    public Graph(int v) {
        vertexNumber = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    /**
     * Add edge into graph
     * @param v vertex
     * @param w vertex
     */
    public void addEdge(int v, int w)  {
        adj[v].add(w);
    }

    /**
     * Prints BFS traversal from a given source vertex
     * @param source source vertex
     */
    public void BFS(int source) {
        boolean visited[] = new boolean[vertexNumber];

        LinkedList<Integer> queue = new LinkedList<>();

        visited[source] = true;
        queue.add(source);

        while (queue.size() != 0) {
            source = queue.poll();
            System.out.print(source + " ");

            for (Integer n : (Iterable<Integer>) adj[source]) {
                if (!visited[n]) {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }

    /**
     * Test
     * @param args
     */
    public static void main(String args[]) {
        Graph g = new Graph(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        g.BFS(2);
    }
}