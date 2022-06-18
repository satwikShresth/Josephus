//Mark Boady
//Queue Implementation

//**Implement this file
//may change this file as needed

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

//Create a new empty queue
//Inputs: None
//Outputs: A Pointer to a new empty queue
//Side Effects: None
//Note: Remember to set all the values correctly
struct Queue* newQueue(){
	struct Queue* Q;
  Q = calloc(0,sizeof(*Q));
  if (!Q) {
      printf("Failed to malloc() item! Exiting...\n");
      return NULL;
    }
  Q->head->next = NULL;
  Q->tail->next = NULL;
  
	return Q;//remove when done
}

//Determine if the Queue is Empty
//Inputs: Pointer to the Q
//Outputs: 1 if empty, 0 if contains values
//Side Effects: None
char isEmpty(struct Queue* Q){
	if(Q->head)
    return 0;
	return 1;
}

//Add a new value to the Queue
//Inputs: Value to Add and pointer to Queue
//Outputs: None
//Side Effects: Allocates memory for new value
// and modifies Queue
void enqueue(int v, struct Queue* Q){
  struct Node* item;
  item = calloc(0,sizeof(*item));
  item->value = v;
  item->next = NULL;
  if (!Q->head)
  {
    Q->head = item;
    Q->tail = item;
  }
  else
  {
    for(Q->tail = Q->head;Q->tail->next != NULL;Q->tail = Q->tail->next);
    Q->tail->next = item;
    Q->tail = item;
  }
}

//Get value in front of queue
//Inputs: Pointer to Queue
//Outputs: First value in Queue or
//        -1 if empty
//Side Effects: None
int front(struct Queue* Q){
  if(!Q->head)
    return -1;
	return Q->head->value;
}

//Remove the First Value from the Queue
//Inputs: Pointer to Queue
//Outputs: None
//Side Effects: Modifies Queue to remove first element
//	     Deletes first element from memory
//Reminder: Don't leak any memory!
void dequeue(struct Queue* Q){
  struct Node* cur;
  cur = Q->head;
  if(cur)
  {
    Q->head = Q->head->next;
    cur->next = NULL;
  }
  free(cur);
  cur = NULL;
}

//Print Queue to Help you Debug
//Inputs: Pointer to the Queue
//Outputs: None
//Side Effects: Prints the Queue to stdout
void printQueue(struct Queue* Q){
	if(Q->head==NULL){
		printf("Empty Queue\n");
		return;
	}
	struct Node* n = Q->head;
	printf("Queue Contents: [");
	while(n!=NULL){
		printf("%d",n->value);
		n=n->next;
		if(n!=NULL){
			printf(",");
		}
	}
	printf("]\n");
	return;
}
