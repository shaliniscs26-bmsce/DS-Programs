
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

// Create a new node
struct node* createNode(int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
struct node* insertBeginning(struct node *head, int value) {
    struct node *newNode = createNode(value);

    newNode->next = head;
    return newNode;
}

// Insert at end
struct node* insertEnd(struct node *head, int value) {
    struct node *newNode = createNode(value);
    struct node *temp = head;

    if (head == NULL)
        return newNode;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete a node
struct node* deleteNode(struct node *head, int value) {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    if (head->data == value) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return head;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found!\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted successfully.\n");
    return head;
}

// Display linked list
void display(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Sort linked list
void sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List sorted successfully.\n");
}

// Reverse linked list
struct node* reverseList(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    printf("List reversed successfully.\n");
    return prev;
}

// Concatenate two lists
struct node* concatenate(struct node *head1,
                         struct node *head2) {
    struct node *temp = head1;

    if (head1 == NULL)
        return head2;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display First List\n");
        printf("5. Sort the First List\n");
        printf("6. Reverse the First List\n");
        printf("7. Create Second List\n");
        printf("8. Display Second List\n");
        printf("9. Concatenate Two Lists\n");
        printf("10. Display Concatenated List\n");
        printf("11. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head1 = insertBeginning(head1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head1 = insertEnd(head1, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head1 = deleteNode(head1, value);
                break;

            case 4:
                printf("First Linked List: ");
                display(head1);
                break;

            case 5:
                sortList(head1);
                break;

            case 6:
                head1 = reverseList(head1);
                break;

            case 7:
                printf("Enter value for second list (-1 to stop):\n");

                while (1) {
                    scanf("%d", &value);

                    if (value == -1)
                        break;

                    head2 = insertEnd(head2, value);
                }
                break;

            case 8:
                printf("Second Linked List: ");
                display(head2);
                break;

            case 9:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                printf("Lists concatenated successfully.\n");
                break;

            case 10:
                printf("Concatenated Linked List: ");
                display(head1);
                break;

            case 11:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
