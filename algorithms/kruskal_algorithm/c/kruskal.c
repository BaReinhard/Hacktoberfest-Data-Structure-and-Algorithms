#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int node1;
    int node2;
    long long int weight;
}Node;

int id[100005], nodes, edges;
Node p[100005];

void initialize()
{
    for(int i = 0;i < 100005; ++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union_1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long int kruskal(Node p[])
{
    int x, y;
    long long int cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        cost = p[i].weight;
        x = p[i].node1;
        y = p[i].node2;
        if(root(y) != root(x))
        {
            minimumCost += cost;
            union_1(x, y);
        }    
    }
    return minimumCost;
}

int comp(const void *p, const void *q)
{
    Node* x = (Node*)p;
    Node* y = (Node*)q;
    if(x->weight < y->weight)
        return 1;
    else if(x->weight == y->weight)
        if(x->node1 > y->node1)
            return 1;
    return -1;
}

int main()
{
    int x, y;
    long long int weight, cost, minCost;
    initialize();
    scanf("%d%d",&nodes,&edges);
    for(int i = 0;i < edges;++i)
    {
        scanf("%d%d%lld",&x,&y,&weight);
        p[i].weight = weight;
        p[i].node1 = x;
        p[i].node2 = y;
    }
    qsort(p, edges, sizeof(Node), comp);
    minCost = kruskal(p);
    printf("%lld\n", minCost);
    return 0;
}
