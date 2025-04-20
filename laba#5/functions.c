#include <stdio.h>
#include <stdlib.h>


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


typedef struct tag_obj {
    int data;
    struct tag_obj* next;
} OBJ;

OBJ* push(OBJ* top, int data) {
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

void show(const OBJ* top) {
    const OBJ* current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

OBJ* fillStack() {
    OBJ* top = NULL;
    int i = 0;
    puts("Enter size of stack:");
    int size = inputIntegerInRange(1, 10);

    while (i < size) {
        printf("Enter %d element: ", i + 1);
        int number = inputIntegerInRange(0, 20);
        top = push(top, number);
        ++i;
    }
    return top;
}

void findMaxElement(const OBJ* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    int max = top->data;
    const OBJ* current = top->next;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    printf("Max element in stack is %d\n", max);
}

void freeStack(OBJ* top) {
    while (top != NULL) {
        OBJ* temp = top;
        top = top->next;
        free(temp);
    }
}

void outputLargestElement() {
    OBJ* top = fillStack();
    printf("\nYour stack is:\n");
    show(top);
    printf("\n");
    findMaxElement(top);
    freeStack(top);
}


OBJ* fillStackDecreasing() {
    OBJ* top = NULL;
    int i = 0;
    puts("Enter size of stack:");
    int size = inputIntegerInRange(1, 10);

    int previous = 21;

    while (i < size) {
        printf("Enter %d element (less than previous): ", i + 1);
        int number = inputIntegerInRange(0, 20);

        if (number >= previous) {
            printf("Each number must be less than the previous one (%d). Try again.\n", previous);
            continue;
        }

        top = push(top, number);
        previous = number;
        ++i;
    }

    return top;
}


OBJ* mergeStacksToAscending(OBJ* stack1, OBJ* stack2) {
    OBJ* third = NULL;

    while (stack1 != NULL && stack2 != NULL) {
        if (stack1->data < stack2->data) {
            third = push(third, stack1->data);
            stack1 = stack1->next;
        }
        else {
            third = push(third, stack2->data);
            stack2 = stack2->next;
        }
    }

    while (stack1 != NULL) {
        third = push(third, stack1->data);
        stack1 = stack1->next;
    }

    while (stack2 != NULL) {
        third = push(third, stack2->data);
        stack2 = stack2->next;
    }

    return third;
}


OBJ* force(OBJ* third) {
    OBJ* force = NULL;
    
    while (third != NULL) {
        force = push(force, third->data);
        third = third->next;
    }
    return force;
}


void formationOfThirdStack() {
    OBJ* first_stack = fillStackDecreasing();
    printf("\nYour first stack (in decreasing order):\n");
    show(first_stack);

    OBJ* second_stack = fillStackDecreasing();
    printf("\nYour second stack (in decreasing order):\n");
    show(second_stack);

    OBJ* third_stack = mergeStacksToAscending(first_stack, second_stack);

    printf("\nThird stack (merged in increasing order):\n");

    OBJ* forcebuy = force(third_stack);
    show(forcebuy);

    freeStack(first_stack);
    freeStack(second_stack);
    freeStack(third_stack);
    freeStack(forcebuy);
}


void chooseTask() {
    puts("Choose number of task (1-2) or exit (3):");
    int choice = inputInteger();

    if (choice == 1) {
        outputLargestElement();
    }
    else if (choice == 2) {
        formationOfThirdStack();
    }
    else {
        exit(1);
    }
}