#include <iostream>

using namespace std;

// Stack FILO
typedef struct Stack
{
    int data;
    struct Stack *next;
} Stack;

Stack *initStack(int data)
{
    Stack *head = (Stack *)malloc(sizeof(Stack));
    head->data = data;
    head->next = NULL;
    return head;
}

void push(Stack **head, int data)
{
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int pop(Stack **head)
{
    if (*head == NULL)
    {
        return -1;
    }
    Stack *node = *head;
    *head = (*head)->next;
    int data = node->data;
    free(node);
    return data;
}

int peek(Stack *head)
{
    if (head == NULL)
    {
        return -1;
    }
    return head->data;
}

void printStack(Stack *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Stack *head = initStack(2);

    push(&head, 10);
    printStack(head);

    push(&head, 20);
    printStack(head);

    push(&head, 30);
    printStack(head);

    cout << pop(&head) << endl;
    printStack(head);

    cout << peek(head) << endl;
    printStack(head);

    return 0;
}