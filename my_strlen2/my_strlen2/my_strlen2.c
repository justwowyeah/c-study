#include <stdio.h>

int my_strlen(char *str)
{
	int *start = str;

	while ('\0' != *str)
	{
		str++;
	}

	return str - start;
}

int main(void)
{
	int len = my_strlen("abc");
	printf("%d", len);
	return 0;
}