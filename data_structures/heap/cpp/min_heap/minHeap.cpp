#include "minHeap.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Some helpers first
// The left child of node in index i is: 2*i+1
// The right child of node in index i is: 2*i+2
// The parent of the node in index i is: (int)((i-1)/2)

int getLeftIndex(int x){
    return 2*x+1;
}

int getRightIndex(int x){
    return 2*x+2;
}

int getParentIndex(int x){
    return (int)((x-1)/2);
}


MinHeap::MinHeap(){}

MinHeap::~MinHeap(){}

void MinHeap::insert(int item){
    int length = _heap.size();
    _heap.push_back(item);
    bubbleUp(length);
}

int MinHeap::deleteMin(){
    int length = _heap.size();

    if(length == 0){
        return -1;
    }
    int min = _heap[0];
    
    _heap[0] = _heap[length-1];
    _heap.pop_back();

    bubbleDown(0);
    return min;
}

void MinHeap::printSelf(){
    cout << "Heap printing...\n";
    if(_heap.size() == 0){
        cout << "There is nothing in the heap\n";
        return;
    }
    for(int i = 0;i < _heap.size();i++){
        cout << _heap.at(i) << ", ";
    }
    cout << endl;
}

void MinHeap::bubbleDown(int index){
    int length = _heap.size();
    int leftChildIndex = getLeftIndex(index);
    int rightChildIndex = getRightIndex(index);

    if(leftChildIndex >= length)
        return; //index is a leaf

    int minIndex = index;

    if(_heap[index] > _heap[leftChildIndex]){
        minIndex = leftChildIndex;
    }
    
    if((rightChildIndex < length) && (_heap[minIndex] > _heap[rightChildIndex])){
        minIndex = rightChildIndex;
    }

    if(minIndex != index){
        //need to swap
        int temp = _heap[index];
        _heap[index] = _heap[minIndex];
        _heap[minIndex] = temp;
        bubbleDown(minIndex);
    }
}

void MinHeap::bubbleUp(int index){
    if(index == 0)
        return;

    int parentIndex = getParentIndex(index);

    if(_heap[parentIndex] > _heap[index]){
        int temp = _heap[parentIndex];
        _heap[parentIndex] = _heap[index];
        _heap[index] = temp;
        bubbleUp(parentIndex);
    }
}