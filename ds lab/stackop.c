#include <stdio.h>//stack operations
#define MAX 5

int stack [MAX];
int top = -1;

//push
void push (int value) {
    if (top==MAX-1) {
        printf("stack overflow\n");
    }


else {
    top ++;
    stack [top] = value;
    printf("pushed %d\n", value);
}
}

//pop
void pop () {
    if (top==-1) {
        printf("stack underflow\n");
    }
    else {
        printf("popped %d\n", stack [top]);
        top --;
    }
}

//display
void display () {
    if (top==-1){
        printf("stack is empty\n");
    }
    else {
        printf("stack elements are:\n");
        for (int i=top; i>=0; i--) {
            printf("%d\n", stack [i]);
        }
    }
}

int main () {
    push (10);
    push (20);
    push (30);
    push (40);
    push (50);
    push (60); // this will cause stack overflow

    display ();

    pop ();
    pop ();
    pop ();
    pop ();
    pop ();
    pop (); // this will cause stack underflow
    display ();

    return 0;
}