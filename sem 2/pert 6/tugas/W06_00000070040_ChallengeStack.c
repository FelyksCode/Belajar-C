#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

// initialize stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// check if stack is full
bool isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// check if stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// push an element to the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack is full\n");
    } else {
        stack->top++;
        stack->items[stack->top] = item;
    }
}

// pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return '\0';
    } else {
        char removedItem = stack->items[stack->top];
        stack->top--;
        return removedItem;
    }
}

// check if opening and closing brackets match
bool isMatchingPair(char openingBracket, char closingBracket) {
    if (openingBracket == '(' && closingBracket == ')') {
        return true;
    } else if (openingBracket == '{' && closingBracket == '}') {
        return true;
    } else if (openingBracket == '[' && closingBracket == ']') {
        return true;
    } else {
        return false;
    }
}

// check if pola is balanced
bool isBalanced(char pola[]) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; i < strlen(pola); i++) {
        if (pola[i] == '(' || pola[i] == '{' || pola[i] == '[') {
            push(&stack, pola[i]);
        } else if (pola[i] == ')' || pola[i] == '}' || pola[i] == ']') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), pola[i])) {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char inputkurung[MAX_SIZE];
    printf("Enter Pola: ");
    fgets(inputkurung, MAX_SIZE, stdin);
    inputkurung[strcspn(inputkurung, "\n")] = '\0';

    if (isBalanced(inputkurung)) {
        printf("Pola is balanced\n");
    } else {
        printf("Pola is not balanced\n");
    }

    return 0;
}
