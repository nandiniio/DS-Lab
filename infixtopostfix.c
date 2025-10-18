#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define max 50
char stack[max];
int top = -1;

void push(char c){
    if(top== max-1){
        printf("stack overflow");
    }
    else{
        stack[++top] = c;
    }
}

int pop(){
    if(top == -1){
        printf("stack underflow");
    }
    else{
        return stack[top--];
    }
}

char peek(){
    if(top==-1){
        return -1;
    }
    else{
        return stack[top];
    }
}

int precedence(char op){
    switch(op){
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
            return 2;
        case '^' :
            return 3;
        case '(' :
            return 0;
    }
    return -1;
}

int associativity(char op){
    if(op == '^'){
        return 1;
    }
    return 0;
}

void infixtopostfix(char infix[], char postfix[]){
    int i,k=0;
    char c;

    for(i =0; infix[i] != 0;i++){
        c = infix[i];
        if(isdigit(c)){
            postfix[k++]=c;
        }
        else if(c == '('){
            push(c);
        }
        else if(c==')'){
            while(peek() != '('){
                postfix[k++] = pop();
            }
            pop();
        }
        else{
            while(top != -1 && ((precedence(peek()) > precedence(c)) || precedence(peek()) == precedence(c) && associativity(c) == 0)){
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while(top!= -1){
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main(){
    char infix[max], postfix[max];
    printf("enter a valid parenthesized infix expression : ");
    scanf("%s",infix);

    infixtopostfix(infix, postfix);

    printf(postfix);

    return 0;
}