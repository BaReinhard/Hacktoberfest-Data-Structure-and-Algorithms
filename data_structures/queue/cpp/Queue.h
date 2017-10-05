#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template<class T>
class Queue
{
    struct Node
    {
        Node(T v, Node* pre){value = v; prev = pre;}
        T value;
        Node* prev;
    };
    public:
        Queue();
        Queue(T value, int intial_size);
        T* Front();
        void Pop();
        void Push(T value);
        int Size();
        void Print();
        virtual ~Queue();

    protected:

    private:
        Node* tail;
        Node* head;
        int sz;
};

#endif // QUEUE_H
