/*******************************************************
Dalton Polhill          0930905
Linked List ADT 
June 2016
********************************************************/
#include "list.h"

#include <stdlib.h>

List * createList(int (* destroy)(void *), void (*print)(void *))
{
    //VAR Declaration
    List * theList;
    theList = malloc(sizeof(List));
    if (theList == NULL)
    {
        return NULL; //malloc failed
    }
    //VAR init
    theList->head = NULL;
    theList->tail = NULL;
    theList->size = 0;
    theList->destroy = (*destroy); //assign a point to the destroy &&print function to the list struct
    theList->print = (* print);
    return theList;
}

int destroyList(List * theList)
{
    if (theList == NULL)
    {
        return 0; //nothing to free
    }
    //var declaration
    Node * temp;
    int flag;
    //var init
    temp = theList->head;
    flag = 0; // 0 is success 1 is failure

    while(temp != NULL && temp->next != NULL) //iterate the entire list including the tail
    {
        theList->destroy(temp->data);
        temp = temp->next;
        free(temp->prev);        
        if(temp->prev != NULL)
        {
            flag = 1;
        }
    }
    if (temp != NULL)
    {
        theList->destroy(temp->data);
        free(temp);
    }
    free(theList);
    flag = 0;
    return flag;
}

int getSize(List * theList)
{
    if (theList == NULL)
    {
        return -1;
    }
    return theList->size;
}


List * insertFront(List * theList, void * data)
{
    if (theList == NULL || data == NULL) //null variable passed in or the list is full
    {
        return NULL;
    }
    else if (theList->head == NULL) //there is no head to the list yet
    {
        theList->head = malloc(sizeof(Node));
        theList->head = theList->head;
        theList->tail = theList->head;
        theList->head->data = data;
        theList->head->next = NULL;
        theList->head->prev = NULL;
        theList->size = theList->size + 1;
        return theList;
    }
    else
    {
        Node * newNode;
        newNode = malloc(sizeof(Node));
        if (newNode != NULL) //the malloc was successful
        {
            newNode->data = data; //add the newNodes data, next and prev pointers
            newNode->prev = NULL;
            newNode->next = theList->head;
            theList->head->prev = newNode; //swap the head of the list to the newNode
            theList->head = newNode;
            theList->size = theList->size + 1;
            return theList;
        }
        else
        {
            return theList; //malloc was unsuccessful list is unchanged
        }

    }
    return theList;
}

List * insertBack(List * theList, void * data)
{
    if (theList == NULL || data == NULL) //null variable passed in or the list is full
    {
        return NULL;
    }
    else if (theList->tail == NULL) //there is no tail  to the list yet
    {
        //if there is no tail this tail becomes the head..
        theList->tail = malloc(sizeof(Node));//malloc for a tail and insert that tail into the list 
        theList->tail->data = data;
        theList->tail->next = NULL;
        theList->tail->prev = NULL;
        theList->size =theList->size + 1;
        theList->head = theList->tail; //tail and head are the same
        return theList;
    }
    else
    {
        Node * newNode;
        newNode = malloc(sizeof(Node));
        if (newNode != NULL) //the malloc was successful
        {
            newNode->data = data; //add the newNodes data, next and prev pointers
            newNode->prev = theList->tail;
            newNode->next = NULL;
            theList->tail->next = newNode; //swap the head of the list to the newNode
            theList->tail = newNode;
            theList->size =theList->size + 1;
            return theList;
        }
        else
        {
            return theList; //malloc was unsuccessful list is unchanged
        }
    }
    return theList;
}

List * insertNth(List * theList, void * data, int n)
{
    if (theList == NULL || data == NULL) //null variables were passed in or the list is full
    {
        return NULL;
    }
    if (n == 0) 
    {
        insertFront(theList, (void *)data);
        return theList;
    }
    if (n <= theList->size) //n is within the size off the list
    {
        Node * newNode;
        newNode = malloc(sizeof(Node));
        if (newNode != NULL) //malloc was successful
        {
            int i;
            Node * temp;

            i = 0;
            temp = theList->head;
      
            for (i = 0; i < n-1; i++) //cycle through the list to the nth position
            {
                temp = temp->next;
            }
            newNode->data = data;
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            theList->size++;
            return theList;
        }
    }
    return theList;
}

List * removeHead(List * theList)
{
    if(theList == NULL || theList->head == NULL) //passed in null variables
    {
        return NULL;
    }
    Node * temp;
    temp = theList->head;

    theList->destroy(theList->head->data); //call the destroy function on the data inside the head
    theList->head = theList->head->next; //move the head pointer to the next spot in list
    free(temp);
    theList->head->prev = NULL; //remove the 'prev' pointer, pointing to the original head
    theList->size = theList->size - 1; //reduce the size of the list

    return theList;
}

List * removeTail(List * theList)
{
    if(theList == NULL || theList->tail == NULL) //passed in null variables
    {
        return NULL;
    }
    Node * temp;
    temp = theList->tail;

    theList->destroy(theList->tail->data); //call the destroy function on the data inside the tail
    theList->tail = theList->tail->prev; //move the head pointer to the next spot in list
    free(temp);
    theList->tail->next = NULL; //remove the 'prev' pointer, pointing to the original tail
    theList->size = theList->size - 1; //reduce the size of the list

    return theList;
}

List * removeNth(List * theList, int n)
{
    if(theList == NULL) //passed in null variables
    {
        return NULL;
    }
    else if (n < theList->size) //n is within the list
    {
        int i;
        Node * temp;
        Node * prevTemp;
        Node * nextTemp;

        temp = theList->head;

        for (i = 0; i < n-1; i++)
        {
            temp = temp->next;
        }
        prevTemp = temp->prev; //point to previous node
        nextTemp = temp->next; //point to next node
        
        nextTemp->prev = prevTemp; //make next node point to previous 
        prevTemp->next = nextTemp; //make previous node point to next node

        theList->destroy(temp->data); //call the destroy function on the data inside temp
        free(temp); 
        theList->size = theList->size - 1;
        return theList;
    }
    else if (n == theList->size)
    {
        theList = removeTail(theList);
        return theList;
    }
    return theList;
}

void * getHeadData(List * theList) //returns vois * data
{
    if (theList == NULL || theList->head == NULL) //null list was passed in
    {
        return NULL;
    }
    return theList->head->data;
}

void * getTailData(List * theList) //returns vois * data
{
    if (theList == NULL || theList->head == NULL) //null list was passed in
    {
        return NULL;
    }
    return theList->tail->data;
}

void * getNodeData(Node * n) //return void * data
{
    if (n == NULL) //null node was passed in
    {
        return NULL;
    }
    return n->data;
}

void * getNthData(List * theList, int n)
{
    if (theList == NULL || n < 0) //passed in invalid or null data
    {
        return NULL;
    }
    else if (n < theList->size) //the nth position is within the list
    {
        int i;
        Node * temp;
    
        i = 0;
        temp = theList->head;

        for (i = 1; i < n; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }   
    else if (n == theList->size)
    {
        theList = getTailData(theList);
        return theList;
    }
    return NULL; //the nth position was not within the length of the list
}

Node * getNextNode(Node * n)
{
    if(n == NULL)
    {
        return NULL;
    }
    return n->next;
}

Node * getPrevNode(Node * n)
{
    if(n == NULL)
    {
        return NULL;
    }
    return n->prev;
}

Node * getHead(List * theList)
{
    if (theList == NULL)
    {
        return NULL;
    }

    return theList->head;
}

Node * getTail(List * theList)
{
    if (theList == NULL)
    {
        return NULL;
    }

    return theList->tail;
}

