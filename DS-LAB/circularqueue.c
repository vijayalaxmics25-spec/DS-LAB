#include <stdio.h>
#define MAX 5   // size of circular queue

int cq[MAX];
int front = -1, rear = -1;

// Insert operation
void insert() {
    int item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow! Circular Queue is full.\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &item);

        if (front == -1) {   // first insertion
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        cq[rear] = item;
        printf("Element %d inserted.\n", item);
    }
}

// Delete operation
void delete() {
    if (front == -1) {
        printf("Queue is Empty! Cannot delete element.\n");
    } else {
        printf("Deleted element: %d\n", cq[front]);

        if (front == rear) {   // only one element
            front = -1;
            rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

// Display operation
void display() {
    int i;
    if (front == -1) {
        printf("Queue is Empty.\n");
    } else {
        printf("Circular Queue elements are:\n");
        i = front;
        while (i != rear) {
            printf("%d ", cq[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", cq[rear]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
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
