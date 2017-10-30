#include<iostream>
using namespace std;

void FindLocation(int);
struct student{
  int data;
  student* next;
  student* prev;
} *loc,*head,*tail,*ptr;

void insertion_begin(int y){
  student* temp=new student();
  
 if(head==NULL){
  temp->next=NULL;
 temp->prev=NULL;
  head=temp;
  tail=temp;
  temp->data=y;
}
 else{
  temp->next=head;
  temp->prev=NULL; 
  head->prev=temp;
  head=temp;
  temp->data=y;
  }

}
void insertion_end(int y){
 student* temp=new student();

 if(head==NULL){
  temp->next=head;
  temp->prev=head;
   head=temp;
   tail=temp;
  temp->data=y;
}
 else{
  temp->next=NULL;
  temp->prev=tail;
  tail->next=temp;
  tail=temp;
 temp->data=y;
}
}
void insertion_after(int y1){

        student* temp=new student();
         int k3;
    cout<<"enter the element after which data to be inserted ";
    cin>>k3;
        FindLocation(k3);
	  if(loc==NULL)
               insertion_end(y1);
           else{
		temp->next=loc->next;
		temp->prev=loc;
		loc->next->prev=temp;
		loc->next=temp;
                temp->data=y1;
   }
}
void insertion_before(int y2){
         student* temp=new student();
        int k1;
    cout<<"enter the element before which data to be inserted ";
    cin>>k1;
        FindLocation(k1);
          if(loc==NULL)
               insertion_begin(y2);
	  else{
		temp->next=loc;
		temp->prev=loc->prev;
		loc->prev->next=temp;
		loc->prev=temp;
                 temp->data=y2;
      }
}
void FindLocation(int k2){
       student* p=head;
	while(p!=NULL){
		if(p->data==k2){
		  loc=p;
		  return;
       }
		else
		   p=p->next;
           
  }

  loc=NULL;
}
       

void display()
{
  student* q=head;
  while(q!=NULL){
  cout<<q->data<<" ";
  q=q->next;
}
cout<<endl<<endl;
}
int main()
{
        head=NULL;
	tail=NULL;
        int i,n,x,k,m,a;
         cout<<endl<<"Enter the number of elements: ";
        cin>>n;
         while(1){
        cout<<"select from the following: "<<endl;
        cout<<"1.insertion at the beginning "<<endl;
        cout<<"2.insertion at the end"<<endl;
        cout<<"3. insertion after a given element"<<endl;
        cout<<"4.insertion before a given location"<<endl;
        cout<<"5.display the given list"<<endl;
        cout<<"6.exit"<<endl;
	 cin>>k;
        switch(k)
        {
          case 1: cout<<"enter the number:";
           for(i=0;i<n;i++){
            cin>>x;
            insertion_begin(x);
      }
           break;
          case 2: cout<<"enter the number:";
           for(i=0;i<n;i++){
            cin>>x;
            insertion_end(x);
        }
           break;
          case 3: cout<<"enter the element to be inserted: ";
                  cin>>m;
                   insertion_after(m);
          break;
          case 4: cout<<"enter the element to be inserted: ";
                  cin>>a;
		  insertion_before(a);
          break;
          case 5: display();
          break;
        case 6: return(0);
           default: cout<<"incorrect choice"<<endl;

        }
        }
    return(0);
}                   
                                                            

