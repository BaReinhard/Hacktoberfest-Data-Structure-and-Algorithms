//Given a matrix of N*M order. Find the shortest distance from a source cell to a destination cell, traversing through limited cells only. 
//Also you can move only up, down, left and right. If found output the distance else -1.
//s represents ‘source’
//d represents ‘destination’
//* represents cell you can travel
//0 represents cell you can not travel

static class pair {
	int i;
	int y;
	int dist;
	pair(int i, int y, int dist)
	{
		this.i= i;
		this.y = y;
		this.dist = dist;
	}
}


public static void bfs(char graph[][],int n,int m,boolean visited[][]){
		
		
		pair p = new pair(0,0,0);
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j<m;j++){
				if(graph[i][j] == '0')
					visited[i][j] = true;
				else
					visited[i][j] = false;
				
				if(graph[i][j] == 's'){
//					source = graph[i][j];
					p.i = i;
					p.y =j;
					
				}
			}
		}
		visited[p.i][p.y] = true;
		LinkedList<pair> q = new LinkedList<>();
		q.add(p);
		boolean flag = false;
		
		while(!q.isEmpty()){
			//visited[graph[i][j]] = true;
			
			pair pp = q.remove();
			
			if(graph[pp.i][pp.y] == 'd'){
				flag = true;
				System.out.println(pp.dist);
				return;
			}
			
			if(pp.i - 1 >= 0 && graph[pp.i-1][pp.y] != '0' && visited[pp.i-1][pp.y] == false)
			{
				visited[pp.i-1][pp.y] = true;
				pair mp = new pair(pp.i-1,pp.y, pp.dist + 1);
				q.add(mp);
			}
			if(pp.y - 1>= 0 && graph[pp.i][pp.y - 1] != '0' && visited[pp.i][pp.y - 1] == false)
			{
				visited[pp.i][pp.y - 1] = true;
				pair mp = new pair(pp.i,pp.y -1, pp.dist + 1);
				q.add(mp);
			}
			if(pp.i + 1 < graph.length && graph[pp.i+ 1][pp.y] != '0' && visited[pp.i + 1][pp.y] == false)
			{
				visited[pp.i+ 1][pp.y] = true;
				pair mp = new pair(pp.i+1,pp.y, pp.dist + 1);
				q.add(mp);
			}
			if(pp.y +1 < graph[0].length && graph[pp.i][pp.y + 1] != '0' && visited[pp.i][pp.y + 1] == false)
			{
				visited[pp.i][pp.y + 1] = true;
				pair mp = new pair(pp.i,pp.y + 1, pp.dist + 1);
				q.add(mp);
			}
		}
		
		if(!flag)
		System.out.println("-1");
		}
