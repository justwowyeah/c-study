#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int day = 0;
    scanf("%d", &day);

    if (day >= 1 && day <= 6)
    {
        printf("����%d", day);
    }
    else if (day == 7)
    {
        printf("������");
    }
    else
    {
        printf("������1-7��ֵ");
    }

    return 0;
}