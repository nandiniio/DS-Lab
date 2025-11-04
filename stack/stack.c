#include<stdio.h>

#define max 10
int stack[max];
int top = -1;

void push(){
    int x;
    printf("enter a number : ");
    scanf("%d", &x);

    if(top==max-1){
        printf("stack overflow!");
    }
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    int x;
    if(top==-1){
        printf("stack underflow!");
    }
    else{
        x = stack[top];
        printf("deleted element : %d", x);
        top--;
    }
}

void peek(){
    if(top==-1){
        printf("stack is empty!");
    }
    else{
        printf("top element : %d\n", stack[top]);
    }
}

void display(){
    if(top==-1){
        printf("stack is empty!");
    }
    else{
        for(int i=0;i<=top;i++){
        printf("%d ", stack[i]);
    }
    }
}

int main(){
    char ch;

    printf(" Choices are : a - push\n b - pop\n c - peek\n d - display\n e - exit.\n");

    printf("enter a choice (a/b/c/d/e) : ");
    scanf(" %c", &ch);

    while(ch != 'e'){
        switch(ch){
            case 'a' : push();
            break;
            case 'b' : pop();
            break;
            case 'c' : peek();
            break;
            case 'd' : display();
            break;
            default : printf("invalid choice!");
            break;
        }
        printf("\nEnter your choice: ");
        scanf(" %c", &ch);
    }
    printf("bye bye!");
    return 0;
}

