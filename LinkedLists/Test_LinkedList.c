#include "LinkedList.h"

int main(void)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;

    /*  ≥ÎµÂ 5∞≥ √ﬂ∞° */
    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    /*  ∏ÆΩ∫∆Æ √‚∑¬ */
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  ∏ÆΩ∫∆Æ¿« ººπ¯¬∞ ≥ÎµÂ µ⁄ø° ªı ≥ÎµÂ ª¿‘ */
    printf("\nInserting 3000 After [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);

    SLL_InsertAfter(Current, NewNode);

    /*  ∏ÆΩ∫∆Æ √‚∑¬ */
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  ∏µÁ ≥ÎµÂ∏¶ ∏ﬁ∏∏Æø°º≠ ¡¶∞≈     */
    printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }

    return 0;
}
