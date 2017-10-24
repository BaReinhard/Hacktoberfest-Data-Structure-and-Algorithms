// Simple queue data structure using singly linked list
#include <iostream>

// List node
template <typename T>
struct QueueNode {
	// Constructor. Set node value and initialize next node pointer to NULL
	QueueNode<T>(T _value) {
		value = _value;
		pNext = NULL;
	}
	
	T value; // Value stored in node
	QueueNode<T> *pNext; // Next node in linked list
};

// Queue structure
template <typename T>
class CQueue {
public:
	// Constructor. Initialize head & tail pointer to NULL.
	CQueue<T>() {
		m_pHead = m_pTail = NULL;
	}

	// Push a new element into the queue
	void enqueue(T value) {
		QueueNode<T> *pNewTail = new QueueNode<T>(value);
		
		if (m_pHead == NULL)
			m_pHead = m_pTail = pNewTail;
		else {
			m_pTail->pNext = pNewTail;
			m_pTail = pNewTail;
		}
	}
	
	// Pop the head element from the queue
	T dequeue() {
		if (m_pHead == NULL)
			return NULL;
		
		T value = m_pHead->value;
		QueueNode<T> *pNewHead = m_pHead->pNext;
		delete m_pHead;
		m_pHead = pNewHead;
		
		return value;
	}
	
	// Check if the queue is empty
	bool isEmpty() {
		return m_pHead == NULL;
	}
	
private:
	QueueNode<T> *m_pHead; // Head node of linked list
	QueueNode<T> *m_pTail; // Tail node of linked list
};

using namespace std;

int main() {
	CQueue<int> queue;
	
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	
	while (!queue.isEmpty())
		cout << queue.dequeue() << ' ';
	
	return 0;
}
