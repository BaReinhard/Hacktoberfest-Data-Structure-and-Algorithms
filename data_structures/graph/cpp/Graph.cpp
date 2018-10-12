#include <iostream>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int *parent;

/**
 * author: Gabriella Mara 
 * github: https://github.com/gmarap
 */
class Graph {

private:
    int numVertex;
    int **adj;
    bool *visited;

public:
    Graph(int numVertex);
    ~Graph();
    void addEdge(int origin, int destin, int weight);
    void delEdge(int origin, int destin);
    int getEdge(int origin, int destin);
    void display();
    void print();
    bool isConnected(int origin, int destin);
    bool emptyVertex(int v);
    bool emptyMat();
    int getNumVertex();
    long dfs(int origin, int destin);
    long dfs(int origin, int destin, int prev);
    void dfsT(int node);
    void bfsT(int node);
    int minDistance(long dist[], bool sptSet[]);
    long dijkstra(int origin, int destin);
    void printPath(int parent[], int j);
    int printSolution(long dist[], int parent[]);
    void delMinPath(int origin, int destin);
};

/**
 * Construtor
 */
Graph::Graph(int numVertex) {
    this->numVertex = numVertex;

    visited = new bool [numVertex]; // Criando um array de bool [visitado = true || não visitado = false]
    
    // Alocando memória para a matriz de adjacência
    adj = new int* [numVertex];
    for (int i = 0; i < numVertex; i++) {
        adj[i] = new int [numVertex];
        for(int j = 0; j < numVertex; j++) {
            adj[i][j] = 0; // Inicializando todas as posições com 0
        }
    }
}


/**
 * Destrutor
 */
Graph::~Graph() {
  for (int i = 0; i < this->numVertex; i++) {
    delete [] this->adj[i];
  }
  delete [] this->adj;
}

/**
 * Retorna o número de vértices do Grafo
 */
int Graph::getNumVertex() {
    return this->numVertex;
}

/**
 * Adiciona uma aresta do vértice "origin" até o "destin", de peso "weight"
 */
void Graph::addEdge(int origin, int destin, int weight) {

    // Verifica se os vértices são válidos
    if( origin > this->numVertex || destin > this->numVertex || origin < 0 || destin < 0) {   
        cout << "Invalid edge!\n";
    }
    else {
        adj[origin][destin] = weight; // Adiciona o "destin" como adjacente de "origin"
        adj[destin][origin] = weight; // Adiciona o "origin" como adjacente de "destin"
    }
}

/**
 * Verifica se dois vértices estão conectados
 */
bool Graph::isConnected(int origin, int destin) {
    return (this->adj[origin][destin] > 0);
}

/**
 * Deleta uma aresta que conecta o vértice "origin" ao "destin" e retorna seu peso ou 0 (caso não exista)
 */
void Graph::delEdge(int origin, int destin) {
  
    int wei = this->adj[origin][destin];
    
    // Verifica se a aresta existe
    if(wei > 0) {
        this->adj[origin][destin] = this->adj[destin][origin] = 0; // Seta o valor da aresta como 0 (apaga)
    }
}

/**
 * Retorna o peso, ou 0 (caso não exista), da aresta que conecta o vértice "origin" ao "destin"
 */
int Graph::getEdge(int origin, int destin) {
    return this->adj[origin][destin];
}

/**
 * Faz uma busca por profundidade do vértice "origin" até o "destin"
 */
long Graph::dfs(int origin, int destin) {
    return dfs(origin, destin, origin);
}

long Graph::dfs(int origin, int destin, int prev) {
    
    long sum = 0;

    for( int i = (prev + 1) % getNumVertex(); i != prev; i = (i + 1) % getNumVertex() ){
        
        // Verifica se o vértice de origem e o "i" estão conectados e se "i" não é o vértice anterior
        if(adj[origin][i] != 0 && i != prev){
            sum = dfs(i, destin, origin); 
        }

        // Verifica se já achou alguma aresta ou se "i" é o vértice de destino e tem conexão com o atual
        if(sum != 0 || (i == destin && adj[origin][i] != 0)){
            sum += adj[origin][i]; // Soma o peso da aresta
            break;
        }
    }
    return sum;
}

/**
 * Faz a busca por profundidade no Grafo, a partir do vértice "node"
 */
void Graph::dfsT(int node) {
    this->visited[node] = true;
    int i;
    cout << node << " ";

    for(i = 0; i < this->numVertex; i++) {
        if(adj[node][i] && !this->visited[i]) {
            dfsT(i);
        }
    }

    cout << endl;
}

/**
 * Faz a busca por largura no Grafo, a partir do vértice "node"
 */
void Graph::bfsT(int node) {
    this->visited[node]=true;
    queue<int> qu;
    qu.push(node);

    while(!qu.empty()) {
        int element = qu.front();
        int i;
        qu.pop();
        cout << element << " ";
        for(i = 0; i < this->numVertex; i++) {
            if(adj[element][i] && !this->visited[i]) {
                qu.push(i);
                this->visited[i] = true;
            }
        }
    }
}

/**
 * Verifica se o vértice é isolado
 */ 
bool Graph::emptyVertex(int v) {
  for (int i = 0; i < this->numVertex; i++) {
    if (adj[v][i] > 0) {
      return false;
    }
  }
  return true;
}

/**
 * Verifica se a matriz está vazia
 */
bool Graph::emptyMat() {
    for(int i = 0; i < this->numVertex; i++) {
        for(int j = 0; j < this->numVertex; j++) {
            if (adj[i][j] > 0) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Printa o Grafo
 */ 
void Graph::display() {

    cout << "\n\n            ";
    for(int i = 0; i < this->numVertex; i++) { 
      printf("%10d  ", i);
    }

    cout << "\n\n";
    for (int i = 0; i < this->numVertex; i++) { 
      
      printf("%10d  ", i);
      for (int j = 0; j < this->numVertex; j++) {
        printf("%10d  ", this->adj[i][j]);
      }
      cout << endl;
    }
    cout << "\n\n";
}

/**
 * Pega o vértice de menor distância que não foi fechado ainda
 */
int Graph::minDistance(long dist[], bool sptSet[]) {
     
    long min = INT_MAX;
    int minIndex;
 
    for (int i = 0; i < this->numVertex; i++) {
        if (sptSet[i] == false && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}


/**
 * Retorna o menor caminho entre dois vértices
 */
long Graph::dijkstra(int origin, int destin) {
    
    int N = this->numVertex;

    long dist[N]; // dist[i] terá a menor distância de src até i
 
    bool sptSet[N]; // sptSet[i] será true se i está no menor caminho ou o menor caminho de src para i foi finalizado
 
    parent = new int[N];
 
    for (int i = 0; i < N; i++){
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
 
    dist[origin] = 0; // A distância de um vértice até ele mesmo é sempre 0
 
    for (int count = 0; count < N - 1; count++){

        int u = minDistance(dist, sptSet); // Pega o vértice de menor distância que ainda não foi fechado
 
        sptSet[u] = true; // Fecha o vértice u
 
        for (int i = 0; i < N; i++) {
 
            // Só atualize dist[v] se ele não estiver em sptSet &&
            // Se existir uma aresta entre u e v &&
            // Se valor total do caminho de src até v, passando por u for menor que dist[v]
            if (!sptSet[i] && this->isConnected(u,i) && (( dist[u] + this->adj[u][i] ) < dist[i])) {
                parent[i] = u;
                dist[i] = dist[u] + this->adj[u][i];
            } 
        }
    }
    return dist[destin];
}

/**
 * Deleta o menor caminho do Grafo
 */
void Graph::delMinPath(int origin, int destin) {
    if(origin == destin) {
        return;
    }
    else {
        this->delEdge(destin, parent[destin]);
        delMinPath(origin, parent[destin]);
    }
}

/**
 * Printa o caminho 
 */
void Graph::printPath(int parent[], int j) {
     
    if (parent[j] == - 1)
        return;
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}
 
/**
 * Printa o valor do menor caminho da origem a cada vértice, com seu respectivo caminho 
 */
int Graph::printSolution(long dist[], int parent[]) {
    int src = 0;
    
    printf("Vertex\t Distance\tPath");
    
    for (int i = 1; i < this->numVertex; i++) {
        printf("\n%d -> %d \t\t %ld\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}