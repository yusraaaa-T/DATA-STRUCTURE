#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* yeniNode(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void basaEkle(int data) {
    struct Node *n = yeniNode(data);
    if (head != NULL) {
        n->next = head;
        head->prev = n;
    }
    head = n;
}

void sonaEkle(int data) {
    struct Node *n = yeniNode(data);
    if (head == NULL) {
        head = n;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void arayaEkle(int onceki, int data) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != onceki)
        temp = temp->next;

    if (temp == NULL)
        return;

    struct Node *n = yeniNode(data);
    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}

void sil(int data) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != data)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

struct Node* ara(int data) {
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void ileriYazdir() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void geriYazdir() {
    struct Node *temp = head;
    if (temp == NULL) return;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    basaEkle(10);
    basaEkle(5);
    sonaEkle(20);
    sonaEkle(30);
    arayaEkle(20, 25);

    ileriYazdir();
    geriYazdir();

    sil(5);
    ileriYazdir();

    if (ara(25) != NULL)
        printf("25 bulundu\n");
    else
        printf("25 bulunamadi\n");

    return 0;
}

