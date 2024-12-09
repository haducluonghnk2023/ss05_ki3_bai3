#include<stdio.h>
#include<stdlib.h>

// Ð?nh ngh?a Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteLast(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong co gi de xoa.\n");
        return;
    }

    Node* temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf(" <--> %d", temp->data);
        temp = temp->next;
    }
    printf(" <--> NULL\n");
}

int main() {
    Node* head = NULL;
    int n, value;

    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sach ban dau: ");
    printList(head);

    printf("Xoa phan tu cuoi danh sach.\n");
    deleteLast(&head);

    printf("Danh sach sau khi xoa: ");
    printList(head);

    return 0;
}

