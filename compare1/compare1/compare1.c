#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int tmp = 0;
	scanf("%d%d%d", &a, &b, &c);

	if (a < b)
	{
		tmp = b;
		b = a;
		a = tmp;
	}

	if (a < c)
	{
		tmp = c;
		c = a;
		a = tmp;
	}

	if (b < c)
	{
		tmp = c;
		c = b;
		b = tmp;
	}

	printf("%d %d %d", a, b, c);

	return 0;
}