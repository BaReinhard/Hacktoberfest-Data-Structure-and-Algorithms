#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;

class MinHeap{
public:
    MinHeap();
    ~MinHeap();
    void insert(int item);
    int deleteMin();
    void printSelf();
private:
    void bubbleUp(int index);
    void bubbleDown(int index);
    vector<int> _heap;
};

#endif //MINHEAP_H
