
#include <stdio.h>
#include <stdlib.h>

// Structure of doubly linked list
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Create and insert node at end
void create(int value) {
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node created successfully.\n");
}

// Insert a node to the left of specified value
void insertLeft(int key, int value) {
    struct node *temp, *newNode;

    temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Specified node not found!\n");
        return;
    }

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->prev = temp->prev;
    newNode->next = temp;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }

    temp->prev = newNode;

    printf("Node inserted successfully.\n");
}

// Delete node based on specific value
void deleteNode(int value) {
    struct node *temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Node deleted successfully.\n");
}

// Display the doubly linked list
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Doubly Linked List:\n");

    printf("NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice, value, key;

    while (1) {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Create a Node\n");
        printf("2. Insert Node to the Left\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                create(value);
                break;

            case 2:
                printf("Enter the specified node value: ");
                scanf("%d", &key);

                printf("Enter the new node value: ");
                scanf("%d", &value);

                insertLeft(key, value);
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
