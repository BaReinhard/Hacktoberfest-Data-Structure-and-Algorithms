#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct doubleLinkedList{
    struct doubleLinkedList* next;
    struct doubleLinkedList* previous;
    int value;
} DoubleLinkedList;

DoubleLinkedList* NewDoubleLinkedList();
DoubleLinkedList* GetElementAt(DoubleLinkedList* list, int index);
int LengthOfTheList (DoubleLinkedList* list);
void DeleteElementAt(DoubleLinkedList* list, int index);
void DeleteElement(DoubleLinkedList* list, DoubleLinkedList* element);
void AddANewValueToLinkedList(DoubleLinkedList* list, int newValue);
void PrintAllValues (DoubleLinkedList* list);


int main () {
    int deletedIndex = 0;
    int insertedValue = 6;

    printf("Here is an example of how to use the functions:\n");

    DoubleLinkedList* myIntList;
    myIntList = NewDoubleLinkedList();

    AddANewValueToLinkedList(myIntList, insertedValue);
    printf("Inserted %d at the end of the list!\n", insertedValue);
    insertedValue = 7;
    AddANewValueToLinkedList(myIntList, insertedValue);
    printf("Inserted %d at the end of the list!\n", insertedValue);
    insertedValue = 8;
    AddANewValueToLinkedList(myIntList, insertedValue);
    printf("Inserted %d at the end of the list!\n", insertedValue);
    insertedValue = 9;
    AddANewValueToLinkedList(myIntList, insertedValue);
    printf("Inserted %d at the end of the list!\n", insertedValue);
    insertedValue = 10;
    AddANewValueToLinkedList(myIntList, insertedValue);
    printf("Inserted %d at the end of the list!\n", insertedValue);
    printf("-----------------------------------------------------\n");

    printf("The first arrays' length is: %d:\n", LengthOfTheList(myIntList));
    PrintAllValues(myIntList);
    printf("-----------------------------------------------------\n");

    DeleteElementAt(myIntList, 0);
    printf("Deleted element at: %d\n", deletedIndex);
    DeleteElementAt(myIntList, 0);
    printf("Deleted element at: %d\n", deletedIndex);
    DeleteElement(myIntList, GetElementAt(myIntList, 0));
    printf("Deleted element at: %d\n", deletedIndex);
    DeleteElement(myIntList, GetElementAt(myIntList, 0));
    printf("Deleted element at: %d\n", deletedIndex);
    DeleteElement(myIntList, GetElementAt(myIntList, 0));
    printf("Deleted element at: %d\n", deletedIndex);
    printf("-----------------------------------------------------\n");
    PrintAllValues(myIntList);
    return 0;
}

DoubleLinkedList* NewDoubleLinkedList(){
    //Create a new head pointer
    DoubleLinkedList* newList = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));;
    newList->next = NULL;
    newList->previous = NULL;
    newList->value = NULL;
    return newList;
}

void AddANewValueToLinkedList(DoubleLinkedList* list, int newValue){
    DoubleLinkedList* lastNode = list;
    //Looking for the last node
    while (lastNode->next != NULL){
        lastNode = lastNode->next;
    }

    //Creating a new node and adding it to the end
    DoubleLinkedList* newNode = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
    newNode->previous = lastNode;
    newNode->value = newValue;
    newNode->next = NULL;
    lastNode->next = (DoubleLinkedList*) newNode;
}

void PrintAllValues (DoubleLinkedList* list){
    int i = 0;
    DoubleLinkedList* actualNode = list->next;
    if(actualNode == NULL){
        printf("The list is empty.\n");
    }
    //Printing all values
    while(actualNode != NULL){
        printf("Element at %d has the value %d\n", i, actualNode->value);
        actualNode = actualNode->next;
        i++;
    }
}

DoubleLinkedList* GetElementAt (DoubleLinkedList* list, int index){
    int i = -1;
    DoubleLinkedList* actualNode = list;

    //Iterating till end of the list or till the wanted index
    while(actualNode != NULL && i < index){
        i++;
        actualNode = actualNode->next;
    }

    if (actualNode == NULL && i < index)
        return NULL;
    else
        return actualNode;
}

int LengthOfTheList(DoubleLinkedList* list){
    int i = 0;
    DoubleLinkedList* actualNode = list;

    while(actualNode != NULL){
        i++;
        actualNode = actualNode->next;
    }

    return i - 1;
}

void DeleteElementAt (DoubleLinkedList* list, int index){
    int i = -1;
    DoubleLinkedList* actualNode = list;
    DoubleLinkedList* previousNode = NULL;
    if(index < 0){
        return NULL;
    }

    //Iterating till end of the list or till the wanted index
    while(actualNode != NULL && i < index){
        i++;
        previousNode = actualNode;
        actualNode = actualNode->next;
    }

    //Actually deleting the node
    if (i == index){
        previousNode->next = actualNode->next;
        free(&actualNode);
    }
}

void DeleteElement (DoubleLinkedList* list, DoubleLinkedList* element){
    int i = -1;
    DoubleLinkedList* actualNode = list;
    DoubleLinkedList* previousNode = NULL;
    if(element == NULL){
        return NULL;
    }

    //Iterating till end of the list or till the wanted index
    while(actualNode != NULL && actualNode != element){
        i++;
        previousNode = actualNode;
        actualNode = actualNode->next;
    }

    //Actually deleting the node
    if (actualNode == element){
        previousNode->next = actualNode->next;
        free(&actualNode);
    }
}