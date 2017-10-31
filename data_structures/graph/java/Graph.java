import java.util.*;

class Graph{
	
	HashMap<Integer, List<Integer>> adj;
	
	Graph(){
		
		adj = new HashMap<Integer , List<Integer>>();
	}
	
	void setEdge(int org, int dest) {
		
		if(adj.containsKey(org)) {
			
			List<Integer> list = adj.get(org);
			list.add(dest);
			adj.put(org, list);
		}
		
		else {
			
			ArrayList<Integer> list = new ArrayList<Integer>();
			list.add(dest);
			adj.put(org, list);
		}
	}
	
	boolean isNeighbour(int org , int dest) {
		
		if(!adj.containsKey(org)) {
			return false;
		}
		
		for(Integer i : adj.get(org)) {
			
			if(i == dest) {
				return true;
			}
		}
		
		return false;
	}
	
	void removeEdge(int org , int dest) {
		
		if(!adj.containsKey(org)) {
			System.out.println("Error.Enter a valid vertex");
		}
		
		else {
			
			Iterator<Integer> it = adj.get(org).iterator();
			while(it.hasNext()) {
				int ele = it.next();
				if(ele == dest) {
					it.remove();
				}
			}
		}
	}
	
	void printGraph() {
			
			for(Integer i : adj.keySet()) {
				
				List<Integer> list = adj.get(i);
				System.out.println("Key - "+i+"---> "+list);
			}
	}
	
	public static void main(String args[]) {
		
		Graph g = new Graph();
		g.setEdge(0, 1);
		g.setEdge(0, 2);
		g.setEdge(1, 2);
		g.removeEdge(0, 2);
		g.printGraph();
		System.out.println(g.isNeighbour(0, 2));
	}
	
}