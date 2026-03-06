// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// Push
void push(int x) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

// Pop
int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct node* temp = top;
    int value = temp->data;
    top = temp->next;
    free(temp);

    return value;
}

// Evaluate postfix
int evaluate(char exp[]) {
    int i = 0;

    while(exp[i] != '\0') {

        if(isdigit(exp[i])) {
            push(exp[i] - '0');   // convert char to int
        }

        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/') {

            int op2 = pop();
            int op1 = pop();
            int result;

            switch(exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main() {

    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluate(exp);

    printf("Result = %d\n", result);

    return 0;
}