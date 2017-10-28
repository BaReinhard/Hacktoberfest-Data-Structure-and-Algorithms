#include<cstdio>
#include<cstdlib>
struct ListNode{
    int data;
    ListNode* next;
    ListNode* prev;
};
void pushBackDEQ(ListNode* &head,int data){
    ListNode* newNode=(ListNode*)malloc(sizeof(ListNode));
    newNode->data=data;
    if(head==NULL){
        head=newNode;
        head->next=head;
        head->prev=head;
    }else{
        newNode->prev=head->prev;
        newNode->next=head;
        head->prev->next=newNode;
        head->prev=newNode;
    }
}
void pushFrontDEQ(ListNode* &head,int data){
    pushBackDEQ(head,data);
    head=head->prev;
}
int popBackDEQ(ListNode* head){
    int data;
    if(head->prev==head){
        data=head->data;
        free(head);
        head=NULL;
    }else{
        ListNode* newTail=head->prev->prev;
        data=head->prev->data;
        newTail->next=head;
        free(head->prev);
        head->prev=newTail;
    }
    return data;
}
int popFrontDEQ(ListNode* head){
    int data;
    head=head->next;
    data=popBackDEQ(head);
    return data;
}
void printDEQ(ListNode* head){
    if(head==NULL){
        return;
    }
    ListNode* current=head;
    do{
        printf("%d ",current->data);
        current=current->next;
    }while(current!=head);
}
int main(){
    ListNode* head=NULL;
    pushBackDEQ(head,1);
    pushFrontDEQ(head,2);
    pushBackDEQ(head,3);
    printDEQ(head);
    printf("\n");
    int data2=popBackDEQ(head);
    int data1=popFrontDEQ(head);
    printf("%d %d",data1,data2);
    return 0;
}


