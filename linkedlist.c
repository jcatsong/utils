#include <stdlib.h>
#include <stddef.h>

#include <stdio.h>

#include "linkedlist.h"

list_t * initList(){
	list_t *temp = malloc(sizeof(list_t));
	if(temp){
		temp->head = NULL;
		temp->tail = NULL;
		temp->count = 0;
	}
	return temp;
}

node_t * initNode(int data){
	node_t *temp = malloc(sizeof(node_t));
	if(temp){
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
	}
	return temp;
}

bool isEmpty(list_t *list){
	return list->count == 0;
}

void freeList(list_t *list){
	node_t *temp1 = list->head; 
	node_t *temp2 = temp1;
	while(temp1){
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	free(list);
}

void addNodeFront(list_t *list, node_t *node){
	// List is empty
	if(list->head == NULL){
		list->head = node;
		list->tail = node;
	}
	// List not empty
	else{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	list->count++;
}

void addNodeRear(list_t *list, node_t *node){
	// List is empty
	if(list->head == NULL){
		list->head = node;
		list->tail = node;
	}
	// List not empty
	else{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	list->count++;
}

node_t * removeNodeFront(list_t *list){
	// Make sure list isnt empty
	if(list->head == NULL){
		return NULL;
	}
	node_t *temp = list->head;

	// Only 1 node in the list	
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	}
	// More than 1 node in the list
	else{
		list->head = list->head->next;
		list->head->prev = NULL;
		temp->next = NULL;
	}
	list->count--;
	return temp;
}

node_t * removeNodeRear(list_t *list){
	// Make sure list isnt empty
	if(list->head == NULL){
		return NULL;
	}
	node_t *temp = list->tail;
	// Only 1 node in the list
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	}
	// More than 1 node in the list
	else{
		list->tail = temp->prev;
		list->tail->next = NULL;
		temp->prev = NULL;
	}
	list->count--;
	return temp;
}


