/**********************************************************
Dalton Polhill          0930905
June 2016
**********************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int destroy(void * data);
void printList(void * theList);

int main (void)
{
    //VARIABLE DECLARATIONS
    FILE * file;
    List * theList;
    int size;
    int data;
    int flag;

    //VARIABLE INIT
    file = fopen("testOutput.txt", "w");
    size = 0;

    flag = 0; 

    //TESTING_CREATELIST()
    fprintf(file, "Testing createList()\n");
    theList = createList(&destroy, printList);
    if (theList == NULL)
    {
        fprintf(file, "->theList was returned NULL, the malloc failed\n");
    }
    else
    {
        fprintf(file, "theList was created properly");
    }

    //TESTING_GETSIZE()
    fprintf(file, "\nTesting getSize()\n");
    size = getSize(theList);
    fprintf(file, "inserting %d\nsize of list = %d\n", data, size);

    //TESTING_INSERTFRONT()
    fprintf(file, "\nTesting insertFront()\n");
    data = 10; 
    theList = insertFront(theList,(void*) &data);
    if (theList != NULL)
    {
        size = getSize(theList);
        fprintf(file, "inserting %d\nsize of list = %d\n", data, size);
        data = *(int*)getHeadData(theList);   
        fprintf(file, "head->data = %d\n", data);
    }
    int dataTwo = 9; 
    theList = insertFront(theList,(void*) &dataTwo);
    if (theList != NULL)
    {
        size = getSize(theList);
        fprintf(file, "inserting %d\nsize of list = %d\n",dataTwo, size);
        dataTwo = *(int*)getHeadData(theList);   
        fprintf(file, "head->data = %d\n", dataTwo);
    }
    int dataThree = 8; 
    theList = insertFront(theList,(void*) &dataThree);
    if (theList != NULL)
    {
        size = getSize(theList);
        fprintf(file, "inserting %d\nsize of list = %d\n", dataThree, size);
        dataThree = *(int*)getHeadData(theList);   
        fprintf(file, "head->data = %d\n", dataThree);
    }    
    int dataFour = 6; 
    theList = insertFront(theList,(void*) &dataFour);
    if (theList != NULL)
    {
        size = getSize(theList);
        fprintf(file, "inserting %d\nsize of list = %d\n", dataFour, size);
        dataFour = *(int*)getHeadData(theList);   
        fprintf(file, "head->data = %d\n", dataFour);
    }

    printList(theList);

    //TESTING_INSERTNTH()
    fprintf(file, "\nTesting insertNth()\n");
    int dataIdk = 59;
    theList = insertNth(theList, (void*) &dataIdk, 3);
    if (theList != NULL)
    { 
        size = getSize(theList);
        fprintf(file, "size of list = %d\n", size);
    }
    printf("inserting 59 to 3rd spot\n");
    printList(theList);

    //TESTING_REMOVEHEAD()
    fprintf(file, "\nTesting removeHead()\n");
    theList = removeHead(theList);
    if (theList != NULL)
    {
        size = getSize(theList);
        fprintf(file, "size of list = %d\n", size);
        data = *(int*)getHeadData(theList);   
        fprintf(file, "head->data = %d\n", data);
        fprintf(file, "tail address: %p\n", (void *)theList->tail);
    }

    //TESTING_REMOVETAIL()
    fprintf(file, "\nTesting removeTail()\n");
    theList = removeTail(theList);
    if (theList != NULL)
    {
        size = getSize(theList);
        fprintf(file, "size of list = %d\n", size);
        data = *(int*)getHeadData(theList);   
        fprintf(file, "head->data = %d\n", data);
        fprintf(file, "tail address: %p  <-this address should be different then the tail->address above, if not remove tail is not working properly\n", (void *)theList->tail);
    }
    printf("removed head and tail\n");
    printList(theList);

    //TESTING_INSERTBACK()
    fprintf(file, "\nTesting InsertBack()\n");
    int dataFive = 27; 
    theList = insertBack(theList,(void*) &dataFive);
    if (theList != NULL)
    {
        size = getSize(theList);
        fprintf(file, "inserting %d\nsize of list = %d\n",dataFive, size);
    }
    int dataSix = 2; 
    theList = insertBack(theList,(void*) &dataSix);
    if (theList != NULL)
    { 
        size = getSize(theList);
        fprintf(file, "inserting %d\nsize of list = %d\n",dataSix, size);
    }    
    int dataSeven = 56; 
    theList = insertBack(theList,(void*) &dataSeven);
    if (theList != NULL)
    { 
        size = getSize(theList);
        fprintf(file, "inserting %d\nsize of list = %d\n",dataSeven, size);
    }
    printList(theList);

    //TESTING_GETHEADDATA()
    fprintf(file, "\nTesting getHeadData()\n");
    void * theData = getHeadData(theList);
    if (theData != NULL)
    {
        int headData = *(int*)theData;   
        fprintf(file, "head->data = %d\n", headData);
    }

    //TESTING_GETTAILDATA()
    fprintf(file, "\nTesting getTailData()\n");
    void * theTailData = getTailData(theList);
    if (theTailData != NULL)
    {
        int tailDataOne = *(int*)theTailData;   
        fprintf(file, "tail->data = %d\n", tailDataOne);
    }

    //TESTING_GETNODEDATA()
    fprintf(file, "\nTesting getNodeData()\n");
    void * randData = getNodeData(NULL);
    if (randData != NULL)
    {
        int tailData = *(int*)randData;   
        fprintf(file, "tail->data = %d\n", tailData);
        fprintf(file, "passing in NULL Node\n");
    }

    //TESTING_GETNTHDATA()
    fprintf(file, "\nTesting getNthData()\n");
    void * temp = getNthData(theList, 2);
    if (temp != NULL)
    {
        int someData = *(int*)temp;   
        fprintf(file, "secondNode->data = %d\n", someData);
    }

    //TESTING_INSERTNTH()
    fprintf(file, "\nTesting InsertNth()\n");
    int dataEight = 13; 
    int n = 3;
    theList = insertNth(theList, (void*) &dataEight, n);
    size = getSize(theList);
    fprintf(file, "inserting %d at the %dth spot\nsize of list = %d\n",dataEight, n, size);

    printList(theList);

    //TESTING_REMOVENTH()
    fprintf(file, "\nTesting removeNth()\n");
    int m = 6;
    theList = removeNth(theList, m);
    size = getSize(theList);
    fprintf(file, "removing %dth spot\nsize of list = %d\n", m, size);
    
    printList(theList);

    //TESTING_GETNEXTNODE()
    fprintf(file, "\nTesting getNextNode()\n");
    Node * nextNode = NULL;
    //nextNode = getNextNode(theList->head);
    nextNode = getNextNode(NULL);
    if (nextNode != NULL)
    {
        fprintf(file, "the second node in the list is: %d\n", *(int *)nextNode->data);
        fprintf(file, "passing in the tail\n");
    }
    //nextNode = getNextNode(theList->tail);
    if (nextNode != NULL)
    {
        nextNode = getNextNode(NULL);
        fprintf(file, "the node after the tail is is: %p\n", (void *)nextNode);
    }

    //TESTING_GETPREVNODE()
    fprintf(file, "\nTesting getPrevNode()\n");
    Node * prevNode = NULL;
    //prevNode = getPrevNode(theList->tail);
    prevNode = getPrevNode(NULL);
    if (nextNode != NULL)
    {
        fprintf(file, "the second last node is: %d\n", *(int *)prevNode->data);
        fprintf(file, "passing in the head\n");
    }
    //prevNode = getPrevNode(theList->head);
    prevNode = getPrevNode(NULL);
    if (nextNode != NULL)
    {
        fprintf(file, "the node before the head is: %p\n", (void *)prevNode); 
    }

    //TESTING_GETHEAD()
    fprintf(file, "\nTesting getHead()\n");
    Node * theNode = NULL;
    theNode = getHead(theList);
    if (theNode !=NULL)
    {
        fprintf(file, "theNode->data = %d\n", *(int *)theNode->data);
    }

    //TESTING_GETTAIL()
    fprintf(file, "\nTesting getTail()\n");
    theNode = NULL;
    theNode = getTail(theList);
    if (theNode !=NULL)
    {
        fprintf(file, "theNode->data = %d\n", *(int *)theNode->data);
    }

    //TESTING_DESTROYLIST()
    fprintf(file, "\nTesting destroyList()\n");
    flag = destroyList(theList);
    fprintf(file, "the destroyList flag == %d (0 is success)\n", flag);

    fclose(file);
    return 0;
}

//returns 0 on success, 1 on failure
int destroy(void * data)
{
    //there is nothing to free because the data was never malloced for therefore, simply return 0 (success code)
    return 0; //success
}

void printList(void * theList)
{
    if (theList == NULL)
    {
        return;
    }
    List * list;
    list = (List *)theList;

    Node * temp;
    temp = list->head;
 
    //loop through until reach the tail
    printf("\nTHE_LIST\n");
    printf("list->size = %d\n", list->size);
    if (list->size == 0)
    {
        printf("No list (list->size = 0)\n");
    }
    else if (list->size == 1)
    {
        printf("Head->data: %d\n", *(int *)temp->data);
        return;
    }
    else 
    {
        printf("Head->data: %d\n", *(int *)temp->data);
        temp = temp->next;
        while (temp->next != NULL)
        {
            printf("Node->data: %d\n", *(int *)temp->data);
            temp = temp->next;
        }
        printf("Tail->data: %d\n", *(int *)temp->data); //print the tail
        printf("\n");
        return;
    }
}

