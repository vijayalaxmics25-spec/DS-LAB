#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

/* Initialize hash table */
void init() {
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}

/* Hash function: H(K) = K mod m */
int hashFunction(int key) {
    return key % m;
}

/* Insert key using Linear Probing */
void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % m;

        if (index == startIndex) {
            printf("Hash Table Overflow! Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Key %d inserted at address %d\n", key, index);
}

/* Display hash table */
void display() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == -1)
            printf("Address %d : EMPTY\n", i);
        else
            printf("Address %d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;

    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);

    init();

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
