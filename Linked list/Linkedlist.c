#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL; 

void createList(int n) {
    struct Node *newnode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Enter a valid number of nodes.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("Linked list created successfully!\n");
}

void insertAtBeginning() {
    struct Node *newnode;
    int data;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = head;
    head = newnode;

    printf("Node inserted at the beginning.\n");
}

void insertAtEnd(int data) {
    struct Node *newnode, *temp;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("Node inserted at the end.\n");
}

void insertAtPosition(int data, int pos) {
    struct Node *newnode, *temp = head;
    int i;

    if (pos < 1) {
        printf("Enter valid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning();
        return;
    }

    newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = data;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, data, pos;

    printf("\n LINKED LIST OPERATIONS : \n");
    printf("1. Create List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert at Position\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                insertAtBeginning();
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 4:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(data, pos);
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
