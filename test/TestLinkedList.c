#include <stdlib.h>

#include <unity.h>

#include "linkedlist.h"


void testEmptyList(){
	list_t *list = initList();
	
	TEST_ASSERT_TRUE(0 == list->count);
	TEST_ASSERT_TRUE(NULL == list->head);
	TEST_ASSERT_TRUE(NULL == list->tail);

	freeList(list);
}

void testRemoveFrontEmptyList(){
	list_t *list = initList();
	node_t *temp = removeNodeFront(list);

	TEST_ASSERT_TRUE(NULL == temp);
	freeList(list);
}

void testRemoveRearEmptyList(){
	list_t *list = initList();
	node_t *temp = removeNodeRear(list);

	TEST_ASSERT_TRUE(NULL == temp);
	freeList(list);
}

void testOneItemAddedFront(){
	list_t *list = initList();
	int data = 1;
	addNodeFront(list, initNode(data));
	
	TEST_ASSERT_TRUE(1 == list->count);
	TEST_ASSERT_TRUE(list->head == list->tail);
	TEST_ASSERT_EQUAL_INT(list->head->data, data);
	
	freeList(list);
}

void testOneItemAddedRear(){
	list_t *list = initList();
	int data = 1;
	addNodeRear(list, initNode(data));
	
	TEST_ASSERT_TRUE(1 == list->count);
	TEST_ASSERT_TRUE(list->head == list->tail);
	TEST_ASSERT_EQUAL_INT(list->head->data, data);
	
	freeList(list);
}

void testRemoveRearOneItem(){
	list_t *list = initList();
	int data = 1;
	addNodeRear(list, initNode(data));
	
	node_t *temp = removeNodeRear(list);
	TEST_ASSERT_EQUAL_INT(data, temp->data);
	TEST_ASSERT_TRUE(NULL == temp->next);
	TEST_ASSERT_TRUE(NULL == temp->prev);
	TEST_ASSERT_EQUAL_INT(0, list->count);
	TEST_ASSERT_TRUE(NULL == list->head);
	TEST_ASSERT_TRUE(NULL == list->tail);

	freeList(list);
	free(temp);
}

void testRemoveFrontOneItem(){
	list_t *list = initList();
	int data = 1;
	addNodeFront(list, initNode(data));
	
	node_t *temp = removeNodeFront(list);
	TEST_ASSERT_EQUAL_INT(data, temp->data);
	TEST_ASSERT_NULL(temp->next);
	TEST_ASSERT_NULL(temp->prev);
	TEST_ASSERT_EQUAL_INT(0, list->count);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);

	freeList(list);
	free(temp);
}

void testAddRandomSideThenRemoveRandomSide(){
	list_t *list = initList();
	const int SEED = 1;
	const int MIN_NUM_CARDS = 100;
	const int MAX_NUM_CARDS = 1000;

	srand(SEED);
	int numNodesToAdd = (rand() + MIN_NUM_CARDS) % MAX_NUM_CARDS;
	int numNodesToRemove = (rand() + MIN_NUM_CARDS) % numNodesToAdd;
	int diff = numNodesToAdd - numNodesToRemove;
	int i;
	printf("Adding %d nodes, Removing %d nodes\n", numNodesToAdd, numNodesToRemove);
	for(i = 0; i < numNodesToAdd; i++){
		if(rand() % 2){
			addNodeFront(list, initNode(i));
		}
		else{
			addNodeRear(list, initNode(i));	
		}
	}

	for(i = 0; i < numNodesToRemove; i++){
		if(rand() % 2){
			removeNodeFront(list);
		}
		else{
			removeNodeRear(list);
		}
	}
	
	TEST_ASSERT_EQUAL_INT(diff, list->count);
	
	freeList(list);
}


void testRemoveNPlusOneItems(){
	list_t *list = initList();
	const int NUM_NODES_TO_ADD = 10;
	int i;
	for(i = 0; i < NUM_NODES_TO_ADD; i++){
		addNodeFront(list, initNode(i));
	}
	TEST_ASSERT_EQUAL_INT(NUM_NODES_TO_ADD, list->count);

	for(i = 0; i < NUM_NODES_TO_ADD; i++){
		removeNodeFront(list);
	}
	TEST_ASSERT_EQUAL_INT(0, list->count);
	node_t *nullNode = removeNodeFront(list);
	TEST_ASSERT_NULL(nullNode);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
}


int main(int argc, char *argv[]){
	UNITY_BEGIN();

	RUN_TEST(testEmptyList);
	RUN_TEST(testRemoveFrontEmptyList);
	RUN_TEST(testRemoveRearEmptyList);
	RUN_TEST(testOneItemAddedFront);
	RUN_TEST(testOneItemAddedRear);
	RUN_TEST(testRemoveRearOneItem);
	RUN_TEST(testRemoveFrontOneItem);
	RUN_TEST(testAddRandomSideThenRemoveRandomSide);
	RUN_TEST(testRemoveNPlusOneItems);
	UNITY_END();
}
