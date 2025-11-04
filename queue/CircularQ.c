#include<stdio.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
        printf("number added. index: %d\n", rear);
    }
    else if((rear + 1) % N == front){
        printf("Queue is full.\n");
    }
    else{
        rear = (rear + 1) % N;
        queue[rear] = x;
        printf("number added. index: %d\n", rear);
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty.\n");
    }
    else if(front == rear){
        printf("deleted element: %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("deleted element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is empty.\n");
    }
    else{
        printf("Front element: %d\n", queue[front]);
    }
}

// void display(){
//     if(front == -1 && rear == -1){
//         printf("Queue is empty.\n");
//     }
//     else{
//         int i = front;
//         printf("Queue elements:\n");
//         for(int i = front ; i = (i + 1)%N){
//             printf("%d ", queue[i]);
//         }
//         printf("\n");
//     }
// }

void display() {
    if(front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue elements:\n");
        for(int i = front; ; i = (i + 1) % N) {
            printf("%d ", queue[i]);
            if(i == rear) break;   // stop when we printed the last element
        }
        printf("\n");
    }
}

int main(){
    char ch;
    int x;
    printf("choices are : a-enqueue, b-dequeue, c-peek, d-display, e-exit.\n");

    while(ch != 'e'){
        printf("enter a choice : ");
        scanf(" %c", &ch);

        switch(ch){
            case 'a':
                printf("enter number to be added : ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 'b':
                dequeue();
                break;

            case 'c':
                peek();
                break;

            case 'd':
                display();
                break;

            case 'e':
                printf("exiting...\n");
                break;
        }
    }
    return 0;
}
