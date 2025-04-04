#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef char ElementType;

typedef struct tagSBTNode
{
    struct tagSBTNode *Left;
    struct tagSBTNode *Right;

    ElementType Data;
} SBTNode;

SBTNode *SBT_CreateNode(ElementType NewData);
void SBT_DestroyNode(SBTNode *Node);
void SBT_DestroyTree(SBTNode *Root);

void SBT_PostorderPrintTree(SBTNode *Node);
void SBT_InorderPrintTree(SBTNode *Node);
void SBT_PreorderPrintTree(SBTNode *Node);

#endif