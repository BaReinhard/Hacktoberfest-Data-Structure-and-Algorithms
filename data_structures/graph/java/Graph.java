/**
 * Basic Undirected Graph data strucutre
 *
 * @author gutierr8@southwestern.edu
 * @param <T>
 */
public class Graph<T> {

    private Set<Node> nodes;
    private Node root; // Starting node

    public Graph(){
        nodes = new HashSet<>();
        root = null;
    }

    /**
     * Add a node to the Graph
     * @param n Node to add to the graph
     */
    public void addNode(Node n){
        nodes.add(n);
        //Set the root node if not set
        if(root == null) root = n;
    }

    /**
     * Remove a node from the graph
     * @param n Node to remove
     */
    public void removeNode(Node n){
        // Go through all nodes' adjacencies and remove node
        for(Node n : nodes)
            n.adjacencies.remove(n);
        nodes.remove(n);
    }

    /**
     * Add an edge between Node n1 and Node n2
     * @param n1 First node
     * @param n2 Second node
     */
    public void addEdge(Node n1, Node n2){
        n1.adjacencies.add(n2);
        n2.adjacencies.add(n1);
    }

    /**
     * Remove an edge, the connection between n1 and n2
     * @param n1 First Node
     * @param n2 Second Node
     */
    public void removeEdge(Node n1, Node n2){
        Set<Node> l1 = n1.adjacencies;
        Set<Node> l2 = n2.adjacencies;

        if(l1 != null)
            l1.remove(n2);

        if(l2 != null)
            l2.remove(n1);
    }

    /**
     * Get a list of nodes by breadth-first search starting from the root node
     * @return List of nodes
     */
    public List<Node> breadthFirstTraversal(){
        return breadthFirstTraversal(root);
    }

    /**
     * Get a list of nodes by breadth-first search starting from Node n
     * @param n Node to start from
     * @return A list of nodes
     */
    public List<Node> breadthFirstTraversal(Node n){
        List<Node> visited = new ArrayList<>();
        Queue<Node> queue = new LinkedList<>();
        queue.add(n);
        visited.add(n);
        while(!queue.isEmpty()){
            Node node = queue.poll();
            for(Node v : node.adjacencies){
                if(!visited.contains(v)){
                    visited.add(v);
                    queue.add(v);
                }
            }
        }
        return visited;
    }

    class Node {
        T data;
        Set<Node> adjacencies;
    }
}