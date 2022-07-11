#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int max = 0;
	scanf("%d%d", &a, &b);

	if (a < b)
	{
		max = b;
	}
	else
	{
		max = a;
	}

	while (1)
	{
		if (0 == a % max && 0 == b % max)
		{
			printf("%d ", max);
			break;
		}

		max--;
	}

	return 0;
}