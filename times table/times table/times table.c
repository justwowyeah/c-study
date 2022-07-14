#include <stdio.h>

void multiply()
{
	int i = 0;
	int a = 0;

	for (i = 1; i <= 9; i++)
	{
		for (a = 1; a <= i; a++)
		{
			printf("%d * %d = %-2d  ", a, i, i * a);
		}

		printf("\n");
	}
}

int main()
{
	multiply();
	return 0;
}