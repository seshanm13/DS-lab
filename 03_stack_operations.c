// Program 3: Implement stack operations using arrays and linked lists

// --- Stack using Array ---
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = value;
        printf("Pushed %d\n", value);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else {
        printf("Popped %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main1() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}

// --- Stack using Linked List ---
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* ll_top = NULL;

void pushLL(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow (Memory not available)\n");
        return;
    }
    newNode->data = value;
    newNode->next = ll_top;
    ll_top = newNode;
    printf("%d pushed to stack\n", value);
}

void popLL() {
    if (ll_top == NULL) {
        printf("Stack Underflow (Empty stack)\n");
        return;
    }
    struct Node* temp = ll_top;
    printf("%d popped from stack\n", ll_top->data);
    ll_top = ll_top->next;
    free(temp);
}

void peek() {
    if (ll_top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", ll_top->data);
    }
}

void displayLL() {
    if (ll_top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = ll_top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                pushLL(value);
                break;
            case 2:
                popLL();
                break;
            case 3:
                peek();
                break;
            case 4:
                displayLL();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
