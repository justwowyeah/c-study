#include <stdio.h>

int main()
{
    int sum = 0;
    int ret = 1;
    int n = 1;

    for (n = 1;n <= 10; n++)
    {
        ret *= n;
        sum += ret;
    }

    printf("%d", sum);

    return 0;
}