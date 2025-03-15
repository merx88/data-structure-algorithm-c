#include "CircularDoublyLinkedList.h"

Node *CDLL_CreateNode(ElementType NewData)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;
    return NewNode;
}

void CDLL_DestroyNode(Node *Node)
{
    free(Node);
}

void CDLL_AppendNode(Node **Head, Node *NewNode)
{
    if (*Head == NULL)
    {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else
    {
        Node *Tail = (*Head)->PrevNode;
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
        NewNode->NextNode = *Head;
        (*Head)->PrevNode = NewNode;
    }
}

void CDLL_InsertAfter(Node *Current, Node *NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;
    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}

void CDLL_InsertNewHead(Node **Head, Node *NewHead)
{
    if (*Head == NULL)
    {
        *Head = NewHead;
    }
    else
    {
        NewHead->NextNode = *Head;
        NewHead->PrevNode = (*Head)->PrevNode;
        (*Head)->PrevNode = NewHead;
        *Head = NewHead;
    }
}

void CDLL_RemoveNode(Node **Head, Node *Remove)
{

    Remove->NextNode->PrevNode = Remove->PrevNode;
    Remove->PrevNode->NextNode = Remove->NextNode;
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
}

Node *CDLL_GetNodeAt(Node *Head, int Location)
{
    Node *Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

int CDLL_GetNodeCount(Node *Head)
{
    int Count = 0;
    Node *Current = Head;
    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;

        if (Current == Head)
            break;
    }
    return Count;
}