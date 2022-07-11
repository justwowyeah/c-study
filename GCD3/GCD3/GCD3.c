#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int m = 0;
	int n = 0;
	int t = 0;
	scanf("%d%d", &m, &n);

	if (m < n)
	{
		t = m;
		m = n;
		n = t;
	}

	while (m % n)
	{
		t = m % n;
		m = n;
		n = t;
	}

	printf("%d", n);

	return 0;
}