/*********************************************************
Dalton Polhill     0930905
Linked List ADT
June 2016
**********************************************************/
#ifndef _LIST_H
#define _LIST_H


struct listNode{
    struct listNode * next;
    struct listNode * prev;
    void * data;
};
typedef struct listNode Node;


struct list
{
    Node * head;
    Node * tail;
    int size;
    int (*destroy)(void *);
    void (*print)(void *);
};
typedef struct list List;

/* 
List * createList(int (* destroy)(void *), void (* print)(void *),int(*compare)(void*,void*));
Input: (* destroy)(void *), (* print)(void *)
Output: List *
Preconditions: destroy and print functions are defined by the module 
Postconditions: a list is created and returned, the destroy and compare functions are set as elements of the list, size is set to 0. returns NULL on unable to allocate memory
*/

List * createList(int (* destroy)(void *), void (* print)(void *));

/* 
int * destroyList(List *);

Input: List *
Output: int
Preconditions: a list exists
Postconditions: all the data associated with the list is freed.
                returns 0 on clean exit, 1 otherwise.
*/
int destroyList(List * theList);

/*
int getSize(List * list);

Input: List *
Output: int
Preconditions: an initialized list is passed in 
Postconditions: the size of the list is returned
*/
int getSize(List * theList);

/*
List * insertFront(List * theList, void * data);

Input: List *, void * 
Output: List *
Preconditions: an initialized list is passed in
Postconditions: if the list is not full the data is added, becoming the new head of the list, the new list is returned.
                else (the list is full) return the passed in list unchanged, print a message telling the user the list is full
*/
List * insertFront(List * theList, void * data);


/*
List * insertBack(List * theList, void * data);

Input: List *, void *
Output: List *
Preconditions: an initialized list is inputted 
Postconditions: if the list is not full the data is added to the back of the list and the new list is returned
                else (the list is full) return the passed in list unchanged print a message telling the user the list is full
*/
List * insertBack(List * theList, void * data);

/*
List * insertNth(List * theList, void * data, int n);

Input: List *, void *, int
Output: List *
Preconditions: an initialized list is passed in
Postconditions: if the list is not full the data is added to the nth position of the list
                if the list is full return the list unchanged, print a message to the user telling them the list is full
*/
List * insertNth(List * theList, void * data, int n);

/*
List * removeHead(List * theList);

Input: List *, void *
Output: List *
Preconditions: an initialized list is passed in, there is dat in the head 
Postconditions: the data within the head is destroyed and the new list is return, with the second element in the list being the new head
                return NULL if the head is NULL

*/
List * removeHead(List * theList);

/*
List * removeTail(List * theList);

Input: List *, void *
Output: List *
Preconditions: an initialized list is passed in, there is dat in the head 
Postconditions: the data within the Tail is destroyed and the new list is return, with the second element in the list being the new head
                return NULL if the tail is NULL
*/
List * removeTail(List * theList);

/*
List * removeNth(List * theList, int n);

Input: List *, void *, int
Output: List *
Preconditions: an initialized list is passed in, there is dat in the head 
Postconditions: the data within the Nth element is destroyed and the new list is return, with the second element in the list being the new head
                return NULL if the Nth element is NULL

*/
List * removeNth(List * theList, int n);

/*
void * getHeadData(List * theList);

Input: List *
Output: void *
Preconditions: an initialized list is passed in, the head has data in it 
Postconditions: the data pointer is returned on success
                NULL otherwise
*/
void * getHeadData(List * theList);

/*
void * getTailData(List * theList);

Input: List *
Output: void *
Preconditions: an initialized list is passed in, the tail has data in it 
Postconditions: the data pointer is returned on success
                NULL otherwise
*/
void * getTailData(List * theList);

/*
void * getNodeData(Node * theNode);

Input: Node *
Output: void *
Preconditions: an initialized Node is passed in 
Postconditions: the data pointer is returned on success
                NULL otherwise
*/
void * getNodeData(Node * theNode);

/*
void * getNthData(List * theList, int n);

Input: List *, int
Output: void *
Preconditions: an initialized list is passed in
Postconditions: pointer to the nth element in the list is returned

*/
void * getNthData(List * theList, int n);

/*
Node * getHead(List * theList);

Input: List *
Output: Node *
Preconditions: an initialized list is passed in, head has data  
Postconditions: return the pointer to the head node
*/
Node * getHead(List * theList);

/*
Node * getTail(List * theList);

Input: List *
Output: Node *
Preconditions: an initialized list is passed in, Tail has data  
Postconditions: return the pointer to the Tail node
*/
Node * getTail(List * theList);

/*
Node * getNextNode(Node * theNode);

Input: Node *
Output: Node *
Preconditions: an initialized node is passed in
Postconditions: the pointer to the next node in the list is returned on success
                NULL is returned otherwise
*/
Node * getNextNode(Node * theNode);

/*
Node * getPrevNode(Node * theNode);

Input: Node *
Output: Node *
Preconditions: an initialized node is passed in
Postconditions: the pointer to the prev node in the list is returned on success
                NULL is returned otherwise
*/
Node * getPrevNode(Node * theNode);

#endif
