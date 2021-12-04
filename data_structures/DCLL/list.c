#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void init(list *l) {
	l->head = l->tail = NULL;
	l->length = 0;
}
void traverse(list *l) {
	printf("Forwards: [ ");
	node *p = l->head;
	while(p != l->tail) {
		printf("%s ", p->str);
		p = p->next;
	}
	if(p)
		printf("%s ", p->str);
	printf(" ]\n");

	printf("Backwards: [ ");
	p = l->tail;
	while(p != l->head) {
		printf("%s ", p->str);
		p = p->prev;
	}
	if(p)
		printf("%s ", p->str);
	printf(" ]\n");
}
/* can insert at positions [0..length] */
void insert(list *l, char *str, int pos) {
	node *p, *tmp;
	int i;
	if(pos < 0 || pos > l->length)		
		return;

	tmp = (node *)malloc(sizeof(node));
	tmp->str = (char *)malloc(strlen(str) + 1);
	strcpy(tmp->str, str);
	if(l->head == NULL) {
		tmp->next = tmp->prev = 
		l->head = l->tail = tmp;
		l->length = 1;
		return;
	}
	/* assert: posoitin is =>0 && <= length */
	p = l->head;
	for(i = 0; i < pos - 1; i++)
		p = p->next;
	if(pos == 0)
		p = p->prev;
	/* assert: p points to the node after which we link tmp*/

	tmp->prev = p;	
	tmp->next = p->next;
	p->next->prev = tmp;
	p->next = tmp;
	if(pos == l->length)
		l->tail = tmp;
	if(pos == 0)
		l->head = tmp;
	(l->length)++;
}
char *remov(list *l, int pos) {
	return NULL;
}
void append(list *l, char *str) {
}
int length(list *l) {
	return l->length;	
}
void reverse(list *l) {
	node *p, *q, *r;
	if(l->head == l->tail)
		return;
	if(l->length == 2) {
		p = l->tail;
		l->tail = l->head;
		l->head = p;
		return;
	}		
	q = l->head;
	p = q->next;
	r = p->next;
	while(q != r) {
		p->next = q;
		q = p;	
		p = r;
		r = r->next;
	}
	l->head  = q->next;

	q = l->tail;
	p = q->prev;
	r = p->prev;
	while(q != r) {
		p->prev = q;
		q = p;	
		p = r;
		r = r->prev;
	}
	l->tail = q->prev;
}
void sort(list *l) {
	node *p, *q, *tmp, *pnext;
	if(l->head == NULL)
		return;
	p = l->head->next;
	while(p != l->head) {
		//insert p in already sorted list
		q = l->head;
		while(strcmp(q->str, p->str) < 0)
			q = q->next;
		/* q points to the node, before which we have to insert p */
		if(q == p) {
			p = p->next;
			continue;
		}	
		tmp = (node *)malloc(sizeof(node));
		tmp->str = p->str;

		
		//link tmp to before q
		tmp->next = q;
		tmp->prev = q->prev;
		q->prev->next = tmp;
		q->prev = tmp;
		if(q == l->head)
			l->head = tmp;
		//destroy p;	
		p->next->prev = p->prev;
		p->prev->next = p->next;
		pnext = p->next;
		if(p == l->tail)
			l->tail = p->prev;
		free(p);	
		p = pnext;
	}	
}
