
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Stack variables
struct node *top = NULL;

// Queue variables
struct node *front = NULL;
struct node *rear = NULL;

// PUSH operation
void push(int value) {
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Element pushed successfully\n");
}

// POP operation
void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

// Display Stack
void displayStack() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// ENQUEUE operation
void enqueue(int value) {
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Element inserted successfully\n");
}

// DEQUEUE operation
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Display Queue
void displayQueue() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                while (1) {
                    printf("\n--- STACK MENU ---\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");

                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            push(value);
                            break;

                        case 2:
                            pop();
                            break;

                        case 3:
                            displayStack();
                            break;

                        case 4:
                            goto mainmenu;

                        default:
                            printf("Invalid choice\n");
                    }
                }

            case 2:
                while (1) {
                    printf("\n--- QUEUE MENU ---\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");

                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            enqueue(value);
                            break;

                        case 2:
                            dequeue();
                            break;

                        case 3:
                            displayQueue();
                            break;

                        case 4:
                            goto mainmenu;

                        default:
                            printf("Invalid choice\n");
                    }
                }

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }

        mainmenu:
        ;
    }

    return 0;
}
