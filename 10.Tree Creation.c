#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

struct Node* createTree(int arr[], int i, int n) {
    if (i >= n)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = createTree(arr, 2*i + 1, n);
    root->right = createTree(arr, 2*i + 2, n);

    return root;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
	int i;
    printf("Eleman sayisi: ");
    scanf("%d", &n);

    int arr[n];
    printf("Array elemanlarini girin:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = createTree(arr, 0, n);

    printf("\nInorder  : ");
    inorder(root);

    printf("\nPreorder : ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}

