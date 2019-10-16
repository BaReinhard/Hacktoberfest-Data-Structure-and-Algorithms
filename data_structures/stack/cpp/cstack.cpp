// Implementation File

#include "cstack.h"
using namespace std;

// Default Constructor to allow for no params being passed
CStack::CStack()
{
    // Init top to be nullptr, stack is empty
    _top = nullptr;
};
// Destructor to free memory
CStack::~CStack()
{
    while (!IsEmpty())
    {
        Pop ();
    }
}
// Removes value from the top of the stack
void CStack::Pop()
{
    // Check if the array isnt empty, then pop off top stack value
    if (!IsEmpty())
    {
        CElement *new_top = _top->_element_below;
        delete _top;        //Do not forget to free memory
        _top = new_top;
    }
}
// Pushes new value to the top of the stack
void CStack::Push(char val)
{
    CElement *new_top = new CElement();     //Allocate memory for the new top element
    new_top->_element_below = _top;
    new_top->_val = val;
    _top = new_top;
}
// Returns value at top of the stack
char CStack::Top()
{
    // If array is empty, return null character
    if (IsEmpty())
    {
        return '\0';
        // Else return top Stack value
    }
    else
    {
        return _top->_val;
    }
}
// Checks whether the stack is empty, returns bool
bool CStack::IsEmpty()
{
    return _top == nullptr;
}
