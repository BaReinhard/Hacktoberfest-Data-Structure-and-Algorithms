package minimumSpanningTree;

import java.util.*;

public class Kruskal {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int e=s.nextInt();
		
		Edge edges[]=new Edge[e];
		
		for(int i=0;i<e;i++) //input edges
		{
			int a=s.nextInt();
			int b=s.nextInt();
			int wt=s.nextInt();
			edges[i]=new Edge(a,b,wt);
		}
		kruskalMST(edges, n);
	}

	public static void kruskalMST(Edge[] edges,int n)
	{
		Arrays.sort(edges,new Edge());//sort edges on weight basis
		int parent[]=new int[n];//parent array
		for(int i=0;i<parent.length;i++)
		{
			parent[i]=i;
		}
		
		Edge result[]=new Edge[n-1];//result array
		int i=0,count=0;
		while(count<n-1) //cycle detection //Union-Find Algo
		{
			Edge currEdge=edges[i++];
			int sourceParent=findParent(parent,currEdge.source);
			int destinationParent=findParent(parent,currEdge.destination);
			
			if(sourceParent!=destinationParent)
			{
				parent[sourceParent]=destinationParent;
				result[count++]=currEdge;
			}
			
		}
		
		for(int k=0;k<result.length;k++)
		{
			System.out.println(result[k].source+" "+result[k].destination+" "+result[k].weight);
		}
	}

	private static int findParent(int[] parent, int source) {
		if(parent[source]==source)
			return source;
		return findParent(parent,parent[source]);
	}

}


class Edge implements Comparator<Edge>{
	int source;
	int destination;
	int weight;
	Edge(){
		
	}
	Edge(int source,int destination, int weight){
		this.source=source;
		this.destination=destination;
		this.weight=weight;
	}
	@Override
	public int compare(Edge o1, Edge o2) {
		return o1.weight-o2.weight;
	}
	
	
}