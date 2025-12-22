#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* Function to create a linked list */
struct node* create() {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
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
    return head;
}

/* Display linked list */
void display(struct node *head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Sort linked list (Bubble sort) */
void sort(struct node *head) {
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
    printf("Linked list sorted.\n");
}

/* Reverse linked list */
struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printf("Linked list reversed.\n");
    return prev;
}

/* Concatenate two linked lists */
struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp = head1;

    if (head1 == NULL)
        return head2;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    printf("Linked lists concatenated.\n");
    return head1;
}

int main() {
    struct node *list1 = NULL, *list2 = NULL;
    int choice;

    while (1) {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List 1 and List 2\n");
        printf("6. Display List 1\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: list1 = create(); break;
            case 2: list2 = create(); break;
            case 3: sort(list1); break;
            case 4: list1 = reverse(list1); break;
            case 5: list1 = concatenate(list1, list2); break;
            case 6: display(list1); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
