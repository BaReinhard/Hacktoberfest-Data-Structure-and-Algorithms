#ifndef STACK_H
#define STACK_H

#include <stdexcept>

/*
 * Templated class declaration and definition
 * in a single file for portability
 *
 */
template <typename Object>
class Stack {
private:
	class Node {
	friend Stack;
	private:
		Node * next;
		Object data;
	public:
		Node(const Object & d, Node * n): 
			data(d), next(n) {  }
	};

	int length {0};
	Node * head {nullptr};

public:
	// Default ctor but clear on destruction
	Stack() {  };
	~Stack() { clear(); };

	// Returns the number of elements in the stack
	int size() { 
		return length; 
	}

	// Adds an element on top of the stack
	void push(const Object & value) {
		head = new Node(value, head);
		++length;
	}

	// Returns top element form the stack
	Object top() {
		if ( head != nullptr )
			return head->data;
		throw std::logic_error("Cannot return top from an empty stack");
	}

	// Removes top element from the stack
	void pop() {
		if ( head != nullptr )
		{
			Node * tmp {head};
			head = head->next;
			--length;
			delete tmp;
		} else
			throw std::logic_error("Cannot remove top from an empty stack");
	}

	// Tests wether or not the stack is empty
	bool empty() { 
		return length == 0; 
	}

	// Removes all element from the stack
	void clear() {
		while ( !empty() )
			pop();
	}
};
#endif
