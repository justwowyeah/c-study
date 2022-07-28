#include "game.h"
//初始化雷阵
void InitBoard(char board[][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}

	}

}
//打印雷阵
void DisplayBoard(char board[][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	printf("\n _______________________________________\n|");
	//打印列号
	for (count = 0; count <= row; count++)
	{
		printf("\033[31m%2d\033[0m |", count);
	}

	printf("\n|___|___|___|___|___|___|___|___|___|___|\n");

	for (i = 1; i <= row; i++)
	{
		//打印行号
		printf("|\033[31m%2d\033[0m |", i);

		for (j = 1; j <= col; j++)
		{
			printf(" \033[33m%c\033[0m |", board[i][j]);
		}

		printf("\n|___|___|___|___|___|___|___|___|___|___|\n");
	}

	printf("\n");
}
//设置雷
void SetMine(char mine[][COLS], int row, int col, int count)
{
	int x = 0;
	int y = 0;

	while (count)
	{
		x = (rand() % row) + 1;
		y = (rand() % row) + 1;

		if ('0' == mine[x][y])
		{
			mine[x][y] = '*';
			count--;
		}

	}

}
//获取坐标周围雷的个数
char GetMine(char mine[][COLS], int i, int j)
{
	int x = 0;
	int y = 0;
	char num = '0';
	//遍历周围九个坐标
	for (x = -1; x <= 1; x++)
	{
		for (y = -1; y <= 1; y++)
		{
			if (mine[i + x][j + y] == '*')
			{
				num++;
			}

		}

	}

	return num;
}
//展开一片
void Spread(char show[][COLS], char mine[][COLS], int row, int col, int i, int j, int *count)
{
	int x = 0;
	int y = 0;
	//遍历周围九个坐标
	for (x = -1; x <= 1; x++)
	{
		for (y = -1; y <= 1; y++)
		{
			//保证坐标位于雷阵上且未被排查出来（防止栈溢出）且不是雷
			if (((i + x) >= 1) && ((i + x) <= row)
				&& ((j + y) >= 1) && ((j + y) <= col)
				&& '*' == show[i + x][j + y]
				&& (mine[i + x][j + y] == '0'))
			{
				//存放坐标周围雷的个数
				show[i + x][j + y] = GetMine(mine, i + x, j + y);
				*count = *count + 1;
				//如果坐标周围没有雷，则通过递归展开一片
				if ('0' == show[i + x][j + y])
				{
					Spread(show, mine, row, col, i + x, j + y, count);
				}

			}

		}

	}

}

void FindMine(char show[][COLS], char mine[][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	//计时
	clock_t start, end;
	//确定待排查的坐标个数
	int count = (row * col) - EasyCount;

	while (1)
	{
		int input = 0;
		printf(" 排查还是标记呢？抑或是取消标记？\n 1 排查   0 标记或取消标记\n 请选择:>");
		scanf("%d", &input);

		if (1 == input)
		{
			while (count)
			{
				printf("\n 你想排查哪个地方呢？请输入行与列:>\n");
				printf(" 输入行:>");
				scanf("%d", &i);
				printf(" 输入列:>");
				scanf("%d", &j);
				//开始计时
				if (0 == tmp)
				{
					start = clock();
				}
				//判断坐标是否合法
				if ((i >= 1) && (i <= row) && (j >= 1) && (j <= col))
				{
					//合法，则判断坐标是否已经被排查
					if (('*' == show[i][j]) || ('?' == show[i][j]))
					{
						//未被排查，则判断坐标是否为雷
						if ('0' == mine[i][j])
						{
							//不是雷，则存放坐标周围雷的个数
							show[i][j] = GetMine(mine, i, j);
							//如果坐标周围没有雷，则展开一片
							if ('0' == show[i][j])
							{
								Spread(show, mine, row, col, i, j, &count);
							}

							tmp = 1;
							count--;

							if (0 == count)
							{
								DisplayBoard(mine, row, col);
								goto end;
							}
							else
							{
								DisplayBoard(show, row, col);
								break;
							}

						}
						else
						{
							//是雷，且第一次排查，则保证坐标不是雷
							if (0 == tmp)
							{
								//防止原坐标被重新设置成雷
								while (1)
								{
									mine[i][j] = '0';
									SetMine(mine, row, col, 1);

									if ('0' == mine[i][j])
									{
										break;
									}
								}

								show[i][j] = GetMine(mine, i, j);
								DisplayBoard(show, row, col);
								count--;
								tmp = 1;
								break;
							}
							else
							{
								//是雷，且不是第一次排查，则游戏结束
								DisplayBoard(mine, row, col);
								printf("  * 代表雷\n\n");
								printf(" !!!!!!!!!!! BOOM !!!!!!!!!!!\n\n");
								printf(" 你不小心踩到雷了！再来一次吧！\n\n");
								goto end;
							}

						}

					}
					else
					{
						printf("\n 这个地方已经排查过了哦，再看看吧！\n\n");
					}

				}
				else
				{
					printf("\n 找不到这个地方哦，再看看吧！\n\n");
				}

			}

		}
		else if (0 == input)
		{
			while (1)
			{
				printf("\n 你想标记或取消标记哪个地方呢？请输入行与列:>\n");
				printf(" 输入行:>");
				scanf("%d", &i);
				printf(" 输入列:>");
				scanf("%d", &j);
				//判断坐标是否合法
				if ((i >= 1) && (i <= row) && (j >= 1) && (j <= col))
				{
					//判断坐标是否被排查或标记
					if ('*' == show[i][j])
					{
						//标记
						show[i][j] = '?';
						DisplayBoard(show, ROW, COL);
						break;
					}
					else if ('?' == show[i][j])
					{
						//取消标记
						show[i][j] = '*';
						DisplayBoard(show, ROW, COL);
						break;
					}
					else
					{
						printf("\n 这个地方已经排查过了哦，再看看吧！\n\n");
					}

				}
				else
				{
					printf("\n 找不到这个地方哦，再看看吧！\n\n");
				}

			}

		}
		else
		{
			printf("没有这个选项哦，请重新选择:>\n\n");
		}

	}

end:;
	end = clock();
	printf(" 耗时：%f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
}