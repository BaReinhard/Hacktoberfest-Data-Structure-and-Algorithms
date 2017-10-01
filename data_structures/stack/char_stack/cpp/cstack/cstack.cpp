// Implementation File

#include <iostream>
#include "cstack.h"
using namespace std;

// Default Constructor to allow for no params being passed
CStack::CStack()
{
    // Init top to be -1, array is empty
    _top = -1;
};
// Removes value from the top of the stack
void CStack::Pop()
{
    // Check if the array isnt empty, then pop off top stack value
    if (!IsEmpty())
    {
        _top = _top - 1;
    }
}
// Pushes new value to the top of the stack
void CStack::Push(char val)
{
    // Check if the array isn't full, then add new val
    if (!IsFull())
    {
        // Increase _top to the next index
        _top = _top + 1;
        // Set new value to array location
        _data[_top] = val;
    }
}
// Returns value at top of the stack
char CStack::Top()
{

    char empty;
    // If array is empty, return empty character
    if (IsEmpty())
    {
        return empty;
        // Else return top Stack value
    }
    else
    {
        return _data[_top];
    }
}
// Checks whether the stack is empty, returns bool
bool CStack::IsEmpty()
{
    // Check if the index is -1, if so return true.
    // If not return false
    return _top == -1;
}
// Checks whether the Stack is full, returns bool
bool CStack::IsFull()
{
    // Check if the index is less than equal to 18, if so return true.
    // If not return false
    return _top >= 18;
}
