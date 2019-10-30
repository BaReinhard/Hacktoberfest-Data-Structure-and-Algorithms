#include <bits/stdc++.h>
using namespace std;
int getMinVertex(bool * visited,int * weight,int n)
{
    int minVertex = -1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex == -1 || weight[minVertex] > weight[i]))
            minVertex = i;
    }
    return minVertex;
}
void prims(int ** edges,int n)
{
    int * parent = new int[n];
    int * weight = new int[n];
    bool *visited = new bool[n]();
    for(int i=0;i<n;i++)
        weight[i] = INT_MAX;
    parent[0] = -1;
    weight[0] = 0;
    for(int i=0;i<n-1;i++)
    {
        int minVertex = getMinVertex(visited,weight,n);
        visited[minVertex] = true;
        
        for(int j=0;j<n;j++)
        {
            if(edges[minVertex][j] != 0 && !visited[j])
            {
                if(weight[j] > edges[minVertex][j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(parent[i] < i)
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        else
            cout << i << " " << parent[i] << " " << weight[i] << endl;
    }
    delete [] parent;
    delete [] weight;
    delete [] visited;
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
    int ** edges = new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i] = new int[V];
        for(int j=0;j<V;j++)
            edges[i][j] = 0;
    }
    for(int i=0;i<E;i++)
    {
        cin >> tempX >> tempY;
        cin >> edges[tempX][tempY];
        edges[tempY][tempX] = edges[tempX][tempY];
    }
    
    prims(edges,V);
    
  return 0;
}
