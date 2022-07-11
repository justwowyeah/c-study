#include <stdio.h>

int is_leap_years(int i)
{
	if ((0 == i % 4 && 0 != i % 100) || (0 == i % 400))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int main()
{
	int i = 0;

	for (i = 1000; i <= 2000; i++)
	{
		if (1 == is_leap_years(i))
		{
			printf("%d\n", i);
		}

	}

	return 0;
}