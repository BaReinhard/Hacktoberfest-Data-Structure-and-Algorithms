/**
 * A Java program for Dijkstra's single source shortest path algorithm.
 * The program is for adjacency matrix representation of the graph
 */
public class ShortestPath {
    private static final int vertexNumber = 9;

    private int minDistance(int dist[], Boolean sptSet[]) {
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int v = 0; v < vertexNumber; v++) {
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    private void printSolution(int dist[]) {
        System.out.println("Vertex   Distance from Source");
        for (int i = 0; i < vertexNumber; i++)
            System.out.println(i + " \t\t " + dist[i]);
    }

    /**
     * Dijkstra's single source shortest path
     *
     * @param graph The graph represented using adjacency matrix
     * @param source Source vertex
     */
    public void dijkstra(int graph[][], int source) {
        int dist[] = new int[vertexNumber];

        Boolean sptSet[] = new Boolean[vertexNumber];

        for (int i = 0; i < vertexNumber; i++) {
            dist[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
        }

        dist[source] = 0;

        for (int count = 0; count < vertexNumber-1; count++) {
            int u = minDistance(dist, sptSet);

            sptSet[u] = true;

            for (int v = 0; v < vertexNumber; v++) {
                if (!sptSet[v] && graph[u][v] != 0 &&
                        dist[u] != Integer.MAX_VALUE &&
                        dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        printSolution(dist);
    }

    /**
     * Usage
     * @param args
     */
    public static void main (String[] args) {
        int graph[][] = new int[][]{{0, 4, 0, 0, 0, 0, 0, 8, 0},
                {4, 0, 8, 0, 0, 0, 0, 11, 0},
                {0, 8, 0, 7, 0, 4, 0, 0, 2},
                {0, 0, 7, 0, 9, 14, 0, 0, 0},
                {0, 0, 0, 9, 0, 10, 0, 0, 0},
                {0, 0, 4, 14, 10, 0, 2, 0, 0},
                {0, 0, 0, 0, 0, 2, 0, 1, 6},
                {8, 11, 0, 0, 0, 0, 1, 0, 7},
                {0, 0, 2, 0, 0, 0, 6, 7, 0}
        };

        ShortestPath t = new ShortestPath();
        t.dijkstra(graph, 0);
    }
}