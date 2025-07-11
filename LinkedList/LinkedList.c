#include "LinkedList.h"

Node *SLL_CreateNode(ElementType NewData)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    return NewNode;
}

void SLL_DestroyNode(Node *Node)
{
    free(Node);
}

void SLL_AppendNode(Node **Head, Node *NewNode)
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
    }
}

void SLL_InsertAfter(Node *Current, Node *NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node **Head, Node *NewHead)
{
    if (*Head == NULL)
    {
        *Head = NewHead;
    }
    else
    {
        NewHead->NextNode = *Head;
        *Head = NewHead;
    }
}

void SLL_RemoveNode(Node **Head, Node *Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node *Current = *Head;
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }
        if (Current != NULL)
        {
            Current->NextNode = Remove->NextNode;
        }
        else
        {
            printf("We dont have");
        }
    }
}

Node *SLL_GetNodeAt(Node *Head, int Location)
{
    Node *Current = Head;

    for (int i = 0; i < Location; i++)
    {
        Current = Current->NextNode;
    }
    // 기본적으로 순회 잘못돔 -> why -> 다음거 지정하는건데 지금 보면 벗어남;;

    // <예외처리>
    // Head가 Null인 경우 처리하지 않음
    // Location이 리스트 길이보다 큰경우를 처리하지 않음

    // 모범 답안
    // 위의 예외 처리를 모두 진행
    // while (Current != NULL && (--Location) >= 0)
    // {
    //     Current = Current->NextNode;
    // }

    return Current;
}

int SLL_GetNodeCount(Node *Head)
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