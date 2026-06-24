// Program 6: Implement queue operations using arrays and linked lists

// --- Queue using Array ---
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if(rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted\n", value);
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted\n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if(front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue Elements:\n");
        for(i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main1() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}

// --- Queue using Linked List ---
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *ll_front = NULL;
struct Node *ll_rear = NULL;

void enqueueLL(int value) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(ll_rear == NULL) {
        ll_front = ll_rear = newNode;
    } else {
        ll_rear->next = newNode;
        ll_rear = newNode;
    }
    printf("%d inserted\n", value);
}

void dequeueLL() {
    struct Node *temp;
    if(ll_front == NULL) {
        printf("Queue Underflow\n");
    } else {
        temp = ll_front;
        printf("%d deleted\n", ll_front->data);
        ll_front = ll_front->next;
        if(ll_front == NULL)
            ll_rear = NULL;
        free(temp);
    }
}

void displayLL() {
    struct Node *temp;
    if(ll_front == NULL) {
        printf("Queue is Empty\n");
    } else {
        temp = ll_front;
        printf("Queue Elements:\n");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    enqueueLL(10);
    enqueueLL(20);
    enqueueLL(30);
    displayLL();
    dequeueLL();
    displayLL();
    return 0;
}
