#include<iostream>
#include<cstdio>
using namespace std;

//Edge Structure to store the edges
struct Edge{
    int vertex; //vertex to which the edge goes
    Edge* next; //next pointer to next vertex

    Edge(){
        //default constructor. No Use here
    }

    Edge(int v){
        vertex = v;
        next = NULL;
    }
};

struct Graph{
    int V; //no. of vertexes
    int E; //no. of edges
    Edge **edges; //adjacent list to contain edges

    Graph(){
        printf("Enter Number of Vertex: ");
        scanf("%d", &V);

        printf("Enter Number of Edges: ");
        scanf("%d", &E);

        edges = new Edge*[V]; //dynamic allocation of adjacent list
        for(int i=0;i<V;i++){
            edges[i] = NULL;
        }
    }

    Graph(int V, int E){
        this->V = V;
        this->E = E;
        edges = new Edge*[V];
    }

    void addEdge(int source, int destination){
        if(edges[source] == NULL){
            edges[source] = new Edge(destination);
        } else {
            Edge* current = edges[source];
            while(current->next != NULL){
                current = current->next;
            }
            current->next = new Edge(destination);
        }
    }

    void printGraph(){
        for(int i=0;i<V;i++){
            Edge* current = edges[i];
            if(current != NULL){
                printf("%d--%d ", i,current->vertex);
                while(current->next != NULL){
                    current = current->next;
                    printf("%d--%d ", i,current->vertex);
                }
            }

            printf("\n");
        }
    }

    void DFSUtil(int v, bool visited[]){
        visited[v] = true;
        printf("%d ", v);

        Edge* current = edges[v];
        while(current != NULL){
            if(!visited[current->vertex]){
                DFSUtil(current->vertex, visited);
            }
            current = current->next;
        }
    }

    void DFS(){
        bool* visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }

        DFSUtil(0, visited);
    }
};

int main(){

    Graph *g = new Graph();

    //No. of vertexes are 4
    //No. of edges are 6

    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(2, 0);
    g->addEdge(2, 3);
    g->addEdge(3, 3);

    printf("The obtained graph is: \n");
    g->printGraph();

    printf("\nDeepth First Search on given Graph is: \n");
    g->DFS(); //source is 0th node

    return 0;
}
