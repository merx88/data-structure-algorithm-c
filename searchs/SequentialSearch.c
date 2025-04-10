#include <stdio.h>
#include <string.h>

int Transpose(int DataSet[], int Length, int Target)
{
    int i = 0;
    int Match = -1;
    int Temp = -1;
    while (Match == -1)
    {
        if (Target == DataSet[i])
        {
            Match = DataSet[i];
            if (i > 0) // 추가 해야함 첫번째는 스왑 하지 않으니까
            {
                Temp = DataSet[i];
                DataSet[i] = DataSet[i - 1];
                DataSet[i - 1] = Temp;
            }
        }
        i++;
    }

    return Match;
}

int main(void)
{
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
    int Target = 2;
    int i = 0;

    for (i = 0; i < Length; i++)
    {
        printf("%d", DataSet[i]);
    }
    printf("\n");

    printf("%d\n", Transpose(DataSet, Length, Target));

    for (i = 0; i < Length; i++)
    {
        printf("%d", DataSet[i]);
    }

    printf("\n");

    return 0;
}