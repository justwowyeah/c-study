#include <stdio.h>

int my_strlen(char *str)
{
	int count = 0;

	while ('\0' != *str)
	{
		count++;
		str++;
	}

	return count;
}

int main(void)
{
	int len = my_strlen("abc");
	printf("%d", len);
	return 0;
}