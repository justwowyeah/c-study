#include <stdio.h>

int main(void)
{
	int a = 13;
	int count = 0;
	int i = 0;

	for (i = 0; i < 32; i++)
	{
		if (a & 1 == 1)
		{
			count++;
		}

		a = a >> 1;
	}

	printf("%d", count);

	return 0;
}