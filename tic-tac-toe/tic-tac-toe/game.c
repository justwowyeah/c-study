#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}

	}

}

void DisplayBoard(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("\n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);

			if (j < col - 1)
			{
				printf("|");
			}

		}

		printf("\n");
		
		for (j = 0; j < col; j++)
		{
			if (i < row - 1)
			{
				printf("___");
			}
			else
			{
				printf("   ");
			}
			if (j < col - 1)
			{
				printf("|");
			}

		}
		
		printf("\n");
	}

}

void PlayerMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("\n你来下!");

	while (1)
	{
		printf("下在哪一行呢:>");
		scanf("%d", &x);
		printf("下在哪一列呢:>");
		scanf("%d", &y);

		if (x > 0 && x < 4 && y > 0 && y < 4)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("\n这个地方已经被下过了，再看看吧!\n");
			}

		}
		else
		{
			printf("\n找不到这个地方，再看看吧!\n");
		}

	}

}

void ComputerMove(char board[][COL], int row, int col)
{
	printf("\n电脑开始下啦！");
	//电脑休眠0.5秒
	Sleep(500);
	//电脑获取随机值下棋
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}

	}

}

char IsWin(char board[][COL], int row, int col)
{
	int i = 0;

	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
		else if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}

	}

	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' '))
	{
		return board[1][1];
	}
	//判断棋盘是否填满
	int ret = IsFull(board, row, col);

	if (ret == 1)
	{
		return 'Q';
	}

	return 'C';
}

int IsFull(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}

		}

	}

	return 1;
}