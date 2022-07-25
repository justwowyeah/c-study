#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<time.h>

void menu()
{
	printf("\n******************");
	printf("\n******************");
	printf("\n***** 1:play *****");
	printf("\n***** 0:exit *****");
	printf("\n******************");
	printf("\n******************\n");
}

void game()
{
	int guess = 0;
	int ret = rand() % 100 + 1;
	printf("请猜数字：");

	while (1)
	{
		scanf("%d", &guess);

		if (guess < ret)
		{
			printf("猜小了，继续：");
		}
		else if (guess > ret)
		{
			printf("猜大了，继续：");
		}
		else if (guess == ret)
		{
			printf("恭喜你，猜对了！");
			break;
		}

	}

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请输入数字选择，记得回车哦：");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
		{
			game();
		}
		case 0:
		{
			break;
		}
		default:
		{
			printf("\n输入错误");
			break;
		}
		}

	} while (input);

	return 0;
}