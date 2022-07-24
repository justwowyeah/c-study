#include <stdio.h>

int my_strlen(char* str)
{
	int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}

	return count;
}

void reverse_string(char* str)
{
	int len = my_strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';

	if (my_strlen(str + 1) >= 2)
	{
		reverse_string(str + 1);
	}

	*(str + len - 1) = tmp;

}

int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}