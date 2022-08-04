#include <stdio.h>
#include <assert.h>

size_t my_strlen(const char *str)
{
	assert(str);
	size_t len = 0;

	while ('\0' != str[len++])
	{
		;
	}

	return len - 1;
}

int main(void)
{
	char arr[] = "helloworld";
	printf("%d", my_strlen(arr));
	return 0;
}