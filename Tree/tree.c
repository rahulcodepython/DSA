#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *add_node(struct tree *root, int value)
{
    struct tree *new_tree_node = (struct tree *)malloc(sizeof(struct tree));
    if (root == NULL)
    {
        new_tree_node->data = value;
        new_tree_node->left = NULL;
        new_tree_node->right = NULL;
        return new_tree_node;
    }
    else
    {
        if (value < root->data)
        {
            root->left = add_node(root->left, value);
        }
        else
        {
            root->right = add_node(root->right, value);
        }
    }
    return root;
}

struct tree *create_tree(struct tree *root)
{
    int data;

    while (true)
    {
        printf("Enter the data of the node: ");
        scanf("%d", &data);
        if (data < 0)
        {
            break;
        }
        root = add_node(root, data);
    }
    return root;
}

void print_tree_preorder(struct tree *t)
{
    if (t != NULL)
    {
        printf("%d  ", t->data);
        print_tree_preorder(t->left);
        print_tree_preorder(t->right);
    }
}

void print_tree_inorder(struct tree *t)
{
    if (t != NULL)
    {
        print_tree_preorder(t->left);
        printf("%d  ", t->data);
        print_tree_preorder(t->right);
    }
}

void print_tree_postorder(struct tree *t)
{
    if (t != NULL)
    {
        print_tree_preorder(t->left);
        print_tree_preorder(t->right);
        printf("%d  ", t->data);
    }
}

int main()
{
    struct tree *root = NULL;
    root = create_tree(root);
    print_tree_preorder(root);
    printf("\n");
    print_tree_inorder(root);
    printf("\n");
    print_tree_postorder(root);
    return 0;
}