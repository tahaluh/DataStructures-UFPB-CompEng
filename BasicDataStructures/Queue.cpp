#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *head;
    Node *tail;
} Queue;

void initQueue(Queue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

void enqueue(Queue *queue, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->head == NULL)
    {
        queue->head = newNode;
    }
    else
    {
        queue->tail->next = newNode;
    }
    queue->tail = newNode;
}

int dequeue(Queue *queue)
{
    if (queue->head == NULL)
    {
        return 0;
    }
    Node *node = queue->head;
    int data = node->data;
    queue->head = node->next;
    free(node);
    return data;
}

void printQueue(Queue *queue)
{
    Node *node = queue->head;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void printValue(int value)
{
    cout << value << endl;
}

int getQueueLength(Queue *queue)
{
    int length = 0;
    Node *node = queue->head;
    while (node != NULL)
    {
        length++;
        node = node->next;
    }
    return length;
}

int main()
{
    Queue queue;
    Queue reversed;

    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printQueue(&queue);

    int len = getQueueLength(&queue);

    for (int i = 0; i < len; i++)
    {
        enqueue(&reversed, dequeue(&queue));
    }

    printQueue(&reversed);

    return 0;
}