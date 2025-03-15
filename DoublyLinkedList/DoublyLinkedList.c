#include "DoublyLinkedList.h"

Node *DLL_CreateNode(ElementType NewData)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;
    return NewNode;
}

void DLL_DestroyNode(Node *Node)
{
    free(Node);
}

void DLL_AppendNode(Node **Head, Node *NewNode)
{
    if (*Head == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        Node *Tail = *Head;
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

void DLL_InsertAfter(Node *Current, Node *NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
    }
    Current->NextNode = NewNode;
}

void DLL_InsertNewHead(Node **Head, Node *NewHead)
{
    if (*Head == NULL)
    {
        *Head = NewHead;
    }
    else
    {
        NewHead->NextNode = *Head;
        (*Head)->PrevNode = NewHead;
        *Head = NewHead;
    }
}

void DLL_RemoveNode(Node **Head, Node *Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        if ((Remove->NextNode != NULL))
            Remove->NextNode->PrevNode = NULL;
    }
    else
    {
        // 만약에 해당 노드가 리스트에 없는 경우를 다음과 같이 처리가능하다
        if (Remove->PrevNode != NULL)
            Remove->PrevNode->NextNode = Remove->NextNode;
        if (Remove->NextNode != NULL)
            Remove->NextNode->PrevNode = Remove->PrevNode;
    }
}

Node *DLL_GetNodeAt(Node *Head, int Location)
{
    Node *Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

int DLL_GetNodeCount(Node *Head)
{
    int Count = 0;
    Node *Current = Head;
    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}