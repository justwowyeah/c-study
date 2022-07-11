#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void compare(int* x, int* y)
{
	int z = 0;
	z = *x;
	*x = *y;
	*y = z;
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int tmp = 0;
	scanf("%d%d%d", &a, &b, &c);

	if (a < b)
	{
		compare(a, b);
	}

	if (a < c)
	{
		compare(&a, &c);
	}

	if (b < c)
	{
		compare(&b, &c);
	}

	printf("%d %d %d", a, b, c);

	return 0;
}