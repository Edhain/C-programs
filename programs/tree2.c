#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct node {
    struct node *next;
    struct node *child;
    char *data;
};

// Function to print the tree recursively
void printtree_r(struct node *node, int depth) {
    int i;
    while (node) {
        if (node->child) {
            for (i = 0; i < depth * 3; i++) {
                printf(" ");
            }
            printf("{\n");
            printtree_r(node->child, depth + 1);
            for (i = 0; i < depth * 3; i++) {
                printf(" ");
            }
            printf("}\n");
        }
        for (i = 0; i < depth * 3; i++) {
            printf(" ");
        }
        printf("%s\n", node->data);
        node = node->next;
    }
}

// Function to print the tree from the root
void printtree(struct node *root) {
    printtree_r(root, 0);
}

// Function to create a new node
struct node *createnode(const char *data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node) {
        new_node->next = NULL;
        new_node->child = NULL;
        new_node->data = strdup(data); // Allocate and copy the string
    }
    return new_node;
}

// Function to free the allocated memory of the tree
void freetree(struct node *root) {
    if (root == NULL) {
        return;
    }
    freetree(root->child);
    freetree(root->next);
    free(root->data); // Free the string
    free(root); // Free the node
}

int main() {
    // Create the tree nodes
    struct node *root = createnode("root");
    struct node *child1 = createnode("child1");
    struct node *child2 = createnode("child2");
    struct node *child3 = createnode("child3");
    struct node *subchild1 = createnode("subchild1");

    // Construct the tree
    root->child = child1;
    child1->next = child2;
    child2->next = child3;
    child1->child = subchild1;

    // Print the tree
    printtree(root);

    // Free the allocated memory
    freetree(root);

    return 0;
}
