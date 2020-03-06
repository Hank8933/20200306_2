#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100

int aba(char *string) //判斷是否為迴文，是迴文回傳1，反之0
{
    int i;
    int len;  //字串長度

    len = strlen(string);

    for(i = 0; i < (len/2); i++)
    {
        if (string[i] != string[len-i-1])  //判斷
            return 0;
    }
    return 1;
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

    for (i=1; i<=MAX; i++) //拆分字串，i=字串長度
    {
        //printf("%d:\n",i);
        int left=0;
        char arrayTemp[i];
        for (j=0; j<=i; j++)
        {
            arrayTemp[j] = '\0';
        }
        //printf("%d \n",strlen(arrayTemp));
        for (left=0; left<=MAX-i; left++) //left=字串開始
        {
           // printf("l:%d\n",left);

            for (j=0; j<i; j++) //填入臨時字串
            {
                arrayTemp[j]=array[left+j];
            }

            //printf("%d %s\n",strlen(arrayTemp),arrayTemp);

            if (aba(arrayTemp))  //判斷是否為迴文
            {
                printf("%s ",arrayTemp);
            }
        }
        printf("\n");
    }
    return 0;
}
