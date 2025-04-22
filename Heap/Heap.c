#include "Heap.h"

Heap *HEAP_Create(int InitialSize)
{
    Heap *NewHeap = (Heap *)malloc(sizeof(Heap));
    NewHeap->Capacity = InitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode *)malloc(sizeof(HeapNode) * NewHeap->Capacity);

    printf("size : %lu\n", sizeof(HeapNode));

    return NewHeap;
}

void HEAP_Destroy(Heap *H)
{
    free(H->Nodes);
    free(H);
}

void HEAP_Insert(Heap *H, ElementType NewData)
{
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);

    if (CurrentPosition == H->Capacity)
    {
        H->Capacity *= 2;
        H->Nodes = (HeapNode *)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }

    H->Nodes[CurrentPosition].Data = NewData;

    while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
    {
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);
        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }

    H->UsedSize++;
}

int HEAP_GetParent(int Index)
{
    return (int)((Index - 1) / 2);
}

void HEAP_SwapNodes(Heap *H, int Index1, int Index2)
{
    int CopySize = sizeof(HeapNode);
    HeapNode *Temp = (HeapNode *)malloc(CopySize);

    memcpy(Temp, &H->Nodes[Index1], CopySize);
    memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
    memcpy(&H->Nodes[Index2], Temp, CopySize);

    free(Temp);
}

void HEAP_DeleteMin(Heap *H, HeapNode *Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    memset(&H->Nodes[0], 0, sizeof(HeapNode));

    H->UsedSize--;

    HEAP_SwapNodes(H, 0, H->UsedSize);

    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1)
    {
        int SelectedChild = 0;
        // 왼쪽 포지션이 크거나 같으면 해당 지금 selectedNode는 자식이 없는거임

        if (LeftPosition >= H->UsedSize)
            break;
        // 만약 오른 쪽 포지션이 크거나 같으면 오른쪽이 없는거고 왼쪽은 있는거다 완전이진트리이기떄문에
        if (RightPosition >= H->UsedSize)
        {
            SelectedChild = LeftPosition;
        }
        // 만약 자식이 둘다 있다면 작은쪽을 찾아서 스왑해줘야한다
        else
        {
            if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
            {
                SelectedChild = RightPosition;
            }
            else
            {
                SelectedChild = LeftPosition;
            }
        }

        if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data)
        {
            HEAP_SwapNodes(H, SelectedChild, ParentPosition);
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;

        if (H->UsedSize < (H->Capacity / 2))
        {
            H->Capacity /= 2;
            H->Nodes = (HeapNode *)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
        }
    }
}

int HEAP_GetLeftChild(int Index)
{
    return (Index * 2) + 1;
}

void HEAP_PrintNodes(Heap *H)
{
    int i = 0;
    for (i = 0; i < H->UsedSize; i++)
    {
        printf("%d ", H->Nodes[i].Data);
    }
    printf("\n");
}