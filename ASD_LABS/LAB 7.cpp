#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void push(Node** head, int data) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}
Node* getNextHead(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}
void fromArray(Node** head, int* arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while (i-- != 0);
}

void deleteList(Node** head) {
    Node* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}
int size(Node* head) {
    int i = 0;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}

int getNextVal(Node** head, int n) {
    if (n == 0) {
        return 0;
    }
    else {
        Node* prev = getNextHead(*head, n - 1);
        Node* elm = prev->next;
        int val = elm->value;
        return val;
    }
}


void printLinkedList(const Node* head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void main() {
    Node* head = NULL;
    int arr[2000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }
    int n;
    printf_s("Input your N:\n");
    scanf_s("%d", &n);
    fromArray(&head, arr, 2 * n);
    printLinkedList(head);
    int sum = 0;
    int temp = size(head) - 1;
    printf_s("Size = ( %d )\n", size(head));
    for (int i = 0; i < size(head); i++) {
            int a = getNextVal(&head, i);
            int b = getNextVal(&head, temp);
            int res = a * b;
            sum += res;
            temp--;
    }
    deleteList(&head);
    printLinkedList(head);
    printf_s("Sum = ( %d )\n", sum);
}
