//Implementation of circular queue using array
//a Queue follows First in first out principle

#include<stdio.h>
#define SIZE 10 //allows max of 10 elements in queue

int queue[SIZE];
int front=-1,rear=-1;

int is_full(){
  //returns 1 if the queue is full, else returns 0
  int next_pos = rear+1;
  if(next_pos == SIZE) next_pos = 0;

  if(next_pos == front) return 1;
  else return 0;
}

int is_empty(){
  //returns 1 if the queue is empty, else returns 0
  if(front == -1) return 1;
  else return 0;
}

int add_element(int element){
  //adds an element at the rear of queue
  //returns 1 if addition is success, else returns 0

  //OVERFLOW condition
  if(is_full())return 0;

  //adding the first node
  if(rear == -1) front = 0;

  //maintain circular indexing
  int next_pos = rear+1;
  if(next_pos == SIZE) next_pos = 0;

  //adding the element
  queue[next_pos] = element;
  rear = next_pos;
  return 1;
}

int remove_element(int *element){
  //removes an element from the front of queue
  //return 1 on success, else returns 0

  //UNDERFLOW condition
  if(is_empty())return 0;

  //removing element
  *element = queue[front];

  //last element is removed
  if(front == rear) front = rear = -1;
  else{
    //maintain circular indexing
    front++;
    if(front == SIZE)front = 0;
  }

  return 1;
}

int search_element(int element){
  //searches element in queue
  //returns 1 on success else return 0

  if(is_empty())return 0;

  int next = front;

  if(queue[next]==element)return 1;
  while(next!=rear){
    next++;
    if(next == SIZE)next = 0;
    if(queue[next]==element)return 1;
  }

  //element not found
  return 0;
}

void tranverse(){
  //prints the queue from front to rear

  if(!is_empty()){
    int next = front;
    printf("%d -> ",queue[next]);

    while(next!=rear){
      next++;
      if(next == SIZE)next = 0;
      printf("%d -> ",queue[next]);
    }
  }
  printf("NULL\n");
}

void main(){
  //menu driven program
  int choice,element;
  while(choice != 6){
    printf("\nMain Menu\n");
    printf("Current queue ");tranverse();
    printf("\n\t1.Add element\n");
    printf("\t2.Search element\n");
    printf("\t3.Remove element\n");
    printf("\t4.Is empty\n");
    printf("\t5.Is full\n");
    printf("\t6.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

    if(choice == 1){
      printf("Enter an element ");
      scanf("%d",&element);
      if(!add_element(element))
        printf("OVERFLOW\n");
    }
    else if(choice == 2){
      printf("Enter an element ");
      scanf("%d",&element);
      if(search_element(element))
        printf("Element found\n");
      else
        printf("Element not found\n");
    }
    else if(choice == 3){
      if(remove_element(&element))
        printf("Element %d removed\n",element);
      else
        printf("UNDERFLOW\n");
    }
    else if(choice == 4){
      if(is_empty())
        printf("Queue is empty\n");
      else
        printf("Queue is not empty\n");
    }
    else if(choice == 5){
      if(is_full())
        printf("Queue is Full\n");
      else
        printf("Queue is not Full\n");
    }
  }
}
