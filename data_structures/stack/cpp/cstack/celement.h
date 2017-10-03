#ifndef CELEMENT_H
#define CELEMENT_H

/**
 * An element of a CStack : contains a char value and a pointer to the element just below in the stack
 */
struct CElement {
	CElement *_element_below;		//Next element in the stack
	char _val;
};

#endif // CELEMENT_H included
