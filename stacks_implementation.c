#include <stdio.h>
#define N 5
int stack[N];
int top = -1;

void push(){
    int x;
    if(top == N-1){
        printf("Stack Overflow\n");
    }
    else {
        printf("Enter data: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
    }
    else{
        int item = stack[top];
        top--;
        printf("Popped element: %d\n", item);
    }
}

void peek(){
    if(top == -1){
        printf("Stack is empty.\n");
    }
    else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = top; i >= 0; i--){
        printf("%d \n", stack[i]);
    }
    printf("\n");
}

int main(){
    char ch = '\0';
    printf("Choices are:\n a - push()\n b - pop()\n c - peek()\n d - display\n e - exit\n");
    while(ch != 'e'){
        printf("Enter a choice: ");
        scanf(" %c", &ch);

        switch (ch){
            case 'a' : push(); break;
            case 'b' : pop(); break;
            case 'c' : peek(); break;
            case 'd' : display(); break;
            case 'e' : break;
            default : printf("Enter valid choice!!\n");
        }
    }
    return 0;
}
