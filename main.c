#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 100

_Bool aba(char *string,int left, int right) //判斷迴文
{
    if (string[left]!=string[right]) return false;
    if (left>=right) return true;
    else aba(string,++left,--right);
}

int main()
{
    char array[MAX];
    int i,j;

    srand(time(NULL));
    for (i=0; i<MAX; i++)
    {
        array[i] = rand() %26 + 65;
    }

    printf("亂數字串\n");
    for (i=0; i<MAX; i++)
    {
        printf("%c ",*(array+i));
    }

    printf("\n\n迴文字串:\n");
    int left;
    for (i=1; i<=MAX; i++) //i=字串長度
    {
        for (left=0; left<=MAX-i; left++) //left=字串開始
        {
            if (aba(array, left, left+i-1))  //判斷是否為迴文
            {
                for (j=left;j<left+i;j++)  //印出
                {
                    printf("%c",array[j]);
                }
                printf(" ");
            }
        }
        printf("\n");
    }
	system("pause");
    return 0;
}
