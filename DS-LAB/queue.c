#include <stdio.h>
#define MAX 5   // maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Insert operation
void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert element.\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("Element %d inserted into queue.\n", item);
    }
}

// Delete operation
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty! Cannot delete element.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

// Display operation
void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is Empty.\n");
    } else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
