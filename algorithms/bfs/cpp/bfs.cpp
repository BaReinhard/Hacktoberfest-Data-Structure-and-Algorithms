
#import <vector>
#import <queue>
#import <iostream>

class Vertex {
public:
    Vertex(std::string n);

    Vertex * prev; //predecessor
    Vertex *next;   //for queue purposes
    int dist;
    std::string name;
    std::vector <Vertex *> neighbours;
};

Vertex::Vertex(std::string n) {
    prev = nullptr;
    next = nullptr;
    dist = -1;
    name = n;
}

class Queue{
public:
    Queue(Vertex *first){
        head = first;
        tail = first;
        first->dist = 0;
    }
    void Enqueue(Vertex *pred_, Vertex * cur) {
        if(head == nullptr) {
            head = cur;
        }
        cur->dist = pred_->dist+1;
        cur->prev = pred_;
        tail->next = cur;
        tail = cur;
    }

    Vertex * Dequeue(){
        Vertex *tmp = head;
        head = head->next;
        return tmp;
    }

    bool isEmpty(){
        return head== nullptr;
    }

    bool isInQueue(Vertex v){
        Vertex *iter = head;
        while(iter != nullptr) {
            if (iter->name == v.name)
                return true;
            iter = iter->next;
        }
        return false;
    }
    Vertex *head;
    Vertex *tail;

};


void BFS(Vertex *root) {

    Queue q(root);
    Vertex *cur;
    int dist=0;
    root->dist = 0;
    while(!q.isEmpty()) {

        cur = q.Dequeue();
        for (Vertex *v : cur->neighbours) {
            if (q.isInQueue(*v))
                continue;
            cur->dist = dist;
            q.Enqueue(cur,v);
        }
        dist++;
    }
}

int main() {
    Vertex v1("v1");
    Vertex v2("v2");
    Vertex v3("v3");
    Vertex v4("v4");
    v1.neighbours.emplace_back(&v2);
    v1.neighbours.emplace_back(&v3);
    v2.neighbours.emplace_back(&v3);
    v3.neighbours.emplace_back(&v4);
    v1.neighbours.emplace_back(&v4);
    BFS(&v1);
    std::cout << v1.dist << "   v2prevname" << v2.prev->name << "    " << v3.dist << "    " << v4.dist;
    return 0;
}

