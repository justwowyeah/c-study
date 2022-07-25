#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ӡ�˵�
void menu()
{
	printf("****************************\n");
	printf("****************************\n");
	printf("*********  1.play  *********\n");
	printf("*********  0.exit  *********\n");
	printf("****************************\n");
	printf("****************************\n");
}
//������Ϸ
void game()
{
	char board[ROW][COL];
	//��ʼ������ӡ����
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);

	char ret = 0;

	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ϸ״̬
		ret = IsWin(board, ROW, COL);

		if (ret == '*')
		{
			printf("\n��Ӯ��������\n����һ�̰ɣ�\n");
			break;
		}
		else if (ret == '#')
		{
			printf("\n������Ŷ������һ�̣�\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("\n���ƽ������\n����һ�̣�\n");
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ϸ״̬
		ret = IsWin(board, ROW, COL);

		if (ret == '*')
		{
			printf("\n��Ӯ��������\n����һ�̰ɣ�\n");
			break;
		}
		else if (ret == '#')
		{
			printf("\n������Ŷ������һ�̣�\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("\n���ƽ������\n����һ�̣�\n");
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
		printf("����������ѡ�񣬼ǵûس�Ŷ:>");
		scanf("%d", &input);

		//���������ж���Ϸ�Ƿ����
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("\n�˳���Ϸ\n");
			break;
		}
		default:
		{
			printf("\nѡ�����\n");
			break;
		}

		}

	} while (input);

	return 0;
}