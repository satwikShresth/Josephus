//Mark Boady
//Josephus Puzzle

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
//You may change this file

//You MUST leave this function prototype
//You MUST use a Queue to solve this problem
//n is the number of people
//m is denotes how often to kill a person
//If n=7 and m=3, you would have 7 people and start by killing
//the third person.
//Return an ARRAY contain the people in the order by died
//Example: n=7 and m=3
//Array Returned will be [2, 5, 1, 6, 4, 0, 3]
int* josephus(int n, int m);

//You are free to add any additional functions you need

//Main Function
//Takes 2 command line arguments
int main(int argc, char** argv){

  if( argc != 3 ) 
	{
    perror("Invalid inputs");
    return 0;
  }
  int *arr = josephus(atoi(argv[1]),atoi(argv[2]));
  for(int count =0;count<atoi(argv[1]);count++)
    {
      if(count == 0){
        printf("Order: [%d,",*(arr+count));
        }
      else if (count == atoi(argv[1])-1)
      {
        printf(" %d]\n",*(arr+count));
      }
      else{
        printf(" %d,",*(arr+count));
      }
    }
  printf("Josephus will sit in position: %d\n",*(arr+atoi(argv[1])-1));
  free(arr);
  arr = NULL;
}

//Solve the Josephus Problem
//Input: n - number of people
//       m which person to start killing on
//       Every m-th person is killed
//Outputs: Array with people killed in order of death
//Side Effects: None
//NOTE: YOU MUST SOLVE THIS USING YOUR QUEUE
int* josephus(int n, int m){
  struct Queue* newQ = newQueue();
  for(int count = 0;count<n;count++)
      enqueue(count,newQ);
  newQ->tail->next = newQ->head;
  int *arr = calloc(n,sizeof(*arr));
  for(int count=0;count<n;count++)
    {
      for(int count2 = 1;count2<m;count2++)
        {
          newQ->head = newQ->head->next;
          newQ->tail = newQ->tail->next;
        }
      *(arr+count)= front(newQ);
      newQ->tail->next = newQ->head->next;
      dequeue(newQ);
    }
  newQ->tail = newQ->head->next;
  newQ->tail->next = NULL;
  newQ->head->next = NULL;
  newQ->head = NULL;
  newQ->tail = NULL;
  free(newQ);
  newQ = NULL;
  return arr;
}
 