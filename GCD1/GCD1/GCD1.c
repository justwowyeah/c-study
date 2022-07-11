#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int a = 0;
	int b = 0;
	int tmp = 0;
	scanf("%d%d", &a, &b);

	if (a < b)
	{
		tmp = b;
		b = a;
		a = tmp;
	}

	for (i = b; ; i--)
	{
		if (0 == a % i && 0 == b % i)
		{
			printf("%d ", i);
			break;
		}

	}

	return 0;
}