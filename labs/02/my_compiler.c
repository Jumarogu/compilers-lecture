#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <limits.h> 
// Queue implementation taken from https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
// Not written by Me
struct Queue 
{ 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 

struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 

int isFull(struct Queue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int isEmpty(struct Queue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    printf("%d enqueued to queue\n", item); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
int front(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
int rear(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 

int main(int arg, char *arv[]) {

    char fileName[strlen(arv[1]) + 1];
    strcpy(fileName, arv[1]);
    FILE *file = fopen(fileName, "r");
    int n = 0;
    char c;

    if( file == NULL) return 0;

    while((c = (char)fgetc(file)) != EOF){
        if(c == '\n') {
            printf("salto linea");
        }
        printf("%c", c);
    }
    printf("%s\n", fileName);

    return 0;
}
