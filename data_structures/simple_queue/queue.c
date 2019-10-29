#include <stdio.h>
#include <stdlib.h>

//struct with the node data in queue  
typedef struct node{
    int data;
    struct node *next;
} NODE;
 
 //create a node
NODE *create_node(int x){
    NODE *new;
    new = (NODE*) malloc(sizeof(NODE));
    new->data = x;
    new->next = NULL;
    return new;
}
 
 //insert a node
void insert(NODE **queue, int x){
    NODE *tmp = *queue;
    
    if(tmp == NULL){
        *queue = create_node(x);
        return;
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = create_node(x);
}
 
 //remove a node
NODE *remove_element(NODE *queue){
    NODE *tmp = NULL;
    tmp = queue->next;
    free(queue);
    return tmp;
}
int flag;
//find a node
NODE *find_value(NODE *queue, int x){
    flag = 0;
    while(queue->data != x){
        queue = queue->next;
    }
    if(queue->next == NULL){
        flag = 1;
        return NULL;
    }
    return queue;        
}
 
 //return the first value in the queue
int return_value(NODE *queue){
    return queue->data;
}

NODE *clear_queue(NODE *queue){
    if(queue){
        queue = clear_queue(queue->next);
    }
    free(queue);
    return NULL;
} 

int main(){
    NODE *queue = NULL, *tmp = NULL;
    int sizeofqueue,menu;
    int element;
    int count;
    
    printf("Empty Queue.");
    while(1){
        printf("\n\n1- Insert;\n");
        printf("2- Remove;\n");
        printf("3- Show Queue;\n");
        printf("4- Clear Queue;\n");
        printf("5- Exit;\n");
        scanf("%d",&menu);

        if(menu == 1){
            printf("Numer of elements to insert:\n");
            scanf("%d",&sizeofqueue);
            for(count = 0; count < sizeofqueue; count++){
                printf("Type the element to insert:\n");
                scanf("%d",&element);
                insert(&queue,element);                
            }
        }
        if(menu == 2){
            printf("\n\nRemoving the first element\n");
            queue = remove_element(queue);
            printf("Sucess!\n\n");
        }
        if(menu == 3){
            if(queue == NULL){
                printf("\n\nQueue is empty.\n\n");
            }
            else{
                printf("\n\n");
                for(tmp = queue; tmp != NULL; tmp = tmp->next){
                    printf("%d ",tmp->data);
                }
                printf("\n\n");
            }
        }
        if(menu == 4){
            while(queue->next != NULL){
                queue = remove_element(queue);
            }
            queue = queue->next;
            free(queue);
            printf("\n\nSucess! Empty queue\n\n");
        }
        if(menu == 5){
            return 0;
        }
        if(menu > 5 || menu < 1){
            printf("\n\nSelect the option again!\n\n");
        }
    }
}
