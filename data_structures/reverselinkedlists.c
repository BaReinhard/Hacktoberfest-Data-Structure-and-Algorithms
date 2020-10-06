#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* Function to reverse the linked list */
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
 void pop(struct node** head)
{

  struct node *currP, *prevP;
  int x;
  prevP = NULL;
  scanf(" %d",&x);
  for (currP = *head;currP != NULL;prevP = currP, currP = currP->next) 
  {
    if (currP->data == x) { 
      if (prevP == NULL) {
        *head = currP->next;
      } else {
        prevP->next = currP->next;
      }
      free(currP);
      return;
    }
  }
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);    
    (*head_ref)    = new_node;
}
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}    
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   int t,n;
   
  	scanf("%d",&t);
// 	printf("Enter no.of commands ranging from pop,push and reverse\n");
  	while(t--)
  		{scanf("%d",&n);
  		push(&head, n);}
     printList(head);    
     reverse(&head);                      
     printf("\n Reversed Linked list \n");
     printList(head);    
     getchar();
}
