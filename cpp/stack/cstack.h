
#ifndef CSTACK_H
#define CSTACK_H
#include <iostream>
using namespace std;

// Header File
class CStack
{

  public:
    CStack();
    char Top();
    void Pop();
    void Push(char);
    bool IsEmpty();
    bool IsFull();

  private:
    int _top;
    char _data[21];
};
#endif
