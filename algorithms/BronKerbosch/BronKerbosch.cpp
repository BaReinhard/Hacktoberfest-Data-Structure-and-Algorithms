#include <iostream>
#include <fstream>
#include "Vector.h"

#define maxn 100000

using namespace std;

ifstream in("bkr.in");

Vector <int> Graf[maxn];
int N,M;

Vector <int> maxClique;
bool found = false;

int viz[maxn];

int find(Vector<int> P,int x)
{
	for(Vector<int>::iterator it = P.begin(); it != P.end(); it++)
		if(*it == x)
			return 1;

	return 0;	

}

Vector<int>  del(Vector<int> P,int x)
{
	for(Vector<int>::iterator it = P.begin(); it != P.end(); it++)
		if(P[*it] == x)
		{
			int aux;
			aux = P[*it];
			P[*it] = P[*(P.end()-1)];
			P[*(P.end()-1)] = aux;
			P.pop_back();
			return P;
		}

	Vector<int> v;
	return v;
}

void BronKerbosch(Vector <int> R , Vector <int> P, Vector <int> X)
{
	if(X.empty() && P.empty())
	{	
		maxClique = R;
		found = true;
	}

	int length = P.mySize();
	while(length--)
	{ 
		int it = *(P.begin());

		Vector <int> newP;
		Vector <int> newX;

		for(int i = 0; i < (int) Graf[it].mySize(); i++)
		{
			if(find(P,Graf[it][i]))
			{
				newP.push_back(Graf[it][i]);
			}

			if(find(X,Graf[it][i]))
			{
				newX.push_back(Graf[it][i]);
			}

		}
		
		if(!found)
		{
			R.push_back(it);
			BronKerbosch(R, newP, newX);

			R = del(R,it);


			P = del(P,it);
			X.push_back(it);
		}
	}
}



int main()
{
	in>>N>>M;
	int x,y;

	Vector <int> P;
	Vector <int> R;
	Vector <int> X;

	while(M--)
	{
		in>>x>>y;
		Graf[x].push_back(y);
		Graf[y].push_back(x);

		if(!viz[x])
			P.push_back(x);
		if(!viz[y])
			P.push_back(y);

		viz[x] = 1;
		viz[y] = 1;
		
	}
	
	BronKerbosch(R,P,X);

    cout<<maxClique.mySize()<<"\n";
	for(Vector<int>::iterator it = maxClique.begin(); it != maxClique.end(); it++)
		cout<<*it<<" ";		

	cout<<"\n";
	
	return 0;
}
