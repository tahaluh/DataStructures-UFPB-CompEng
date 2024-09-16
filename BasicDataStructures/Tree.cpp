#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
} Node;

Node *createNode(int data, Node *left, Node *right)
{
    Node *tree = (Node *)malloc(sizeof(Node));
    tree->data = data;
    tree->left = left ? left : NULL;
    tree->right = right ? right : NULL;
    return tree;
}

int getNodeHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftHeight = getNodeHeight(node->left);
    int rightHeight = getNodeHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d\n", root->data);

    printTree(root->left);
    printTree(root->right);
}

void fillArray(Node *node, char **arr, int row, int col)
{
    if (node == NULL)
    {
        return;
    }

    arr[row][col] = (char)(node->data + '0');
    printf("arr[%d][%d] = %c\n", row, col, arr[row][col]);

    fillArray(node->left, arr, row + 1, col / 2);
    fillArray(node->right, arr, row + 1, col + col / 2);
}

void printTreeV2(Node *root)
{
    // 2^h - 1
    int height = getNodeHeight(root);
    int width = (1 << height) - 1;

    // Initialize the array with spaces
    char **arr = (char **)malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++)
    {
        arr[i] = (char *)malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++)
        {
            arr[i][j] = ' ';
        }
    }

    // Fill the array
    fillArray(root, arr, 0, (width - 1) / 2);

    // Print the array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Node *tree = createNode(4, NULL, NULL);

    Node *left = createNode(2, NULL, NULL);
    tree->left = left;

    Node *right = createNode(6, NULL, NULL);
    tree->right = right;

    Node *left_left = createNode(1, NULL, NULL);
    tree->left->left = left_left;

    Node *left_right = createNode(3, NULL, NULL);
    tree->left->right = left_right;

    Node *left_right_right = createNode(9, NULL, NULL);
    tree->left->right->right = left_right_right;

    printTreeV2(tree);

    return 0;
}
