#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* NodePtr;

NodePtr createNode(int item) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    newNode->info = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NodePtr insert(int item, NodePtr root) {
    if (root == NULL) {
        return createNode(item);
    }
    if (item < root->info) {
        root->left = insert(item, root->left);
    } else {
        root->right = insert(item, root->right);
    }
    return root;
}

void preorder(NodePtr root) {
    if (root == NULL) return;
    printf("%d ", root->info);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NodePtr root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->info);
}

void inorder(NodePtr root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->info);
    inorder(root->right);
}

NodePtr search(int item, NodePtr root) {
    if (root == NULL || root->info == item) return root;
    if (item < root->info) return search(item, root->left);
    return search(item, root->right);
}

void main() {
    NodePtr root = NULL;
    int choice, item;
    for (;;) {
        printf("1. Insert\n2. Preorder\n3. Postorder\n4. Inorder\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                root = insert(item, root);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the item to be searched: ");
                scanf("%d", &item);
                if (search(item, root) != NULL)
                    printf("Item found\n");
                else
                    printf("Item not found\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
