#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	int color;
	struct node *parent;
	struct node *next; 
};

void bfs(struct node *a[],int size){
	for(int j=0;j<size;j++){
		a[j]->color=-1;
		a[j]->parent=NULL;
	}
	a[0]->color=0;
	struct node *q[100];
	for(int j=0;j<100;j++){
		q[j]=(struct node *)malloc(sizeof(struct node));
	}
	int k=0;
	int cnt=1;
	while(k<size){
	printf("List of connected components %d:\n",cnt);
	cnt++;
	int i=-1;
	int f=0;
	q[++i]=a[k];
	//printf("%d\n",q[0]->data);
	while(i>=f){
		struct node *u=q[f++];
		printf("%d ",u->data);
		struct node *p=u;
		while(p->next!=NULL){
			p=p->next;
			int j;
			for(j=0;j<size;j++){
				if(a[j]->data==p->data) break;
			}
			if(a[j]->color==-1){
				q[++i]=a[j];
				a[j]->color=0;
				a[j]->parent=u;
			}
		}
		u->color=1;
	}
	printf("\n");
	for(k=0;k<size;k++){
		if(a[k]->color==-1) break;
	}
	}

		
	
}

void printpath(struct node *a[],struct node *s,struct node *v){
	if(v->data==s->data) printf("%d ",s->data);
	else if(v->parent==NULL) {printf("No path"); return;}
	else{
		printpath(a,s,v->parent);
		printf("%d ",v->data);
	}
}

void path(struct node *a[],int i,int j)
{
	int arr[100];
	int r=-1;
	int f=0;
	if(a[i]->parent==NULL && a[j]->parent==NULL)
	{
		printf("No path.\n");
	}
	else if(a[i]->parent!=NULL)
	{
		struct node *t=a[i];
		while(t!=NULL)
		{
			arr[++r]=t->data;
			if(t->data==j) break;
			else t=t->parent;
		}

		if(arr[r]==j)
		{
			printf("Path exists.\n");
			while(r>=f)
			{
				printf("%d ",arr[f++]);
			}
			printf("\n");
		}

		else printf("No path.\n");
	}
	else
	{
		struct node *t=a[j];
		while(t!=NULL)
		{
			arr[++r]=t->data;
			if(t->data==i) break;
			else t=t->parent;
		}

		if(arr[r]==i)
		{
			printf("Path exists\n");
			while(r>=f)
			{
				printf("%d ",arr[f++]);
			}
			printf("\n");
		}
		else printf("No path exists\n");
	}
}


int main(){
	int v;
	int e;
	scanf("%d",&v);
	scanf("%d",&e);
	struct node *a[v];
	int size=0;
	for(int i=0;i<e;i++){
		int x,y;
		int j=0,k=0;
		scanf("%d%d",&x,&y);
		//printf("Initially size is %d\n",size);
		while(j<size){
			//printf("j<size loop runs\n");
			if(a[j]->data==x) break;
			else j++;
		}
		//printf("value of j is %d\n",j);
		while(k<size){
			//printf("k<size loop runs\n");
			if(a[k]->data==y) break;
			else k++;
		}
		//printf("value of k is %d\n",k);
		if(j<size && k<size){
			//printf("Condition is j<size && k<size\n");
			struct node *p=a[j];
			struct node *q=a[k];
			while(p->next!=NULL){
				p=p->next;
			}
			while(q->next!=NULL){
				q=q->next;
			}
			struct node *newp=(struct node *)malloc(sizeof(struct node));
			struct node *newq=(struct node *)malloc(sizeof(struct node));
			newp->data=x;newp->next=NULL;
			newq->data=y;newq->next=NULL;
			p->next=newq;q->next=newp;
		}

		if(j==size && k<size){
			//printf("condition is j==size && k<size\n");
			size++;
			//a[size-1]->data=x;
			struct node *p=(struct node *)malloc(sizeof(struct node));
			p->data=y;p->next=NULL;
			struct node *q=(struct node *)malloc(sizeof(struct node));
			q->data=x;q->next=NULL;
			struct node *p1=(struct node *)malloc(sizeof(struct node));
			p1->data=x;p1->next=p;
			struct node *temp=a[k];
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=q;
			//a[size-1]->next=p;
			a[size-1]=p1;
		}	

		if(j<size && k==size){
			//printf("condition is j<size && k==size\n");
			size++;
			//a[size-1]->data=y;
			struct node *p=(struct node *)malloc(sizeof(struct node));
			p->data=x;p->next=NULL;
			struct node *q=(struct node *)malloc(sizeof(struct node));
			q->data=y;q->next=NULL;
			struct node *p1=(struct node *)malloc(sizeof(struct node));
			p1->data=y;p1->next=p;
			struct node *temp=a[j];
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=q;
			//a[size-1]->next=p;
			a[size-1]=p1;
		}

		if(j==size && k==size){
			//printf("condition is j==size && k==size\n");
			size=size+2;
			struct node *p=(struct node *)malloc(sizeof(struct node));
			struct node *q=(struct node *)malloc(sizeof(struct node));
			struct node *p1=(struct node *)malloc(sizeof(struct node));
			struct node *q1=(struct node *)malloc(sizeof(struct node));
			p1->data=x;p1->next=q;
			q1->data=y;q1->next=p;
			p->data=x;p->next=NULL;
			q->data=y;q->next=NULL;
			a[size-2]=p1;
			a[size-1]=q1;
		}
		/*printf("Current size is %d\n",size);
		for(int v=0;v<size;v++){
			printf("%d %d\n",a[v]->data,a[v]->next->data);
		}*/
		//printf("\n");

		
	}
	bfs(a,size);
	//printpath(a,a[6],a[1]);
	printf("\n");
	path(a,1,4);
	return 0;
}
