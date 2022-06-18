//Mark Boady
//Template for a Queue

//**You May NOT change this file**

#ifndef _QUEUE_H_
#define _QUEUE_H_

//We need a data structure for the node
//It contains an integer
//and a pointer to the next value
struct Node{
	int value;
	struct Node* next;
};

//A queue just contains a pointer
//to the head and tail node
struct Queue{
	struct Node* head;
	struct Node* tail;
};

//These are the Functions used
//To work with the Queue

//Return a Pointer to an empty queue
struct Queue* newQueue();

//Ask if the Queue is Empty
//1 for True or 0 for False
char isEmpty(struct Queue* Q);

//Add a value to the back of the queue
void enqueue(int v, struct Queue* Q);

//Ask what value is at the front of the queue
int front(struct Queue* Q);

//Remove Value at front of the queue
void dequeue(struct Queue* Q);

//Print Queue to Help you Debug
void printQueue(struct Queue* Q);

#endif
