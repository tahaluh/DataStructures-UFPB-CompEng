#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *initList(int data)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    return head;
}

Node *getLast(Node *node)
{
    while (node->next != NULL)
    {
        node = node->next;
    }
    return node;
}

Node *getByIndex(Node *node, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (node == NULL)
        {
            return NULL;
        }
        node = node->next;
    }
    return node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Insert a node at the beginning of the list
void unshift(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Remove the first node of the list
void shift(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Insert a node at the end of the list
void push(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *last = getLast(*head);
    last->next = newNode;
}

// Remove the last node of the list
void pop(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *prev = NULL;
    Node *last = *head;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
}

int main()
{
    Node *head = initList(2);

    unshift(&head, 10);
    printList(head);

    unshift(&head, 20);
    printList(head);

    push(&head, 30);
    printList(head);

    Node *temp = getByIndex(head, 1);
    std::cout << temp->data << std::endl;

    pop(&head);
    printList(head);

    shift(&head);
    printList(head);

    return 0;
}
