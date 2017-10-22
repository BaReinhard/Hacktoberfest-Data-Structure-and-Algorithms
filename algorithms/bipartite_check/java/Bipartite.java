import java.util.*;
// import java.util.stream.*;

public class Bipartite {
  public static final int n = 100;
  public static final int[] col;
  public static final int[][] G;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int nodes = sc.nextInt();
    int edges = sc.nextInt();
    init();
    IntStream.range(0, edges).forEach(i -> {
        int u = sc.nextInt();
        int v = sc.nextInt();
        G[u][v] = -1;
        G[u][v] = -1;
    });
  }

  public boolean isBipartite(int start) {
      col[start] = 1;
      Queue queue = new LinkedList();
      queue.push(start);
      while(!queue.isEmpty()) {
        int u = queue.poll();
        IntStream.range(1, nodes + 1).forEach(i -> {
          if (G[u][i] == 1 && col[i] == -1) {
            col[i] = 1 - col[u];
            q.push(i);
          } else {
            if (G[u][i] == 1 && col[i] == col[u]) return false;
          }
        });
      }
  }

  public static void init() {
    col = new int[n];
    G = new int[n][n];
    Arrays.fill(col, -1);
    for(int[] row : G) {
      Arrays.fill(row, 0);
    }
  }
}
