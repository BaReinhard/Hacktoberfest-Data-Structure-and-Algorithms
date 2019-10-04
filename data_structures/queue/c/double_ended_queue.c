#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
struct node 
{
		int data;
		node *link;
};

typedef struct list 
{
		node *head;
		node *tail;
		int number_of_nodes;
}s_list;

typedef struct queue
{
	s_list *ptr_list;
}queue;

void list_initialize(s_list* list); // Initializes the head, tail and no of nodes of the list.
void list_insert_rear(s_list* list, int data); // Inserts element at the rear of the list.
void list_insert_front(s_list* list, int data); // Inserts element at the front of the list.
void list_delete_front(s_list *list); // Deletes element at the front of the list. No operation if list is empty.
void list_delete_rear(s_list* list); // Deletes element at the rear of the list. No operation if list is empty.
const int node_get_data(node* node_ptr);
void list_destroy(s_list* list);
void display(s_list* list); // Prints the list. Prints "Empty Queue" if list is empty.

void queue_initialize(queue* ptr_queue);
void queue_enqueue_rear(queue* ptr_queue, int data);
void queue_dequeue_front(queue* ptr_queue);
void queue_enqueue_front(queue* ptr_queue, int data);
void queue_dequeue_rear(queue* ptr_queue);
int queue_is_empty(queue* ptr_queue); // Returns a boolean value.
const int queue_peek(queue* ptr_queue); // Returns the element at the front.
void queue_destroy(queue* ptr_queue);
void print_queue(queue* ptr_queue);

int main()
{
	queue queue;
	queue_initialize(&queue);
	int choice,element;
	int loop = 1;
	while(loop) 
	{
		scanf("%d", &choice);
		switch(choice) 
		{
			case 0:
				scanf("%d", &element);
				queue_enqueue_front(&queue, element);
				break;

			case 1:
				scanf("%d", &element);
				queue_enqueue_rear(&queue, element);
				break;

			case 2:
				queue_dequeue_front(&queue);
				break;

			case 3:
				queue_dequeue_rear(&queue);
				break;

			case 4:
				if(queue_is_empty(&queue))
				{
					printf("Empty Queue\n");
				}
				else
				{
					printf("%d\n", queue_peek(&queue));
				}
				break;

			case 5:
				print_queue(&queue);
				break;

			default:
				queue_destroy(&queue);
				loop = 0;
		}
	}
	return 0;
}

static node* create_node(int data, node *link) 
{
	link=(node *)malloc(sizeof(node));
	link->data=data;
	link->link=NULL;
	return link;
}

void list_initialize(s_list *ptr_list) 
{
    ptr_list->head=NULL;
    ptr_list->tail=NULL;
    ptr_list->number_of_nodes=0;
}

void list_insert_rear(s_list *ptr_list, int data)
{
	node * rear_node;
	rear_node=create_node(data,rear_node);
	if(ptr_list->tail==NULL)
	{
	    ptr_list->tail=rear_node;
	    ptr_list->head=rear_node;
	}
	else
	{
	    ptr_list->tail->link=rear_node;
	    ptr_list->tail=rear_node;
	}
}

const int node_get_data(node *node_ptr) 
{
	return node_ptr->data;
	
}

void list_delete_front(s_list* ptr_list) 
{
    if(ptr_list->head==NULL)
    {
        return;
    }
    else if(ptr_list->head->link==NULL)
    {
        free(ptr_list->head);
        ptr_list->head=ptr_list->tail=NULL;
    }
    else
    {
        node * temp;
        temp=ptr_list->head;
        ptr_list->head=ptr_list->head->link;
        free(temp);
    }
}


void list_delete_rear(s_list* ptr_list)
{
	if(ptr_list->tail==NULL)
	{
	    return;
	}
	else if(ptr_list->tail==ptr_list->head)
	{
	    free(ptr_list->tail);
	    ptr_list->head=ptr_list->tail=NULL;
	}
	else
	{
	    node * temp;
	    temp=ptr_list->head;
	    node * prev;
	    prev=NULL;
	    while(temp->link!=NULL)
	    {
	        prev=temp;
	        temp=temp->link;
	    }
	    free(temp);
	    prev->link=NULL;
	    ptr_list->tail=prev;
	}
}

void list_insert_front(s_list* ptr_list, int data)
{
	node * front_node;
	front_node=create_node(data,front_node);
	if(ptr_list->head==NULL)
	{
	    ptr_list->head=ptr_list->tail=front_node;
	}
	else
  {
	    front_node->link=ptr_list->head;
	    ptr_list->head=front_node;
	}
}

void display(s_list* ptr_list)
{
	node * temp=ptr_list->head;
	if(temp==NULL)
	{
	    printf("Empty Queue");
	}
	while(temp!=NULL)
	{
	    printf("%d ",temp->data);
	    temp=temp->link;
	}
	printf("\n");
}

void list_destroy(s_list* ptr_list) 
{
	
	node * temp=ptr_list->head;
	node * temp2=NULL;
	while(temp)
	{
	    temp2=temp->link;
	    free(temp);
	    temp=temp2;
	}
}

int queue_is_empty(queue* ptr)
{
	if(ptr->ptr_list->tail==NULL)
	{
	    return 1;
	}
	return 0;
}

const int queue_peek(queue* ptr)
{
	 node * temp=ptr->ptr_list->head;
	 return node_get_data(temp);
}

void queue_initialize(queue* queue_list)
{
	list_initialize(queue_list->ptr_list);
}

void queue_enqueue_rear(queue* ptr,int data)
{
	list_insert_rear(ptr->ptr_list,data);
}

void queue_dequeue_front(queue* ptr)
{
	list_delete_front(ptr->ptr_list);
}

void queue_destroy(queue* ptr)
{
	list_destroy(ptr->ptr_list);
}

void queue_enqueue_front(queue* ptr, int data)
{
	list_insert_front(ptr->ptr_list,data);
}

void queue_dequeue_rear(queue* ptr)
{
	list_delete_rear(ptr->ptr_list);
}

void print_queue(queue* ptr)
{
	display(ptr->ptr_list);
}
