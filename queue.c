#ifndef QUEUE
#define QUEUE

#include <stdio.h>

typedef int bool;

#ifndef false
    #define false 0
#endif

#ifndef true
    #define true 1
#endif

#ifndef empty
    #define empty 0xBADE4EA4
#endif

struct queue
{
    pid_t *pid;
    int *numberOfIterations;
    int *jobNumber;
    struct queue *previous;
};

struct queue *emptyFrame;

void createQueue(struct queue *queueToBe)
{
    queueToBe -> pid = empty;
    queueToBe -> previous = NULL;
}

struct queue *addToEnd(struct queue *currentQueue, pid_t newID, int runNumb, int jobNum)
{
    if(currentQueue -> previous == NULL)
    {
        struct queue *newQueue;
        newQueue = (struct queue*)malloc(sizeof(struct queue));
        newQueue -> pid = newID;
        newQueue -> previous = NULL;
        newQueue -> numberOfIterations = runNumb;
        
        newQueue -> jobNumber = jobNum;
        
        currentQueue -> previous = newQueue;
    }
    else if(currentQueue -> previous != NULL)
        currentQueue = addToEnd(currentQueue -> previous, newID, runNumb, jobNum);
    return currentQueue;
}

void updateIterations(struct queue *currentQueue) 
{
    if(currentQueue -> pid != empty)
    {
        int temp = currentQueue -> numberOfIterations;
        temp = temp + 1;
        currentQueue -> numberOfIterations = temp;
    }
}

void enqueue(struct queue *currentQueue, pid_t newID, int runNumb, int jobNum)
{
    if(currentQueue -> pid == empty) 
    {
        currentQueue -> pid = newID;
        currentQueue -> numberOfIterations = runNumb;
        currentQueue -> jobNumber = jobNum;
    }
    else
    {
        if(currentQueue -> previous == NULL) 
        {
            struct queue *newQueue;
            newQueue = (struct queue*)malloc(sizeof(struct queue));
            newQueue -> previous = NULL;
            newQueue -> pid = newID;
            newQueue -> numberOfIterations = runNumb;
            newQueue -> jobNumber = jobNum;
            
            currentQueue -> previous = newQueue;
        }
        else if(currentQueue -> previous != NULL)
            currentQueue = addToEnd(currentQueue -> previous, newID, runNumb, jobNum);
    }
    
}

int getSize(struct queue *currentQueue) 
{
    int count = 0;
    struct queue* tempQueue;
    tempQueue = (struct queue*)malloc(sizeof(struct queue));
    tempQueue = currentQueue;
    while(tempQueue != NULL)
    {
        tempQueue = tempQueue -> previous;
        count++;
    }
    return count;
}

void clearIterations(struct queue *currentQueue) {currentQueue -> numberOfIterations = 0;}
int peekIterations(struct queue currentQueue) {return currentQueue.numberOfIterations;}
pid_t peek(struct queue currentQueue) {return currentQueue.pid;}
int peekJob(struct queue currentQueue) {return currentQueue.jobNumber;}

pid_t dequeue(struct queue *currentQueue)
{
    pid_t temp;
    struct queue *tempQueue;
    if(currentQueue -> pid == empty) return empty;
    else if(currentQueue -> previous == NULL) 
    {
        temp = currentQueue -> pid;
        currentQueue -> pid = empty;
    }
    else
    {
        temp = currentQueue -> pid;
        currentQueue -> pid = currentQueue -> previous -> pid;
        currentQueue -> jobNumber = currentQueue -> previous -> jobNumber;
        currentQueue -> numberOfIterations = currentQueue -> previous -> numberOfIterations;
        tempQueue = currentQueue -> previous -> previous;
        free(currentQueue -> previous);
        currentQueue -> previous = tempQueue;
    }
    return temp;
}

bool checkEmpty(struct queue *currentQueue)
{
    if(currentQueue -> pid == empty) return true;
    return false;
}

void viewEntire(struct queue *viewQueue)
{
    struct queue* tempQueue;
    tempQueue = (struct queue*)malloc(sizeof(struct queue));
    tempQueue = viewQueue;
    while(tempQueue != NULL)
    {
        printf("%i \n", tempQueue -> pid);
        tempQueue = tempQueue -> previous;
    }
}
