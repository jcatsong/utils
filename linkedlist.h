#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

// Represents a node in the list
typedef struct Node node_t;
struct Node{
	int data;
	node_t *prev;	
	node_t *next;
};

// Represents the list as a whole
typedef struct List{
	node_t *head;
	node_t *tail;
	int count;
}list_t;

/*
	Returns a pointer to an empty linked list if init is successful, NULL otherwise
*/
list_t * initList();

/*
	Returns a pointer to a new node if successful containing supplied int, NULL otherwise
*/
node_t * initNode(int);

/*
	Returns true if the list is empty
*/
bool isEmpty(list_t*);

/*
	Free the specified node
*/
void freeNode(node_t *);

/*
	Free the specified list
*/
void freeList(list_t *);

/*
	Add the specified node to the beginning of the list
*/
void addNodeFront(list_t *, node_t *);

/*
	Add the specified node to the end of the list.
*/
void addNodeRear(list_t *, node_t *);

/*
	Remove the front node and return a pointer to it.  Returns NULL if failed
*/
node_t * removeNodeFront(list_t *);

/*
	Remove the rear node and return a pointer to it.  Returns NULL if failed
*/
node_t * removeNodeRear(list_t *);

#endif
