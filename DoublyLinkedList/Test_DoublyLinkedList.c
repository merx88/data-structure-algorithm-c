#include "DoublyLinkedList.h"

int main(void)
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *Current = NULL;

    /*  ≥ÎµÂ 5∞≥ √ﬂ∞° */
    for (i = 0; i < 5; i++)
    {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    /*  ∏ÆΩ∫∆Æ √‚∑¬ */
    Count = DLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  ∏ÆΩ∫∆Æ¿« ººπ¯¬∞ ƒ≠ µ⁄ø° ≥ÎµÂ ª¿‘ */
    printf("\nInserting 3000 After [2]...\n\n");

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertAfter(Current, NewNode);

    /*  ∏ÆΩ∫∆Æ √‚∑¬ */
    Count = DLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  ∏µÁ ≥ÎµÂ∏¶ ∏ﬁ∏∏Æø°º≠ ¡¶∞≈     */
    printf("\nDestroying List...\n");

    Count = DLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        Current = DLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            DLL_RemoveNode(&List, Current);
            DLL_DestroyNode(Current);
        }
    }

    return 0;
}