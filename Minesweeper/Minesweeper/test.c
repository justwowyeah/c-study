#include "game.h"

void menu(void)
{
	printf(" ---------  扫  雷  ---------\n");
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
	//存放雷
	char mine[ROWS][COLS];
	//存放周围雷的个数
	char show[ROWS][COLS];
	//初始化雷阵
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印雷阵
	DisplayBoard(show, ROW, COL);
	//设置雷
	SetMine(mine, ROW, COL, EasyCount);
	//排查雷
	FindMine(show, mine, ROW, COL);
}

int main(void)
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf(" 请输入数字选择，记得回车哦:>");
		scanf("%d", &input);
		//根据输入判断游戏是否进行
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("\n 退出游戏\n");
			break;
		default:
			printf("\n 没有这个选项哦，请重新选择:>\n\n");
			break;
		}

	} while (input);

	return 0;
}