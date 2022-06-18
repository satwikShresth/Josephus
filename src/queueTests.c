//Mark Boady
//Test for Queue DS

//**You May NOT change this file**
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "queue.h"

//Tests
//Return 1 on pass
//Return 0 on fail
//Print out Reasons for Failure
//Can we create a Queue
char testNewQueue();
//Test Adding to a queue
char testEnqueue();
//Test Front
char testFront();
//Check isEmpty
char testIsEmpty();
//Test Dequeue
char testDequeue();
//Insert and Delete some random numbers
char testRandom();

//Helpers
//Checks for last element in list
char checkTail(struct Queue* Q, int target);

//Test the Queue DS
//0 for passed
//1 for failed
//Runs many unit tests
//Command line argument determines what test
int main(int argv, char** argc){
	srand(time(0));
	//Takes One Command Line Argument
	//Test to run
	//0 means ALL
	int testToRun=0;
	if(argv > 1){
		testToRun = atoi(argc[1]);
	}
	//Run Tests based on input
	switch(testToRun){
		case 0:
			printf("Running ALL Tests\n");
		case 1:
			if(!testNewQueue()){return 1;}
			if(testToRun!=0){break;};
		case 2:
			if(!testEnqueue()){return 1;}
			if(testToRun!=0){break;};
		case 3:
			if(!testFront()){return 1;}
			if(testToRun!=0){break;};
		case 4:
			if(!testIsEmpty()){return 1;}
			if(testToRun!=0){break;};
		case 5:
			if(!testDequeue()){return 1;}
			if(testToRun!=0){break;};
		case 6:
			if(!testRandom()){return 1;}
			if(testToRun!=0){break;};
	}
	return 0;
}


//Test Creation
//Inputs: None
//Outputs: 1 if passed 0 if failed
//Side Effects: Prints reason for failure or success
char testNewQueue(){
	struct Queue* Q = newQueue();
	if(Q==NULL){
		printf("newQueue: FAILED\n");
		printf("Calling newQueue returned NULL.\n");
		return 0;
	}
	if(Q->head!=NULL){
		printf("newQueue: FAILED\n");
		printf("Calling newQueue return object that did not have NULL head.\n");
		return 0;
	}
	if(Q->tail!=NULL){
		printf("newQueue: FAILED\n");
		printf("Calling newQueue return object that did not have NULL tail.\n");
		return 0;
	}
	printf("newQueue: PASSED\n");
	return 1;
}

//Test Enqueue
//Inputs: None
//Outputs: 1 if passed 0 if failed
//Side Effects: Prints reason for failure or success
char testEnqueue(){
	struct Queue* Q = newQueue();
	int tests=10;
	//Check that elements are added in
	for(int i=0; i < tests; i++){
		enqueue(i,Q);
		//Sanity Check
		if(Q->head==NULL){
			printf("enqueue: FAILED\n");
			printf("Head Null After Enqueue Call!\n");
			return 0;
		}
		if(Q->tail==NULL){
			printf("enqueue: FAILED\n");
			printf("Tail Null After Enqueue Call!\n");
			return 0;
		}
		//Check for Value
		if(!checkTail(Q,i)){
			printf("enqueue: FAILED\n");
			printf("enqueue(%d,Q) did not add %d to tail of queue.\n",i,i);
			printf("Tail Pointer must point to number.\n");
			printQueue(Q);
			return 0;
		}
	}
	//Check the Whole List
	struct Node* ptr = Q->head;
	int count=0;
	while(ptr!=NULL){
		if(ptr->value != count){
			printf("Inserted Numbers from 0 to %d into Q.\n",tests);
			printf("Did not find %d in correct location.\n",count);
			printQueue(Q);
			return 0;
		}
		count++;
		ptr=ptr->next;
	}
	printf("enqueue: PASSED\n");
	return 1;
}

//Test Front of Queue
//Inputs: None
//Outputs: 1 if passed 0 if failed
//Side Effects: Prints reason for failure or success
char testFront(){
	struct Queue* Q = newQueue();
	if(front(Q)!=-1){
		printf("Front must return -1 on empty queue.\n");
		printQueue(Q);
		printf("front: FAILED\n");
		return 0;
	}
	enqueue(9,Q);
	if(front(Q)!=9){
		printf("Called enqueue(9,Q) and 9 was not front afterwards.\n");
		printQueue(Q);
		printf("front: FAILED\n");
		return 0;
	}
	enqueue(7,Q);
	if(front(Q)!=9){
		printf("Called enqueue(7,Q) after enqueue(9,Q) and 9 was not front afterwards.\n");
		printQueue(Q);
		printf("front: FAILED\n");
		return 0;
	}
	printf("front: PASSED\n");
	return 1;
}

//Test isEmpty
//Inputs: None
//Outputs: 1 if passed 0 if failed
//Side Effects: Prints reason for failure or success
char testIsEmpty(){
	struct Queue* Q = newQueue();
	if(!isEmpty(Q)){
		printf("Called isEmpty on a new Queue.\n");
		printf("Function did not return true.\n");
		printQueue(Q);
		printf("isEmpty: FAILED\n");
		return 0;
	}
	enqueue(8,Q);
	if(isEmpty(Q)){
		printf("Called isEmpty on Queue Containing 8.\n");
		printf("Function did not return false.\n");
		printQueue(Q);
		printf("isEmpty: FAILED\n");
		return 0;
	}
	printf("isEmpty: PASSED\n");
	return 1;
}

//Test Dequeue
//Inputs: None
//Outputs: 1 if passed 0 if failed
//Side Effects: Prints reason for failure or success
char testDequeue(){
	struct Queue* Q = newQueue();
	//Insert 1-5
	for(int i=1; i < 6; i++){
		enqueue(i,Q);
	}
	int expected=1;
	while(!isEmpty(Q)){
		if(front(Q)!=expected){
			printf("Expected %d at front of Queue but saw %d.\n",
				   expected,front(Q));
			printf("Possible error in dequeue.\n");
			printQueue(Q);
			printf("dequeue: FAILED\n");
			return 0;
		}
		dequeue(Q);
		expected++;
	}
	if(expected!=6){
		printf("Dequeue should have removed %d things but only removed %d.\n",
				  6,expected);
		printf("Possible error in dequeue.\n");
		printQueue(Q);
		printf("dequeue: FAILED\n");
		return 0;
	}
	
	printf("dequeue: PASSED\n");
	return 1;
}

//Insert and Delete some random numbers
//Inputs: None
//Outputs: 1 if passed 0 if failed
//Side Effects: Prints reason for failure or success
char testRandom(){
	//This test generates 3 random arrays
	//It adds then removes all the numbers from the same queue
	struct Queue* Q = newQueue();
	for(int i=0; i < 3; i++){
		//Determine Size
		int size = rand()%10+1;
		//Make array
		int* T = malloc(size*sizeof(int));
		//Put random numbers in
		for(int k=0; k < size; k++){
			T[k]=rand()%100+1;
		}
		//Enqueue them all
		for(int k=0; k < size; k++){
			enqueue(T[k],Q);
		}
		//Dequeue them all
		for(int k=0; k < size; k++){
			if(front(Q)!=T[k]){
				//Something Bad Happened
				printf("Attempted to enqueue and dequeue repeatedly from Queue.\n");
				printf("Failed on Repetition %d on Queue.\n",i);
				printf("Tried to enqueue and dequeue: [");
				for(int a=0; a < size; a++){
					printf("%d",T[a]);
					if(a+1!=size){printf(", ");}
				}
				printf("]\n");
				printQueue(Q);
				printf("Random Values: FAILED\n");
				return 0;
			}
			dequeue(Q);
		}
	}
	printf("Random Values: PASSED\n");
	return 1;
}

//Checks for last element in list
//Inputs: Pointer to Q and Target
//Outputs: 1 if value is at tail and 0 otherwise
//Side Effects: None
char checkTail(struct Queue* Q, int target){
	struct Node* ptr = Q->tail;
	//Compare to last element
	return ptr->value==target;
}

