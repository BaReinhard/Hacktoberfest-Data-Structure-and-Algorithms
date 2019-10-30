                          #include<stdio.h>
                          struct node
                          {
                              int data;
                              struct node *next;
                          };
                          struct node *head = NULL;
                          void insertAtBeg()
                          {
                              struct node *n;
                              n=(struct node*)malloc(sizeof(struct node));
                              printf("\nEnter Your Data:\t");
                              scanf("%d",&n->data);
                              n->next=NULL;
                              n->next=head;
                              head=n;
                          }
                          void insertAtEnd()
                          {
                              struct node *n,*temp;
                              n=(struct node*)malloc(sizeof(struct node));
                              printf("\nEnter Your Data:\t");
                              scanf("%d",&n->data);
                              n->next=NULL;
                              if(head==NULL)
                                  head=n;
                              else{
                                  temp=head;
                                  while(temp->next!=NULL){
                                      temp=temp->next;
                                  }
                                  temp->next=n;
                              }
                          }
                          void deleteAtBeg()
                          {
                              struct node *temp;
                              if(head==NULL)
                                  printf("\nList Is Empty\n");
                              else{
                                  temp=head;
                                  head=head->next;
                                  free(temp);
                              }
                          }
                          void deleteAtEnd()
                          {
                              struct node *temp,*t;
                              if(head==NULL)
                                  printf("\nList Is Empty\n");
                              else{
                                  temp=head;
                                  while(temp->next!=NULL){
                                      t=temp;
                                      temp=temp->next;
                                  }
                                  t->next=NULL;
                                  free(temp);
                              }
                          }
                          void display()
                          {
                              struct node *temp = head;
                              if(head==NULL)
                                  printf("\nList Is Empty\n");
                              else{
                                  while(temp!=NULL){
                                      printf("%d\t",temp->data);
                                      temp=temp->next;
                                  }
                                  printf("\n");
                              }
                          }
                          main()
                          {
                              int ch;
                              printf("1. Insert At Beg\n2. Insert At End\n3. Delete At Beg\n4. Delete At End\n5. Display\n6. Exit\n");
                              while(1){
                                  printf("\nEnter Your Choice:\t");
                                  scanf("%d",&ch);
                                  switch(ch){
                                      case 1:
                                                  insertAtBeg();
                                                  break;
                                      case 2:
                                                  insertAtEnd();
                                                  break;
                                      case 3:
                                                  deleteAtBeg();
                                                  break;
                                      case 4:
                                                  deleteAtEnd();
                                                  break;
                                      case 5:
                                                  display();
                                                  break;
                                      case 6:
                                                  exit(0);
                                      default:
                                                  printf("\nInvalid Choice\n\n");
                                  }
                              }
                          }
