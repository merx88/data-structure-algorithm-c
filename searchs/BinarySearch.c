#include <stdlib.h>
#include <stdio.h>
#include "Score.h"

Score *BinarySearch(Score ScoreList[], int Size, double Target)
{
    int Mid;
    int Left = 0;
    int Right = Size - 1;

    while (Left <= Right) // 결국 끝까지 가면 같은 경우도 생기기에 =이 있어야함
    {
        Mid = (Right + Left) / 2;
        if (Target == ScoreList[Mid].score)
        {
            return &(ScoreList[Mid]);
        }
        else if (Target > ScoreList[Mid].score)
        {
            Left = Mid + 1;
        }
        else
        {
            Right = Mid - 1;
        }
    }

    return NULL;
}

int CompareScore(const void *_elem1, const void *_elem2)
{
    Score *elem1 = (Score *)_elem1;
    Score *elem2 = (Score *)_elem2; // 형변환

    if (elem1->score > elem2->score)
    {
        return 1;
    }
    else if (elem1->score < elem2->score)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;
    Score *found = NULL;

    qsort(DataSet, Length, sizeof(Score), CompareScore);

    found = BinarySearch(DataSet, Length, 671.78);

    printf("found: %d %f \n", found->number, found->score);
    return 0;
}