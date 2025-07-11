#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue **Queue, int Capacity)
{

    (*Queue) = (CircularQueue *)malloc(sizeof(CircularQueue));
    (*Queue)->Nodes = (Node *)malloc(sizeof(Node) * (Capacity + 1));

    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
    (*Queue)->Capacity = Capacity;
}

void CQ_DestroyQueue(CircularQueue *Queue)
{
    free(Queue->Nodes);
    free(Queue);
}

void CQ_Enqueue(CircularQueue *Queue, ElementType Data)
{
    int Position = Queue->Rear;
    if (Queue->Rear == Queue->Capacity)
    {

        Queue->Rear = 0;
    }
    else
    {
        Queue->Rear++;
    }

    Queue->Nodes[Position].Data = Data;
}

ElementType CQ_Dequeue(CircularQueue *Queue)
{
    int Position = Queue->Front;
    if (Queue->Front == Queue->Capacity)
    {
        Queue->Front = 0;
    }
    else
    {
        Queue->Front++;
    }
    return Queue->Nodes[Position].Data;
}

int CQ_GetSize(CircularQueue *Queue)
{
    if (Queue->Front < Queue->Rear)
    {
        return Queue->Rear - Queue->Front;
    }
    else
    {

        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
    }
}

int CQ_IsEmpty(CircularQueue *Queue)
{
    if (Queue->Front == Queue->Rear)
        return 1;
    return 0;
}

int CQ_IsFull(CircularQueue *Queue)
{
    if (Queue->Front < Queue->Rear)
    {
        return ((Queue->Rear - Queue->Front) == Queue->Capacity);
    }
    else
    {
        return (Queue->Rear + 1 == Queue->Front);
    }
}
