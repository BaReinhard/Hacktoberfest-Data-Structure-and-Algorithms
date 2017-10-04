
#ifndef CSTACK_H
#define CSTACK_H

#include "celement.h"

// Header File
class CStack
{
  public:
    CStack(const CStack&) = delete;             //Forbid usage of Copy Constructor because we use raw pointers
    CStack& operator=(const CStack&) = delete;  //Forbid usage of copy assignment for the same reason
    CStack();
    ~CStack();
    char Top();
    void Pop();
    void Push(char);
    bool IsEmpty();

  private:
    CElement *_top;
};
#endif
