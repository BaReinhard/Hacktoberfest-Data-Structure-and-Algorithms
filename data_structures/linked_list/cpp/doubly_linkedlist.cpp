//program to implement doubly linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//structure for doubly_list
struct doubly_list
{
    int data;
    struct doubly_list *next;
    struct doubly_list *prev;
    //methods
    void (*insertbeg)(struct doubly_list *, int);
    void (*insertend)(struct doubly_list *, int);
    void (*insertmid)(struct doubly_list *, int);
    void (*insertpos)(struct doubly_list *, int, int);
    void (*display)(struct doubly_list *);
    int  (*deletebeg)(struct doubly_list *);
    int  (*deletemid)(struct doubly_list *);
    int  (*deleteend)(struct doubly_list *);
    int  (*deletepos)(struct doubly_list *, int);
    int  (*listlen)(struct doubly_list *);
    bool (*isempty)(struct doubly_list *);
    int (*search)(struct doubly_list *, int );
    void (*modify)(struct doubly_list *, int, int);
}*top = NULL, *end = NULL;

//function to insert in the beginning
void insertbeg(struct doubly_list *, int num);
//function to insert at the end
void insertend(struct doubly_list *, int num);
//function to insert at the middle
void insertmid(struct doubly_list *, int num);
//function to insert at any position
void insertpos(struct doubly_list *, int num, int pos);
//function to display elements in list
void display(struct doubly_list *);
//function to delete first element
int deletebeg(struct doubly_list *);
//function to delete middle element
int deletemid(struct doubly_list *);
//function to delete last element
int deleteend(struct doubly_list *);
//function to delete at any position
int deletepos(struct doubly_list *, int pos);
//function to print length of list
int listlen(struct doubly_list *);
//checks if list is empty
bool isempty(struct doubly_list *);
//to search for an element in the list
int search(struct doubly_list *, int val);
//to modify an element in the list
void modify(struct doubly_list *, int num, int pos);

int main()
{
    struct doubly_list dll;
    //bind functions
    dll.insertbeg = insertbeg;
    dll.insertend = insertend;
    dll.insertmid = insertmid;
    dll.insertpos = insertpos;
    dll.deletebeg = deletebeg;
    dll.deletemid = deletemid;
    dll.deleteend = deleteend;
    dll.deletepos = deletepos;
    dll.search = search;
    dll.isempty = isempty;
    dll.modify = modify;
    dll.listlen = listlen;
    dll.display = display ;
    //variables to store position and various other inputs
    int choice, Inum, Dnum, pos, find, change;
    printf("-----------------------------\n");
    printf("1.Insert at the Beginning\n");
    printf("2.Insert at the End\n");
    printf("3.Insert at the Middle\n");
    printf("4.Insert at a Position\n");
    printf("5.Delete at the Beginning\n");
    printf("6.Delete at the End\n");
    printf("7.Delete at the Middle\n");
    printf("8.Delete at a Position\n");
    printf("9.Display\n");
    printf("10.List Length\n");
    printf("11.Check if List is Empty\n");
    printf("12.Search for a Element\n");
    printf("13.Modify a Element\n");
    printf("14.Exit\n");
    printf("------------------------------\n");
    while(1)
    {
         printf("Enter choice:");
         scanf("%d", &choice);
         switch(choice)
         {
         case 1:
             printf("Enter number:");
             scanf("%d", &Inum);
             insertbeg(&dll, Inum);
             break;
         case 2:
             printf("Enter number:");
             scanf("%d", &Inum);
             insertend(&dll, Inum);
             break;
         case 3:
             printf("Enter number:");
             scanf("%d", &Inum);
             insertmid(&dll, Inum);
             break;
         case 4:
             printf("Enter number:");
             scanf("%d", &Inum);
             printf("Enter position:");
             scanf("%d", &pos);
             insertpos(&dll, Inum, pos);
             break;
         case 5:
             Dnum = deletebeg(&dll);
             //list is not empty
             if(Dnum != -1)
                 printf("The deleted number is %d:\n", Dnum);
             break;
         case 6:
             Dnum = deleteend(&dll);
             //list is not empty
             if(Dnum != -1)
                 printf("The deleted number is %d:\n", Dnum);
            break;
         case 7:
             Dnum = deletemid(&dll);
             //list is not empty
             if(Dnum != -1)
                 printf("The deleted number is %d:\n", Dnum);
            break;
         case 8:
             printf("Enter position:");
             scanf("%d", &pos);
             Dnum = deletepos(&dll, pos);
             //list is not empty
             if(Dnum != -1)
                 printf("The deleted number is %d:\n", Dnum);
            break;
         case 9:
            display(&dll);
            break;
         case 10:
            printf("The length of the list is %d:\n", listlen(&dll));
            break;
         case 11:
            if(isempty(&dll))
                printf("the list is empty\n");
            else
                printf("the list is not empty\n");
            break;
         case 12:
            printf("Enter the element you want to search:");
            scanf("%d", &find);
            pos = search(&dll, find);
            //invalid position
            if (pos != -1)
                printf("The Element is Present at %d:\n", pos);
            else
                printf("The Element is not Present\n");
            break;
         case 13:
             printf("Enter position:");
             scanf("%d", &pos);
             printf("Enter number to change to:");
             scanf("%d", &change);
             modify(&dll, change, pos);
             break;
         case 14:
            printf("program terminating\n");
            exit(0);
            break;
         default:
            printf("Invalid choice\n");
            break;
         }
    }
    return 0;
}
void insertbeg(struct doubly_list *dll, int num)
{
    struct doubly_list *temp = (struct doubly_list*)malloc(sizeof(struct doubly_list));
    temp->data = num;
    //if list is empty
    if (top == NULL)
    {
        top = end = temp;
        temp->prev = NULL;
        temp->next = NULL;
        return;
    }
    temp->prev = NULL;
    temp->next = top;
    top->prev  = temp;
    top = temp;
}
void insertend(struct doubly_list *dll, int num)
{
    struct doubly_list *temp = (struct doubly_list*)malloc(sizeof(struct doubly_list));
    temp->data = num;
    //if list is empty
    if (top == NULL)
    {
        top = end = temp;
        temp->prev = NULL;
        temp->next = NULL;
        return;
    }
    temp->prev = end;
    end->next = temp;
    temp->next = NULL;
    end = temp;
}
void insertmid(struct doubly_list *dll, int num)
{
    struct doubly_list *temp = (struct doubly_list*)malloc(sizeof(struct doubly_list));
    struct doubly_list *current = top;
    temp->data = num;
    //list is empty
    if (top == NULL)
    {
        top = end = temp;
        temp->prev = NULL;
        temp->next = NULL;
        return;
    }
    //only one element
    if(listlen(dll) == 1)
    {
        insertbeg(dll,num);
        return;
    }
    int pos = (listlen(dll)) / 2 - 1;
    //go till half way -1
    while(pos--)
    {
        current = current->next;
    }
    temp->next = current->next;
    current->next->prev = temp;
    current->next = temp;
    temp->prev = current;

}
void insertpos(struct doubly_list *dll, int num, int pos)
{
    struct doubly_list *temp = (struct doubly_list*)malloc(sizeof(struct doubly_list));
    struct doubly_list *current = top;
    temp->data = num;
    //list is empty
    if (top == NULL)
    {
        top = end = temp;
        temp->prev = NULL;
        temp->next = NULL;
        return;
    }
    //invalid position
    if (pos < 0 || pos > listlen(dll))
    {
        printf("Invalid position\n");
        return;
    }
    //after end element
    if (pos == listlen(dll))
    {
        insertend(dll,num);
        return;
    }
    //first place
    if(pos == 0)
    {
        insertbeg(dll,num);
        return;
    }
    //last place
    if(pos == listlen(dll) - 1)
    {
        insertend(dll,num);
        return;
    }
    pos--;
    //go till pos -1
    while(pos--)
    {
        current=current->next;
    }
    temp->next = current->next;
    current->next->prev = temp;
    current->next = temp;
    temp->prev = current;
}
int deletebeg(struct doubly_list *dll)
{
    struct doubly_list *current = top;
    //list is empty
    if (top == NULL)
    {
        printf("The list is empty\n");
        return -1;
    }
    int data = current->data;
    //first element
    if(listlen(dll) == 1)
    {
        free(current);
        top = end = NULL;
        return data;
    }
    top = top->next;
    top->prev = NULL;
    free(current);
    return data;
}
int deletemid(struct doubly_list *dll)
{
    struct doubly_list *current = top;
    int data;
    //list is empty
    if (top == NULL)
    {
        printf("The list is empty\n");
        return -1;
    }
    //one element in the list
    if (listlen(dll) == 1)
    {
        data = top->data;
        free(current);
        top = end = NULL;
        return data;
    }
    //only two elements in the list
    if (listlen(dll) == 2)
    {
        data = top->data;
        top = end;
        free(current);
        end->prev = top->prev = NULL;
        return data;
    }
    int pos = listlen(dll) / 2 ;
    //go till position
    while(pos--)
    {
        current = current->next;
    }
    if (listlen(dll) % 2 == 0)
        current = current->prev;
    data = current->data;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return data;
}
int deletepos(struct doubly_list *dll, int pos)
{
    struct doubly_list *current = top;
    int data;
    //list is empty
    if (top == NULL)
    {
        printf("The list is empty\n");
        return -1;
    }
    //invalid position
    if (pos < 0 || pos >= listlen(dll))
    {
        printf("Invalid position\n");
        return -1;
    }
    //first element to be deleted
    if (pos == 0)
    {
        data = deletebeg(dll);
        return data;
    }
    //last element to be deleted
    if (pos == listlen(dll) - 1)
    {
        data = deleteend(dll);
        return data;
    }
    while(pos--)
    {
        current = current->next;
    }
    data = current->data;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return data;

}
int deleteend(struct doubly_list *dll)
{
    struct doubly_list *current = end;
    if (top == NULL)
    {
        printf("The list is empty\n");
        return -1;
    }
    int data = current->data;
    //only one element in the list
    if (listlen(dll) == 1)
    {
        free(current);
        top = end = NULL;
        return data;
    }
    end = end->prev;
    end->next = NULL;
    free(current);
    return data;
}
void display(struct doubly_list *dll)
{
    struct doubly_list *current = top;
    if (current == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    //till the end
    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}
int listlen(struct doubly_list *dll)
{
    struct doubly_list *current = top;
    int count = 0;
    //till the end
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
bool isempty(struct doubly_list *dll)
{
    if (top == NULL)
        return true;
    else
        return false;
}
int search(struct doubly_list *dll, int val)
{
    struct doubly_list *current = top;
    int pos = 0;
    //go through all elements till you find element
    while(current != NULL)
    {
        if (current->data == val)
            return pos;
        current = current->next;
        pos++;
    }
    return -1;
}
void modify(struct doubly_list *dll, int num, int pos)
{
    struct doubly_list *current = top;
    //invalid position
    if (pos < 0 || pos >= listlen(dll))
    {
        printf("Invalid position\n");
        return;
    }
    //list is empty
    if (top == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    //goto position
    while(pos--)
    {
        current = current->next;
    }
    current->data = num;
}
