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


    printLinkedList(head);
    int n;
    printf_s("Input your N:\n");
    scanf_s("%d", &n);
    fromArray(&head, arr, 2 * n);
    int sum = 0;
    int temp = (n * 2) - 1;
    for (int i = 0; i < n * 2; i++) {
            int a = getNextVal(&head, i);
            int b = getNextVal(&head, temp);
            int res = a * b;
            sum += res;
            temp--;
    }
    printf_s("Sum =  %d \n", sum);
}
