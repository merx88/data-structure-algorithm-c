#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
} Node;

typedef struct tagCircularQueue
{
    Node *Nodes;
    int Capacity;
    int Front;
    int Rear;

} CircularQueue;

void CQ_CreateQueue(CircularQueue **Queue, int Capacity);
void CQ_DestroyQueue(CircularQueue *Queue);
void CQ_Enqueue(CircularQueue *Queue, ElementType Data);
ElementType CQ_Dequeue(CircularQueue *Queue);
int CQ_GetSize(CircularQueue *Queue);
int CQ_IsEmpty(CircularQueue *Queue);
int CQ_IsFull(CircularQueue *Queue);

#endif