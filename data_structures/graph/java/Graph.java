
import java.util.ArrayList;
import java.util.HashMap;

public class Graph
{
    HashMap<String, Vertex> vtces = new HashMap<String, Vertex>();

    public static class Vertex{
        public HashMap<String, Integer> nbrs = new HashMap<>(); //<node, cost>
    }

    public int numVertex() //returns number of vertex in graph
    {
        return this.vtces.size();
    }

    public boolean containsVertex(String vname) // tells if vertex vname is present
    {
        return vtces.containsKey(vname);
    }

    public void addVertex(String vname)  // add an unconnected vertex
    {
        vtces.put(vname, new Vertex());
    }

    public void removeVertex(String vname)  // remove this vertex
    {
        // 1) first remove this vertex from the hashmaps of all its neighbours

        Vertex vtx = vtces.get(vname);  // got this vertex
        ArrayList<String> keys = new ArrayList<>(vtx.nbrs.keySet()); // got all its neighbours

        // go and  remove this vertex from all its neighbours
        for(String key : keys){
            Vertex nbrVrtx = vtces.get(key);
            nbrVrtx.nbrs.remove(vname);
        }

        // 2) remove from main graph
        vtces.remove(vname);
    }

    public int numEdges()  //returns number of edges in graph
    {
        // we'll calculate number of edges each vertex is connected to, and divide it by 2
        int count =0;
        ArrayList<String> keys = new ArrayList<>(vtces.keySet());

        for(String key : keys)
        {
            Vertex vtx = vtces.get(key);
            count += vtx.nbrs.size();
        }

        return count/2;
    }

    public boolean containsEdge(String vname1, String vname2) // tells if edge exists between 2 vertices
    {
//        return vtces.get(vname1).nbrs.containsKey(vname2); can't do this coz we need to check null

        Vertex vtx1 = this.vtces.get(vname1);
        Vertex vtx2 = this.vtces.get(vname2);

        // check if any is null
        if(vtx1==null || vtx2==null){
            System.out.print("Illegal request: Vertex doesn't exist : ");
            return false;
        }

        return vtx1.nbrs.containsKey(vname2);

    }

    public void addEdge(String vname1, String vname2, int cost)  // add an edge between 2 existing vertices
    {
        Vertex vtx1 = this.vtces.get(vname1);
        Vertex vtx2 = this.vtces.get(vname2);

        // check if any is null
        if(vtx1==null || vtx2==null){
            System.out.println("Illegal request: Vertex doesn't exist");
            return;
        }

        // check if vname2 exists in nbrs hashmap of vname1.

        if(vtx1.nbrs.containsKey(vname2)) // if an edge already exists, simply return
            return;

        // if an edge doesn't exist, add edge in both their nbrs hashmaps
        vtx1.nbrs.put(vname2, cost);
        vtx2.nbrs.put(vname1, cost);
    }

    public void removeEdge(String vname1, String vname2)
    {
        Vertex vtx1 = this.vtces.get(vname1);
        Vertex vtx2 = this.vtces.get(vname2);

        // check if any is null
        if(vtx1==null || vtx2==null){
            System.out.println("Illegal request: Vertex doesn't exist");
            return;
        }

        // check if vname2 exists in nbrs hashmap of vname1.

        // 1) if an edge doesn't exist, then work is already done. simply return
        if(!vtx1.nbrs.containsKey(vname2))
            return;

        // if an edge exists, remove vertices from their nbrs hashmaps
        vtx1.nbrs.remove(vname2);
        vtx2.nbrs.remove(vname1);
    }

    // get all vertices, and print them with their neighbours and costs
    public void display()
    {
        System.out.println("--------------");
        ArrayList<String> keys = new ArrayList<>(this.vtces.keySet());

        for(String key : keys)
        {
            Vertex vtx = this.vtces.get(key);
            System.out.println( key + " : " + vtx.nbrs );
        }

        System.out.println("--------------");
    }


}
