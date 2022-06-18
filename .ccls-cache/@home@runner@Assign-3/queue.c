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
	//Implement Me
	return NULL;//remove when done
}

//Determine if the Queue is Empty
//Inputs: Pointer to the Q
//Outputs: 1 if empty, 0 if contains values
//Side Effects: None
char isEmpty(struct Queue* Q){
	//Implement Me
	return 10;//remove when done
}

//Add a new value to the Queue
//Inputs: Value to Add and pointer to Queue
//Outputs: None
//Side Effects: Allocates memory for new value
// and modifies Queue
void enqueue(int v, struct Queue* Q){
	//Implement Me
}

//Get value in front of queue
//Inputs: Pointer to Queue
//Outputs: First value in Queue or
//        -1 if empty
//Side Effects: None
int front(struct Queue* Q){
	//Implement Me
	return -5;//remove when done
}

//Remove the First Value from the Queue
//Inputs: Pointer to Queue
//Outputs: None
//Side Effects: Modifies Queue to remove first element
//	     Deletes first element from memory
//Reminder: Don't leak any memory!
void dequeue(struct Queue* Q){
	//Implement Me
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
