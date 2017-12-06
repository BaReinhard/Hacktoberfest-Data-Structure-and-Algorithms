#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}*Node;

Node insert(Node p,int q){
	Node temp = p;
	while(temp->next != NULL){
		temp = temp->next;
	}
	Node temp2 = (Node) malloc(sizeof(struct node*));
	temp2->data = q;
	temp->next = temp2;
	return p;
}

void displayList(Node a){
	while(a != NULL){
		printf("%d ",a->data+1);
		a = a->next;
	}
}

void main(){
	printf("Enter Number of vertices");
	int n;
	scanf("%d",&n);
	Node adj[n];
	int adjm[n][n];
	int i;
	int k;
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
			adjm[i][k] = 0;
		}
	}
	for(i=0;i<n;i++){
		adj[i] = (Node) malloc(sizeof(struct node*));
		adj[i]->data = i;
	}
	printf("Enter Number of edges");
	int e;
	scanf("%d",&e);
	printf("Enter edges");
	for(i=0;i<e;i++){
		int p,q;
		scanf("%d",&p);
		p--;
		if(p>n-1){
		printf("Invalid vertex");
		return;
	}
		scanf("%d",&q);
		q--;
		if(q>n-1){
	printf("Invalid vertex");		
	return;
		}
		adjm[p][q] = 1;
		adjm[q][p] = 1;
		adj[p] = insert(adj[p],q);
		adj[q] = insert(adj[q],p);
	}
	int j;
	printf("Adjacency Matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",adjm[i][j]);
		}
		printf("\n");
	}
	printf("Adjacency List\n");
	for(i=0;i<n;i++){
	displayList(adj[i]);
	printf("\n");
}
}
