#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList
{
    Node *head;
    Node *tail;
} DoublyLinkedList;

DoublyLinkedList *initList()
{
    DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    *list = {NULL, NULL};
    return list;
}

Node *getLast(Node *node)
{
    while (node->next != NULL)
    {
        node = node->next;
    }
    return node;
}

void printList(DoublyLinkedList *list)
{
    Node *aux = list->head;

    while (aux != NULL)
    {
        cout << aux->data << " ";
        aux = aux->next;
    }

    cout << endl;
}

// insert a node at the start of the list
void unshift(DoublyLinkedList *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head != NULL)
    {
        (list->head)->prev = newNode;
    }

    list->head = newNode;
}

// remove the first node of the list
void shift(DoublyLinkedList *list)
{
    if (list->head == NULL)
    {
        return;
    }

    Node *temp = list->head;
    list->head = (list->head)->next;

    if (list->head != NULL)
    {
        (list->head)->prev = NULL;
    }

    free(temp);
}

// insert a node at the end of the list
void push(DoublyLinkedList *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        newNode->prev = NULL;
        list->head = newNode;
    }
    else
    {
        Node *last = getLast(list->head);
        last->next = newNode;
        newNode->prev = last;
    }
}

// remove the last node of the list
void pop(DoublyLinkedList *list)
{
    if (list->head == NULL)
    {
        return;
    }

    if ((list->head)->next == NULL)
    {
        free(list->head);
        list->head = NULL;
        return;
    }

    Node *last = getLast(list->head);
    last->prev->next = NULL;
    free(last);
}

void invertList(DoublyLinkedList *list)
{
    Node *current = list->head;
    Node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        list->head = temp->prev;
    }
}

int main()
{
    DoublyLinkedList *list = initList();

    unshift(list, 10);
    printList(list);

    unshift(list, 20);
    printList(list);

    push(list, 30);
    printList(list);

    push(list, 40);
    printList(list);

    invertList(list);
    printList(list);

    return 0;
}
