#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("Liste bos\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}


struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;

    return head;
}

void insertAfter(struct Node* head, int key, int newData) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = newData;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Eleman bulunamadi\n");
}


struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) return NULL;

    struct Node *curr = head, *prev = NULL;

    /* Tek dugumlu liste */
    if (head->data == key && head->next == head) {
        free(head);
        return NULL;
    }

 
    if (head->data == key) {
        while (curr->next != head)
            curr = curr->next;

        curr->next = head->next;
        free(head);
        return curr->next;
    }

  
    prev = head;
    curr = head->next;

    while (curr != head) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Eleman bulunamadi\n");
    return head;
}


int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printf("Ilk liste:\n");
    traverse(head);

 
    insertAfter(head, 20, 25);
    printf("\n20'den sonra 25 eklendi:\n");
    traverse(head);

  
    head = deleteNode(head, 10);
    printf("\n10 silindi:\n");
    traverse(head);

    return 0;
}
