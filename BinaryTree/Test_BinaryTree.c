#include "BinaryTree.h"

int main(void)
{
    /*  ≥ÎµÂ ª˝º∫ */
    SBTNode *A = SBT_CreateNode('A');
    SBTNode *B = SBT_CreateNode('B');
    SBTNode *C = SBT_CreateNode('C');
    SBTNode *D = SBT_CreateNode('D');
    SBTNode *E = SBT_CreateNode('E');
    SBTNode *F = SBT_CreateNode('F');
    SBTNode *G = SBT_CreateNode('G');

    /*  ∆Æ∏Æø° ≥ÎµÂ √ﬂ∞° */
    A->Left = B;
    B->Left = C;
    B->Right = D;

    A->Right = E;
    E->Left = F;
    E->Right = G;

    /*  ∆Æ∏Æ √‚∑¬ */
    printf("Preorder ...\n");
    SBT_PreorderPrintTree(A);
    printf("\n\n");

    printf("Inorder ... \n");
    SBT_InorderPrintTree(A);
    printf("\n\n");

    printf("Postorder ... \n");
    SBT_PostorderPrintTree(A);
    printf("\n");

    /*  ∆Æ∏Æ º“∏ÍΩ√≈∞±‚ */
    SBT_DestroyTree(A);

    return 0;
}