#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_tree()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    root->left = (struct node *)malloc(sizeof(struct node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct node *)malloc(sizeof(struct node));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    return root;
}

int main()
{

    return 0;
}