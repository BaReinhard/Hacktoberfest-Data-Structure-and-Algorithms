package minimumSpanningTree;

import java.util.Scanner;

public class Prims {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int e=s.nextInt();
		
		int edges[][]=new int[n][n];
		
		for(int i=0;i<e;i++)
		{
			int fv=s.nextInt();
			int sv=s.nextInt();
			int wt=s.nextInt();
			edges[fv][sv]=wt; 
			edges[sv][fv]=wt;  //undirected graph
		}
		
		primsMST(edges);
	}
	
	public static void primsMST(int[][] edges) {
		boolean visited[]=new boolean[edges.length];
		int parent[]=new int[edges.length];
		int weights[]=new int[edges.length];
		
		for(int i=0;i<weights.length;i++)
		{
			weights[i]=Integer.MAX_VALUE;
			visited[i]=false;
		}
		
		parent[0]=-1;
		weights[0]=0;
		
		for(int count=0;count<edges.length-1;count++)
		{
			int current=minWeightVertex(weights,visited); //get vertex with minimum weights and unvisited one
			visited[current]=true;
			
			for(int i=0;i<edges.length;i++)
			{
				if(!visited[i] && edges[current][i]!=0 && edges[current][i]<weights[i]) //update parent and weights
				{
					weights[i]=edges[current][i];
					parent[i]=current;
				}
			}
			
			
			
		}
		
		for(int i=1;i<parent.length;i++)
		{
			System.out.println(i+" "+parent[i]+" "+weights[i]);
		}
		
	}
	
	private static int minWeightVertex(int[] weights,boolean[] visited)
	{
		int min=Integer.MAX_VALUE;
		int minVertex=0;
		
		for(int i=0;i<weights.length;i++)
		{
			if(!visited[i] && weights[i]<min)
			{
				min=weights[i];
				minVertex=i;
			}
		}
		
		return minVertex;
		
	}
}
