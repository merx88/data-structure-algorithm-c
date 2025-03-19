#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack **Stack)
{
    (*Stack) = (LinkedListStack *)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}
void LLS_DestroyStack(LinkedListStack *Stack)
{
    while (!LLS_IsEmpty(Stack))
    {
        Node *Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }
    free(Stack);
}

Node *LLS_CreateNode(char *Data)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode->Data = (char *)malloc(strlen(Data) + 1);

    strcpy(NewNode->Data, Data);

    NewNode->NextNode = NULL;

    return NewNode;
}

void LLS_DestroyNode(Node *_Node)
{
    free(_Node->Data);
    free(_Node);
}

void LLS_Push(LinkedListStack *Stack, Node *NewNode)
{
    if (Stack->List == NULL)
    {
        Stack->List = NewNode;
    }
    else
    {
        // Node *OldTop = Stack->List;
        // while (OldTop->NextNode != NULL)
        // {
        //     OldTop = OldTop->NextNode;
        // }
        // OldTop->NextNode = NewNode;

        Stack->Top->NextNode = NewNode;
    }

    Stack->Top = NewNode;
}

Node *LLS_Pop(LinkedListStack *Stack)
{

    Node *Popped = Stack->Top;

    if (Stack->List == Stack->Top)
    {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else
    {
        Node *OldTop = Stack->List;
        while (OldTop != NULL && OldTop->NextNode != Stack->Top)
        {
            OldTop = OldTop->NextNode;
        }
        OldTop->NextNode = NULL;
        Stack->Top = OldTop;
    }

    return Popped;
}

Node *LLS_Top(LinkedListStack *Stack)
{
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack *Stack)
{

    Node *Current = Stack->List;
    int size = 1;
    while (Current->NextNode != NULL)
    {
        Current = Current->NextNode;
        size++;
    }
    return size;

    // 모범답안
    //  int Count = 0;
    //  Node *Current = Stack->List;

    // while (Current != NULL)
    // {
    //     Current = Current->NextNode;
    //     Count++;
    // }

    // return Count;
}

int LLS_IsEmpty(LinkedListStack *Stack)
{

    // 걍 널하고 비교하면 0인지 1인지 툭하고 튀어나옴!

    return (Stack->List == NULL);
}
