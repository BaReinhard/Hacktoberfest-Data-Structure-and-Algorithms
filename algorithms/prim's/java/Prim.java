package psa.naloga5;

import java.util.Arrays;

public class Prim
{
	int[][] data;
	int n;
	int[] minWeights;
	boolean[] visited;
	int[] parents;

	public Prim(int n)
	{
		data = new int[n][n];
		this.n = n;
		visited = new boolean[n];
		minWeights = new int[n];
		parents = new int[n];
	}

	public Prim(int[][] d)
	{
		data = cloneMatrix(d);
		n = d.length;
		visited = new boolean[n];
		minWeights = new int[n];
		parents = new int[n];
	}

	public void addEdge(int i, int j, int d)
	{
		data[i][j] = d;
		data[j][i] = d;
	}

	public int MSTcost()
	{
		prim(0);
		int cost = 0;
		for (int weight : minWeights)
			cost += weight;

		return cost;
	}

	public int[] prim(int s)
	{
		int currentVertex;
		// Reinitializing arrays in case of having a different starting vertex
		Arrays.fill(visited, false);
		Arrays.fill(minWeights, Integer.MAX_VALUE);
		Arrays.fill(parents, 0);

		int visitedCount = 0;
		while (++visitedCount != n)
		{
			if (visitedCount == 1)
				currentVertex = s;
			else
				currentVertex = getNextVertex(visited);
			visited[currentVertex] = true;
			checkNeighbours(currentVertex);
		}

		for (int i = 0; i < minWeights.length; i++)
			if (minWeights[i] == Integer.MAX_VALUE)
				minWeights[i] = 0; // Add to 0 so we can get the sum of min weigths array

		return parents;
	}

	private int getNextVertex(boolean[] visited)
	{
		int min = Integer.MAX_VALUE;
		int currentVertex = 0;

		for (int i = 0; i < n; i++)
			if (!visited[i] && minWeights[i] <= min)
			{
				currentVertex = i;
				min = minWeights[i];
			}

		return currentVertex;
	}

	public void checkNeighbours(int currentVertex)
	{
		boolean isVisited;
		boolean edgeExists;
		boolean hasSmallerWeight;

		for (int i = 0; i < n; i++)
		{
			isVisited = !visited[i];
			edgeExists = data[currentVertex][i] != 0;
			hasSmallerWeight = data[currentVertex][i] < minWeights[i];

			if (isVisited && edgeExists && hasSmallerWeight)
			{
				minWeights[i] = data[currentVertex][i];
				parents[i] = currentVertex;
			}
		}
	}

	public int[][] cloneMatrix(int[][] matrix)
	{
		int[][] cloned = new int[matrix.length][matrix[0].length];

		for (int i = 0; i < matrix.length; i++)
			System.arraycopy(matrix[i], 0, cloned[i], 0, matrix[i].length);

		return cloned;
	}
}
