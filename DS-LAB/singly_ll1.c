#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Create linked list */
void create() {
    int n, i, value;
    struct node *temp, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

/* Delete first node */
void delete_first() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
    } else {
        temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

/* Delete last node */
void delete_last() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
    } else if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

/* Delete specified element */
void delete_specific() {
    int key;
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    if (head->data == key) {
        delete_first();
        return;
    }

    temp = head;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list.\n");
    } else {
        prev->next = temp->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

/* Display linked list */
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("Linked list is empty.\n");
    } else {
        printf("Linked list contents:\n");
        temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: delete_first(); break;
            case 3: delete_specific(); break;
            case 4: delete_last(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
