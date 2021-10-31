#include <iostream>
#include <vector>
using std::vector;

class MinHeap
{
public:
  MinHeap();
  MinHeap(vector<int>);
  void push(int);
  int pop();
  int size() { return heap.size(); }

private:
  int left(int);
  int right(int);
  int parent(int);
  void siftUp(int);
  void siftDown(int);
  vector<int> heap;

};

MinHeap::MinHeap()
{
}

MinHeap::MinHeap(vector<int> nums) {
  heap = nums;
  for (int i = nums.size() / 2 - 1; i >= 0; i--)
    siftDown(i);
}


void MinHeap::push(int element)
{
  heap.push_back(element);
  siftUp(heap.size() - 1);
}

int MinHeap::pop()
{
  int top = heap.front();
  heap[0] = heap.at(heap.size() - 1);
  heap.pop_back();
  siftDown(0);
  return top;
}


void MinHeap::siftUp(int index)
{

  while ((index > 0) && (parent(index) >= 0) &&
         (heap[parent(index)] > heap[index]))
  {
    int tmp = heap[parent(index)];
    heap[parent(index)] = heap[index];
    heap[index] = tmp;
    index = parent(index);
  }
}

void MinHeap::siftDown(int index)
{

  int child = left(index);
  if ((child > 0) && (right(index) > 0) &&
      (heap[child] > heap[right(index)]))
  {
    child = right(index);
  }
  if (child > 0)
  {
    int tmp = heap[index];
    heap[index] = heap[child];
    heap[child] = tmp;
    siftDown(child);
  }
}

int MinHeap::left(int parent)
{
  int i = (parent * 2) + 1;
  return (i < heap.size()) ? i : -1;
}

int MinHeap::right(int parent)
{
  int i = (parent * 2) + 2;
  return (i < heap.size()) ? i : -1;
}

int MinHeap::parent(int child)
{
  if (child != 0)
  {
    int i = (child - 1) / 2;
    return i;
  }
  return -1;
}