#include "DisjointSet.h"

DisjointSet *DS_MakeSet(void *NewData)
{
    DisjointSet *NewSet = (DisjointSet *)malloc(sizeof(DisjointSet));
    NewSet->parent = NULL;
    NewSet->Data = NewData;

    return NewSet;
}

DisjointSet *DS_FindSet(DisjointSet *Set)
{

    // 이렇게 풀면 set이 루트인 경우 Null의 부모를 찾아내니까 말이안됨
    // DisjointSet *CurrentParent = Set->parent;
    // while (CurrentParent->parent != NULL)
    // {
    //     CurrentParent = CurrentParent->parent;
    // }

    // return CurrentParent;

    while (Set->parent != NULL)
    {
        Set = Set->parent;
    }

    return Set;
}

void DS_DestroySet(DisjointSet *Set)
{

    free(Set);
}

void DS_UnionSet(DisjointSet *Set1, DisjointSet *Set2)
{
    Set2 = DS_FindSet(Set2);
    Set2->parent = Set1;
}