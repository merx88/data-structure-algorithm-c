#include "ArrayStack.h"

void AS_CreateStack(ArrayStack **Stack, int Capacity)
{
    (*Stack) = (ArrayStack *)malloc(sizeof(ArrayStack));
    (*Stack)->Nodes = (Node *)malloc(sizeof(Node) * Capacity);
    (*Stack)->Top = 0;
    (*Stack)->Capacity = Capacity;
}

void AS_DestroyStack(ArrayStack *Stack)
{
    free(Stack);
    free(Stack->Nodes);
}

void AS_Push(ArrayStack *Stack, ElementType Data)
{
    int Position = Stack->Top;

    Stack->Nodes[Position].Data = Data;
    Stack->Top += 1;
}

ElementType AS_Pop(ArrayStack *Stack)
{

    int Position = --(Stack->Top);
    return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack *Stack)
{
    int Postion = Stack->Top - 1;
    return Stack->Nodes[Postion].Data;
}

int AS_GetSize(ArrayStack *Stack)
{
    return Stack->Top;
}

int AS_IsEmpty(ArrayStack *Stack)
{
    // 숫자로 불리언을 표현하기에 아래와 같이 쓰면 킹찮음
    return (Stack->Top == 0);
}
