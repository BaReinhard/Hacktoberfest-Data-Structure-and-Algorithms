//Graph C++
#include<iostream>
#include<vector>
using namespace std;

//class for graph , easily customisable 
class graph
{
	int vertices;
	int edges;
	vector<int> *v;

	public:
		//constructors
		graph()
		{
			vertices=0;
			edges=0;
			v=NULL;
		}
		graph(int ver,int e)
		{
			vertices=ver;
			edges=e;
			v=new vector<int>[ver+2];
		}

		//0 for undirected
		//1 for directed
		void addedge(int a,int b,int dir)
		{
			if(a>vertices || a<0 || b>vertices || b<0)
				return;
			v[a].push_back(b);
			if(dir==0)
				v[b].push_back(a);
		}
		void printedges()
		{
			vector<int>::iterator it;
			for(int i=0;i<=vertices;i++)
			{
				for(it=v[i].begin();it!=v[i].end();it++)
				{
					cout<<i<<"----"<<(*it)<<"\n";
				}
			}
		}
};

int main()
{
	graph g(5,5);
	g.addedge(1,2,1);
	g.addedge(2,3,0);
	g.addedge(4,2,1);
	g.addedge(3,1,1);
	g.addedge(3,5,0);
	g.printedges();
}
