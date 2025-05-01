#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int inputInteger() {
	int var;
	int c;
	while (1) {
		while (scanf_s("%d", &var) != 1) {
			printf("Incorrect input, try again: ");
			while ((c = getchar()) != '\n' && c != EOF);
		}
		if ((c = getchar()) != '\n' && c != EOF && c != ' ') {
			printf("Incorrect input, try again: ");
			while ((c = getchar()) != '\n' && c != EOF);
		}
		else {
			return var;
		}
	}
}

int inputIntegerInRange(const int min, const int max) {
	while (1) {
		const int number = inputInteger();
		if (number >= min && number <= max) {
			return number;
		}
		printf("The number must be between %d and %d.\n", min, max);
	}
}

void initQueue(queue* q, int size) {
	q->data = malloc(size * sizeof(int));
	q->first = -1;
	q->last = -1;
	q->size = size;
}

int isEmpty(queue* q) {
	return q->first == -1;
}

int isFull(queue* q) {
	return ((q->last + 1) % q->size) == q->first;
}

void enqueue(queue* q, int value) {
	if (isFull(q)) {
		puts("Queue is full!");
		return;
	}
	if (isEmpty(q)) {
		q->first = 0;
		q->last = 0;
	}
	else {
		q->last = (q->last + 1) % q->size;
		}
	q->data[q->last] = value;
}

void dequeue(queue* q) {
	if (isEmpty(q)) {
		puts("Queue is empty!");
		return;
	}
	int value = q->data[q->first];
	if (q->first == q->last) {
		q->first = q->last = -1;
	}
	else {
		q->first = (q->first + 1) % q->size;
	}
}

void printQueue(queue* q) {
	if (isEmpty(q)) {
		puts("Queue is empty!");
		return;
	}
	puts("Your elements:\n");
	int i = q->first;
	while (1) {
		printf(" %d ", q->data[i]);
		if (i == q->last) {
			break;
		 }
		else {
			i = (i + 1) % q->size;
		}
	}
}

void outputSizeIfElementRepeat(queue* q, int value) {
	if (q->data[q->last] == value) {
		int current_size;
		if (q->last >= q->first)
			current_size = q->last - q->first + 1;
		else
			current_size = q->size - q->first + q->last + 1;
		printf("\nCurrent size of queue is %d\n", current_size);
	}
}

deque* initDeque() {
	deque* d = malloc(sizeof(deque));
	d->first = d->last = NULL;
	return d;
}

void pushFirstElement(deque* d, int value) {
	node* node = malloc(sizeof(node));
	node->data = value;
	node->prev = NULL;
	node->next = d->first;

	if (d->first == NULL) {
		d->last = node;
	}
	else {
		d->first->prev = node;
	}
	d->first = node;
}

void pushLastElement(deque* d, int value) {
	node* node = malloc(sizeof(node));
	node->data = value;
	node->next = NULL;
	node->prev = d->last;

	if (d->last == NULL) {
		d->first = node;
	}
	else {
		d->last->next = node;
	}
	d->last = node;
}

int popFirst(deque* d) {
	if (d->first == NULL) {
		printf("Deque is empty\n");
		return -1;
	}
	node* temp = d->first;
	int value = temp->data;

	d->first = d->first->next;
	if (d->first) {
		d->first->prev = NULL;
	}
	else {
		d->last = NULL;
	}
	free(temp);
	return value;
}

int popLast(deque* d) {
	if (d->last == NULL) {
		printf("Deque is empty\n");
		return -1;
	}
	node* temp = d->last;
	int value = temp->data;

	d->last = d->last->next;
	if (d->last) {
		d->last->prev = NULL;
	}
	else {
		d->first = NULL;
	}
	free(temp);
	return value;
}

void printDeque(deque* d) {
	node* current = d->first;
	puts("Deque from first in tot last:\n");
	while (current != NULL) {
		printf(" %d ", current->data);
		current = current->next;
	}
}

void initCharQueue(char_queue* q, int size) {
	q->data = malloc(sizeof(char) * size);
	q->first = -1;
	q->last = -1;
	q->size = size;
}

int isEmptyCharQueue(char_queue* q) {
	return q->first == -1;
}

int isFullCharQueue(char_queue* q) {
	return ((q->last + 1) % q->size) == q->first;
}

void enCharQueue(char_queue* q, int value) {
	if (isFullCharQueue(q)) {
		puts("Queue is full!");
		exit(1);
	}
	if (isEmptyCharQueue(q)) {
		q->first = 0;
		q->last = 0;
	}
	else {
		q->last = (q->last + 1) % q->size;
	}
	q->data[q->last] = value;
}

char deCharQueue(char_queue* q) {
	if (isEmptyCharQueue(q)) {
		puts("Queue is empty!");
		return;
	}
	char value = q->data[q->first];
	if (q->first == q->last) {
		q->first = q->last = -1;
	}
	else {
		q->first = (q->first + 1) % q->size;
	}
	return value;
}

void freeQueue(char_queue* q) {
	free(q->data);
}

void loadFileToQueue(const char* filename, char_queue* q) {
	FILE* file = fopen(filename, "r");
	if (!file) {
		puts("Error!");
		exit(1);
	}
	char symbols;
	while ((symbols = fgetc(file)) != EOF) {
		enCharQueue(q, symbols);
	}
	fclose(file);
}

int comparingTwoFiles(char_queue* q1, char_queue* q2) {
	while (!isEmptyCharQueue(q1) && !isEmptyCharQueue(q2)) {
		char symbol_from_first_file = deCharQueue(q1);
		char symbol_from_second_file = deCharQueue(q2);
		if (symbol_from_first_file != symbol_from_second_file)
			return 0;
	}
	return isEmptyCharQueue(q1) && isEmptyCharQueue(q2);
}

void chooseTask() {
	while (1) {
		puts("\nEnter number of task");
		int choice = inputIntegerInRange(1, 4);
		if (choice == 1) {
			queue queue;
			puts("Enter size of queue:");
			int size_of_queue = inputIntegerInRange(1, 10);
			initQueue(&queue, size_of_queue);
			for (int count = 0; count < size_of_queue; count++) {
				printf("Enter %d element: ", count + 1);
				int value = inputIntegerInRange(0, 100);
				outputSizeIfElementRepeat(&queue, value);
				enqueue(&queue, value);
			}
			printQueue(&queue);
		}
		if (choice == 2) {
			deque* deque = initDeque();

			puts("Enter size of deque:");
			int size_of_deque = inputIntegerInRange(1, 10);

			int count = 0;
			while (count < size_of_deque) {
				printf("Enter %d element: ", count + 1);
				int value = inputIntegerInRange(0, 100);
				puts("Where do you want to add element (F/f (add to top) or L/l (add to the end)");
				char choosing_add_element;
				scanf_s("%c", &choosing_add_element);
				if (choosing_add_element == 'F' || choosing_add_element == 'f') {
					pushFirstElement(deque, value);
					if (deque->last->data == value) {
						printf("Current size of deque %d\n", count+1);
					}
				}
				else if (choosing_add_element == 'L' || choosing_add_element == 'l') {
					pushLastElement(deque, value);
					if (deque->first->data == value) {
						printf("Current size of deque %d\n", count + 1);
					}
				}
				else {
					puts("Incorrect input, try again");
					continue;
				}
				count++;
			}
			printDeque(deque);
		}
		if (choice == 3) {
			char_queue first_queue;
			char_queue second_queue;
			initCharQueue(&first_queue, 100);
			initCharQueue(&second_queue, 100);

			loadFileToQueue("first_queue.txt", &first_queue);
			loadFileToQueue("second_queue.txt", &second_queue);
			
			if (comparingTwoFiles(&first_queue, &second_queue)) {
				puts("Files are the same!");
			}
			else {
				puts("File are NOT the same!");
			}
		}
		if (choice == 4) {
			return 1;
		}
	}
}