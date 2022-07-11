#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int day = 0;
    scanf("%d", &day);

    if (day >= 1 && day <= 6)
    {
        printf("星期%d", day);
    }
    else if (day == 7)
    {
        printf("星期天");
    }
    else
    {
        printf("请输入1-7的值");
    }

    return 0;
}