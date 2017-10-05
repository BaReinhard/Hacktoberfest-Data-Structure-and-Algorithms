

#import <vector>
#import <queue>
#import <iostream>


class Vertex {
public:
    Vertex(std::string n);

    bool visited;
    Vertex * prev; //predecessor
    int dist;
    std::string name;
    std::vector <Vertex *> neighbours;
};

Vertex::Vertex(std::string n) {
    prev = nullptr;
    dist = -1;
    name = n;
}

void VisitVertex(Vertex *v, Vertex * predecessor){
    v->prev = predecessor;
    v->visited = true;
    for (Vertex * successor : v->neighbours) {
        if (!successor->visited)
            VisitVertex(successor,v);
    }
}

void DFS(std::vector <Vertex *> graph){
    Vertex * predecessor = nullptr;
    for (Vertex * v: graph ) {
        v->visited = false;
    }
    for (Vertex * v: graph ) {
        if (!v->visited)
            VisitVertex(v, predecessor);
        predecessor = v;
    }

}

int main() {

    //testing

    Vertex v1("v1");
    Vertex v2("v2");
    Vertex v3("v3");
    Vertex v4("v4");
    v1.neighbours.emplace_back(&v2);
    v1.neighbours.emplace_back(&v3);
    v4.neighbours.emplace_back(&v3);
    v3.neighbours.emplace_back(&v4);
    v1.neighbours.emplace_back(&v4);

    std::vector <Vertex *> graph;
    graph.emplace_back(&v1);
    graph.emplace_back(&v2);
    graph.emplace_back(&v3);
    graph.emplace_back(&v4);

    DFS(graph);
    std::cout << "v1 prev: " << v1.prev <<std::endl;
    std::cout << "v2 prev: " << v2.prev->name <<std::endl;
    std::cout << "v3 prev: " << v3.prev->name <<std::endl;
    std::cout << "v4 prev: " << v4.prev->name <<std::endl;
    return 0;
}