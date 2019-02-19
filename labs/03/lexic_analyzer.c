#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <limits.h> 
#include <regex.h>
 
int match(const char *string, const char *pattern)
{
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;
    int status = regexec(&re, string, 0, NULL, 0);
    regfree(&re);
    if (status != 0) return 0;
    return 1;
}
// Queue implementation taken from https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/
// Not written by Me
struct Queue 
{ 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
};

struct Keyword
{
    int keyword;
    char *c;
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

int isSpace(char *c) {
    if(*c == ' ') {
        return 1;
    }
    return 0;
}

int isAssing(char *line) {
    return match(line, "[a-z]{1}=.*") ? 1 : 0;
}

struct Keyword* isKeyword(char *c) {
    struct Keyword* character = (struct Keyword*) malloc(sizeof(struct Keyword)); 
    if(*c == 'i' || *c == 'f' || *c == 'p') {
        character->c = c;
        character->keyword = 1;

        return character;
    }
    character->c = c;
    character->keyword = 0;
    return character;
}

struct Keyword* isOperation(char *c) {
    struct Keyword* character = (struct Keyword*) malloc(sizeof(struct Keyword)); 
    if( *c == '+' || *c == '*' || *c == '-' || *c == '/') {
        character-> keyword = 1;
        if(*c == '+') {
            character->c = "plus";
        } else if(*c == '-') {
            character->c = "substraction";
        } else if(*c == '*') {
            character->c = "multiplication";
        } else {
            character->c = "division";
        }
        return character;
    }
    character->c = c;
    character->keyword = 0;
    return character;
}


int main(int arg, char *arv[]) {

    char fileName[strlen(arv[1]) + 1];
    strcpy(fileName, arv[1]);
    FILE *file = fopen(fileName, "r");
    int n = 0;
    char c;


    if( file == NULL) return 0;
    char line[100];
    int count = 0;

    while((c = (char)fgetc(file)) != EOF){
        if(c != '\n') {
            struct Keyword* character = (struct Keyword*) malloc(sizeof(struct Keyword));
            if(!isSpace(&c)) {
                line[count] = c;
                count = count + 1;
                character = isKeyword(&c);
                if(character->keyword) {
                    //printf("is keyword %c\n", *character->c);
                }
                //printf("%c", c);
            }
        } else {
            printf("%s\n", line);
            if(isAssing(line)) {
                printf("is an assignment %s\n", line);
            }
            memset(line, 0, 100 * sizeof(line[0]));
            count = 0;
        }
    }
    return 0;
}
