#include "game.h"

void menu(void)
{
	printf(" ---------  ɨ  ��  ---------\n");
	printf(" ****************************\n");
	printf(" ****************************\n");
	printf(" *********  1.play  *********\n");
	printf(" *********  0.exit  *********\n");
	printf(" ****************************\n");
	printf(" ****************************\n");
	printf(" ----------------------------\n");
}

void game(void)
{
	//�����
	char mine[ROWS][COLS];
	//�����Χ�׵ĸ���
	char show[ROWS][COLS];
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL, EasyCount);
	//�Ų���
	FindMine(show, mine, ROW, COL);
}

int main(void)
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf(" ����������ѡ�񣬼ǵûس�Ŷ:>");
		scanf("%d", &input);
		//���������ж���Ϸ�Ƿ����
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("\n �˳���Ϸ\n");
			break;
		default:
			printf("\n û�����ѡ��Ŷ��������ѡ��:>\n\n");
			break;
		}

	} while (input);

	return 0;
}