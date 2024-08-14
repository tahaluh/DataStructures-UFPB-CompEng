#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *initList(int data)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    head->prev = NULL;
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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// insert a node at the end of the list
void unshift(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// remove the first node of the list
void shift(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    free(temp);
}

// insert a node at the end of the list
void push(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node *last = getLast(*head);
    last->next = newNode;
    newNode->prev = last;
}

// remove the last node of the list
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

    Node *last = getLast(*head);
    last->prev->next = NULL;
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

    pop(&head);
    printList(head);

    shift(&head);
    printList(head);

    return 0;
}
