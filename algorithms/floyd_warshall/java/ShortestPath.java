/**
 * A Java program for Floyd Warshall All Pairs Shortest
 * Path algorithm.
 */
public class ShortestPath {
    private final static int VERTEX_NUMBER = 4;
    private final static int MAX_VALUE = 999999;

    public void floydWarshall(int graph[][]) {
        int dist[][] = new int[VERTEX_NUMBER][VERTEX_NUMBER];
        int i, j, k;

        for (i = 0; i < VERTEX_NUMBER; i++)
            for (j = 0; j < VERTEX_NUMBER; j++)
                dist[i][j] = graph[i][j];

        for (k = 0; k < VERTEX_NUMBER; k++) {
            for (i = 0; i < VERTEX_NUMBER; i++) {
                for (j = 0; j < VERTEX_NUMBER; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        printSolution(dist);
    }

    private void printSolution(int dist[][]) {
        for (int i = 0; i < VERTEX_NUMBER; ++i) {
            for (int j = 0; j < VERTEX_NUMBER; ++j) {
                if (dist[i][j] == MAX_VALUE) {
                    System.out.print("INF ");
                } else {
                    System.out.print(dist[i][j] + "   ");
                }
            }
            System.out.println();
        }
    }

    /**
     * Test
     * @param args
     */
    public static void main (String[] args) {
        int graph[][] = {
                {0,         5,          MAX_VALUE,  10},
                {MAX_VALUE, 0,          3,          MAX_VALUE},
                {MAX_VALUE, MAX_VALUE,  0,          1},
                {MAX_VALUE, MAX_VALUE,  MAX_VALUE,  0}
        };

        ShortestPath a = new ShortestPath();

        a.floydWarshall(graph);
    }
}
