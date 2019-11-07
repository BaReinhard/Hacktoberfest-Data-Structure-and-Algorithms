/* Input format
• ‘N’ followed by number of vertices n.
• ‘E’ followed by a vertex and vertex-weight pairs that look like:
u, v1,w(u, v1), v2,w(u, v2) · · · , vk,w(u, vk)
This list gives the adjacency list of vertex u along with the respective edge weights.
The list is given as a space-separated list.
• ‘?’ followed by u, v ∈ [n] with a space separating them.
• ‘D’ followed by a u ∈ [n].
• ‘P’ followed by u, v ∈ [n] with a space separating them.


Output Format

• If input line started with ‘N’ or ‘E’, then no corresponding output.
• If input line was “? u v”: Output w(u, v) if (u, v) ∈ E, −1 otherwise.
• If input line was “D u”:
Let v1, v2, . . . , vn be the order of vertices visited on a run of of Dijkstra’s algorithm
from u (note that u = v1). Let δ(u, v) denote the shortest path from u to v. Output
a list of pairs: (v1, δ(u, v1)), . . . ,(vn, δ(u, vn)). If δ(u, v) = ∞ then output −1 in its
place. Use a space to separate v and δ(u, v) within a pair. Use a ‘\n’ between pairs.
• If input line was “P u v”:
If v is not reachable from u, output −1. Else output the shortest distance from u to
v followed by a shortest path from u to v as a space-separated list of vertices starting
with u.
All output lines end with a ‘\n’ character.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct adjLnode{
  int vertex,weight;
  struct adjLnode *next;
};

struct res_node{
  char visited;
  int parent,distance;
};

struct heap_node{
  int vertex,priority;
};

void insert_at_end(struct adjLnode **head,struct adjLnode **tail,int vertex,int weight){
     struct adjLnode *x=(struct adjLnode*)malloc(sizeof(struct adjLnode));
     x->vertex=vertex;    
     x->weight=weight;    // The above function appends element at the end of a LL
     x->next=NULL;
     if(*head==NULL)      // In this case tail is also NULL
        *head=x;
     else
        (*tail)->next=x;
     *tail=x;
}

void freell(struct adjLnode *head){          // Function to free linked list
     struct adjLnode* temp=head;
     while(head){
          temp=head->next;
          free(head);
          head=temp;
          }                   
}

void edge_present(struct adjLnode**graph,int u,int v){
     struct adjLnode *temp=graph[u];
     while(temp){                     
        if(temp->vertex==v){    // Go to adjacency list of 'u' and check if 'v' is present
            printf("%d\n",temp->weight);
            return;
            }
        temp=temp->next;
        }
     printf("-1\n");
}

void free_graph(struct adjLnode **graph,int n){
     for(int i=0;i<=n;i++)
     freell(graph[i]);        // Clear all adjacency lists first
     free(graph);             // Then clear graph array
     graph=NULL;
}

void heapify(struct heap_node *heap, int heapsize, int i) { 
     int min = i; 
     int left = 2*i + 1,right = 2*i + 2;

     if (left < heapsize && heap[left].priority < heap[min].priority) 
        min = left; 
     if (right < heapsize && heap[right].priority < heap[min].priority) 
        min = right; 
     if (min != i) { 
         int w=heap[i].priority,v=heap[i].vertex;
         heap[i].priority=heap[min].priority;     //
         heap[i].vertex=heap[min].vertex;         //
         heap[min].priority=w;                    // Swapping node values
         heap[min].vertex=v;                      //
         heapify(heap, heapsize, min);            
     } 
} 

void insert2heap(int vertex,int priority,struct heap_node *heap,int *heapsize){
     heap[*heapsize].vertex=vertex;
     heap[*heapsize].priority=priority;           // Inserting at last node and heapify
     (*heapsize)++ ;
     for (int i = (*heapsize)/2 - 1; i >= 0; i--) 
         heapify(heap, *heapsize, i); 
}

void deletefromheap(int v,struct heap_node*heap,int *heapsize){
     int i;
     for(i=0;i<*heapsize && heap[i].vertex!=v;i++);  // Search for vertex to be deleted
     if(i>=*heapsize || heap[i].vertex!=v)           // Return if not found
       return;     
     heap[i].vertex=heap[*heapsize-1].vertex;
     heap[i].priority=heap[*heapsize-1].priority;    // If found,swap with last node and call heapify
     (*heapsize)--;
     for (int i = (*heapsize)/2 - 1; i >= 0; i--) 
          heapify(heap, *heapsize, i); 
}

void dijkstra(struct adjLnode **graph,int n,int s){    
     char *visited=(char *)malloc((n+1)*sizeof(char)); // Stores colors of vertices
     int *distance=(int *)malloc((n+1)*sizeof(int));   // Stores distances of vertices from source
     struct heap_node *heap=(struct heap_node *)malloc(n*sizeof(struct heap_node));

     for(int i=0;i<=n;i++)
         visited[i]='w',distance[i]=INT_MAX;       // Intialise all nodes to unvisited and distances to infinity=INT_MAX
     distance[s]=0 ;
     int dist,heapsize=0;

     while(s){                     // NOTE : The following implementation stores only reachable vertices from source in heap    
         visited[s]='b';
         dist=distance[s];
         printf("%d %d\n",s,dist);
         struct adjLnode *temp=graph[s];
         while(temp){                          // For all neighbouring vertices
             int v=temp->vertex,w=temp->weight;
           
             if(visited[v]=='w'){                          // Update distances of all reachable,unvisited vertices
               distance[v]=distance[v]<(dist+w)?distance[v]:(dist+w);
               deletefromheap(v,heap,&heapsize);           // Delete previous entry of vertex,if present
               insert2heap(v,distance[v],heap,&heapsize);  // Update heap with new vertex
               } 

             temp=temp->next;
           }
         s=heapsize?heap[0].vertex:0;          // Assigning s,least distance unvisited vertex
         deletefromheap(s,heap,&heapsize);     // Since s is now visited,delete it from heap
        }
     for(int i=1;i<=n;i++)                     // NOTE : The above implementation stores only reachable vertices from source in heap
         if(distance[i]==INT_MAX)              // Print distances of all unreachable vertices as -1
            printf("%d -1\n",i);      
     free(heap),free(distance),free(visited);
}

void print_shortestpath(struct res_node *stats,int s,int des){
    if(s==des)
    printf(" %d",s);
    if(s!=des){
        print_shortestpath(stats,s,stats[des].parent);
        printf(" %d",des);
    }
}

void printpath(struct adjLnode**graph,int n,int u,int des){
     struct res_node *stats=(struct res_node*)malloc((n+1)*sizeof(struct res_node));
     struct heap_node *heap=(struct heap_node *)malloc(n*sizeof(struct heap_node));

     for(int i=0;i<=n;i++)    // Initialise all nodes to unvisited and distances to infinity=INT_MAX
         stats[i].visited='w',stats[i].distance=INT_MAX,stats[i].parent=0;
     stats[u].distance=0 ;     
     int dist=0,heapsize=0,s=u;

     while(s){                // NOTE : The following implementation stores only reachable vertices from source in heap  
         if(s==des)           // Run dijkstra's till we find distance of desired vertex 
            break;
         stats[s].visited='b';
         dist=stats[s].distance;
         struct adjLnode *temp=graph[s];
         while(temp){        

           int v=temp->vertex,w=temp->weight;

           if(stats[v].visited=='w'){                   // Update distances of all reachable,unvisited vertices
                if(dist+w<stats[v].distance)
                   stats[v].parent=s,stats[v].distance=dist+w;
                deletefromheap(v,heap,&heapsize);                 // Delete previous entry of vertex,if present
                insert2heap(v,stats[v].distance,heap,&heapsize);  // Update heap with new vertex
               } 

             temp=temp->next;
             }
         s=heapsize?heap[0].vertex:0;      // Assigning s,least distance unvisited vertex
         deletefromheap(s,heap,&heapsize); // Since s is now visited,delete it from heap
         }
     if(stats[s].distance==INT_MAX)
        printf("-1\n");
     else{
         printf("%d",stats[des].distance);
         print_shortestpath(stats,u,des);
         printf("\n");
        }
     free(heap),free(stats);
}

int main(){
  int digit,num,weight,N=-1,u,v;
  struct adjLnode** graph=NULL;
  while((digit=fgetc(stdin))!=EOF){

    if(digit=='N'){
       free_graph(graph,N);         // Freeing previous graph
       scanf("%d",&N);
       graph=(struct adjLnode**)malloc((N+1)*sizeof(struct adjLnode*));
       for(int i=0;i<=N;i++)    
           graph[i]=NULL;
       }

    else if(digit=='E'){
       int vertex;
       scanf("%d",&vertex);
       struct adjLnode *head=NULL,*tail=NULL;
       while(getchar()!='\n'){        // Storing all vertices in a linked list in same order
            scanf("%d %d",&num,&weight);
            insert_at_end(&head,&tail,num,weight);
            }
       graph[vertex]=head;   // Now , store the head pointer of the above LL in corresponding source vertex
       }
       
    else if(digit=='?'){
       scanf("%d%d",&u,&v);
       edge_present(graph,u,v);
       }
    else if(digit=='D'){
       scanf("%d",&num);
       dijkstra(graph,N,num);
       }
    else if(digit=='P'){
       scanf("%d%d",&u,&v);
       printpath(graph,N,u,v);
       }
    }
free_graph(graph,N);
return 0;
}
