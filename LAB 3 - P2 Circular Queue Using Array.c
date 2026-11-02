#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert()
{
    int item;

    if((front == 0 && rear == SIZE - 1) ||
       (front == rear + 1))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d", &item);

        if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if(rear == SIZE - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        queue[rear] = item;

        printf("Element inserted successfully\n");
    }
}

void delete()
{
    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if(front == SIZE - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are: ");

        if(front <= rear)
        {
            for(i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        else
        {
            for(i = front; i < SIZE; i++)
            {
                printf("%d ", queue[i]);
            }

            for(i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- CIRCULAR QUEUE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
