import java.util.*;

/**
 * Represents a directed graph using adjacency list
 */
class Graph {
    private int vertexNumber;
    private LinkedList<Integer> adj[];

    /**
     *
     * @param v number of vertex
     */
    Graph(int v) {
        vertexNumber = v;
        adj = new LinkedList[v];
        for (int i=0; i<v; ++i)
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
     *
     * @param v
     * @param visited
     */
    private void DFSUtil(int v, boolean visited[])  {
        visited[v] = true;
        System.out.print(v + " ");

        for (Integer n : adj[v]) {
            if (!visited[n])
                DFSUtil(n, visited);
        }
    }

    /**
     * To do DFS traversal. It uses recursive DFSUtil()
     * @param source source vertex
     */
    void DFS(int source) {
        boolean[] visited = new boolean[vertexNumber];

        DFSUtil(source, visited);
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

        g.DFS(2);
    }
}