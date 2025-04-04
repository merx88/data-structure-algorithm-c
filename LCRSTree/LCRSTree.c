#include "LCRSTree.h"

LCRSNode *LCRS_CreateNode(ElementType NewData)
{
    LCRSNode *NewNode = (LCRSNode *)malloc(sizeof(LCRSNode));

    NewNode->Data = NewData;
    NewNode->RightSibling = NULL;
    NewNode->LeftChild = NULL;

    return NewNode;
}

void LCRS_DestroyNode(LCRSNode *Node)
{
    free(Node);
}

void LCRS_DestroyTree(LCRSNode *Root)
{
    if (Root->LeftChild != NULL)
    {
        LCRS_DestroyTree(Root->LeftChild);
    }
    if (Root->RightSibling != NULL)
    {
        LCRS_DestroyTree(Root->RightSibling);
    }

    LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode *ParentNode, LCRSNode *ChildNode)
{
    if (ParentNode->LeftChild == NULL)
    {
        ParentNode->LeftChild = ChildNode;
    }
    else
    {
        LCRSNode *CurrentNode = ParentNode->LeftChild;
        while (CurrentNode->RightSibling != NULL)
        {
            CurrentNode = CurrentNode->RightSibling;
        }
        CurrentNode->RightSibling = ChildNode;
    }
}

void LCRS_PrintTree(LCRSNode *Node, int Depth)
{
    int i = 0;
    for (i = 0; i < Depth; i++)
    {
        printf(" ");
    }
    printf("%c\n", Node->Data);

    if (Node->LeftChild != NULL)
    {
        LCRS_PrintTree(Node->LeftChild, Depth + 1);
    }
    if (Node->RightSibling != NULL)
    {
        LCRS_PrintTree(Node->RightSibling, Depth);
    }
}
