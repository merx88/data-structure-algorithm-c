#include <stdio.h>
#include <string.h>
// void InsertionSort(int DataSet[], int Length)
// {
//     int i = 0;
//     int j = 0;
//     int temp = 0;
//     for (i = 0; i < Length - 1; i++)
//     {
//         for (j = 1 + i; j >= 0; j--)
//         {
//             if (DataSet[j] < DataSet[j - 1])
//             {
//                 temp = DataSet[j];
//                 DataSet[j] = DataSet[j - 1];
//                 DataSet[j - 1] = temp;
//             }
//             else
//             {
//                 break;
//             }
//         }
//     }
// }

void InsertionSort(int DataSet[], int Length)
{
    int i = 0;
    int j = 0;
    int value = 0;
    for (i = 1; i < Length; i++)
    {

        // 오른쪽에 있는게 가장 크면 그냥 다음거 진행
        if (DataSet[i - 1] <= DataSet[i])
            continue;

        // 맨오른쪽 value에 할당
        value = DataSet[i];

        // 왼쪽에는 value보다 작은 값이 들어가야함
        for (j = 0; j < i; j++)
        {
            // value 보다 큰녀석 발견시
            if (DataSet[j] > value)
            {
                // 어짜피 DataSet[j]이녀석 기준으로 기준 포함해서 오른족은 큰거니까 싹다 한칸씩 미룸
                memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
                // 그러고 미룬 빈칸에 삽입해서 정렬
                DataSet[j] = value;
                break;
            }
        }
    }
}

int main(void)
{
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    InsertionSort(DataSet, Length);

    for (i = 0; i < Length; i++)
    {
        printf("%d", DataSet[i]);
    }

    printf("\n");

    return 0;
}