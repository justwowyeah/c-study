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
	printf("������֣�");

	while (1)
	{
		scanf("%d", &guess);

		if (guess < ret)
		{
			printf("��С�ˣ�������");
		}
		else if (guess > ret)
		{
			printf("�´��ˣ�������");
		}
		else if (guess == ret)
		{
			printf("��ϲ�㣬�¶��ˣ�");
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
		printf("����������ѡ�񣬼ǵûس�Ŷ��");
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
			printf("\n�������");
			break;
		}
		}

	} while (input);

	return 0;
}