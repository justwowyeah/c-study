#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//打印菜单
void menu()
{
	printf("****************************\n");
	printf("****************************\n");
	printf("*********  1.play  *********\n");
	printf("*********  0.exit  *********\n");
	printf("****************************\n");
	printf("****************************\n");
}
//运行游戏
void game()
{
	char board[ROW][COL];
	//初始化并打印棋盘
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);

	char ret = 0;

	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断游戏状态
		ret = IsWin(board, ROW, COL);

		if (ret == '*')
		{
			printf("\n你赢啦！！！\n再来一盘吧！\n");
			break;
		}
		else if (ret == '#')
		{
			printf("\n你输了哦，再来一盘？\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("\n打成平局啦！\n再来一盘！\n");
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断游戏状态
		ret = IsWin(board, ROW, COL);

		if (ret == '*')
		{
			printf("\n你赢啦！！！\n再来一盘吧！\n");
			break;
		}
		else if (ret == '#')
		{
			printf("\n你输了哦，再来一盘？\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("\n打成平局啦！\n再来一盘！\n");
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
		printf("请输入数字选择，记得回车哦:>");
		scanf("%d", &input);

		//根据输入判断游戏是否进行
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("\n退出游戏\n");
			break;
		}
		default:
		{
			printf("\n选择错误\n");
			break;
		}

		}

	} while (input);

	return 0;
}