#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};
struct Node*createNode(int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertionAtBeginning(struct Node**head,int data){
    struct Node*newNode=createNode(data);
    newNode->next=*head;
    *head=newNode;
}
void insertionAtEnd(struct Node**head,int data){
    struct Node*newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node*temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertionAtPosition(struct Node **head, int data, int position){
    struct Node*newNode=createNode(data);
    if(position==0){
        newNode->next=*head;
        *head=newNode;
        return;
    }
    struct Node *temp =*head;
    for (int i=0;i<position-1 && temp !=NULL;i++){
        temp=temp->next;
    }
    if (temp==NULL){
        printf("position out of range\n");
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;

}
void deletionAtBeginning(struct Node**head){
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deletionAtEnd(struct Node**head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
 
void deletionAtPosition(struct Node** head, int position) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    if (position == 0) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("position out of range\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
 void traverse(struct Node*head){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
 }

 int search(struct Node*head,int target){
    struct Node*temp=head;
    while (temp!=NULL){
        if (temp->data==target)return 1;
        temp =temp->next;
 }
 return 0;
}

int main(){
    struct Node*head=NULL;
    insertionAtEnd(&head,10);
    insertionAtEnd(&head,20);
    insertionAtEnd(&head,30);
    traverse(head);

    insertionAtBeginning(&head,5);
    traverse(head);

    insertionAtPosition(&head, 25, 2);
    traverse(head);

    deletionAtBeginning(&head);
    traverse(head);

    deletionAtEnd(&head);
    traverse(head);

    deletionAtPosition(&head, 1);
    traverse(head);

    printf("list contains 20: %s\n", search(head, 20) ? "yes" : "no");

    return 0;
}
