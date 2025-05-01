#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* data;
	int first;
	int last;
	int size;
}queue;

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} node;

typedef struct {
	node* first;
	node* last;
} deque;

typedef struct {
	char* data;
	int first;
	int last;
	int size;
} char_queue;

int inputInteger();

int inputIntegerInRange(const int min, const int max);

void initQueue(queue* q, int size);

int isEmpty(queue* q);

int isFull(queue* q);

void enqueue(queue* q, int value);

void dequeue(queue* q);

void printQueue(queue* q);

void outputSizeIfElementRepeat(queue* q, int value);

deque* initDeque();

void pushFirstElement(deque* d, int value);

void pushLastElement(deque* d, int value);

int popFirst(deque* d);

int popLast(deque* d);

void printDeque(deque* d);

void initCharQueue(char_queue* q, int size);

int isEmptyCharQueue(char_queue* q);

int isFullCharQueue(char_queue* q);

void enCharQueue(char_queue* q, int value);

char deCharQueue(char_queue* q);

void freeQueue(char_queue* q);

void loadFileToQueue(const char* filename, char_queue* q);

int comparingTwoFiles(char_queue* q1, char_queue* q2);

void chooseTask();