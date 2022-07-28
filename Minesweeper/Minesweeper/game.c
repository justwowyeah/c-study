#include "game.h"
//��ʼ������
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
//��ӡ����
void DisplayBoard(char board[][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	printf("\n _______________________________________\n|");
	//��ӡ�к�
	for (count = 0; count <= row; count++)
	{
		printf("\033[31m%2d\033[0m |", count);
	}

	printf("\n|___|___|___|___|___|___|___|___|___|___|\n");

	for (i = 1; i <= row; i++)
	{
		//��ӡ�к�
		printf("|\033[31m%2d\033[0m |", i);

		for (j = 1; j <= col; j++)
		{
			printf(" \033[33m%c\033[0m |", board[i][j]);
		}

		printf("\n|___|___|___|___|___|___|___|___|___|___|\n");
	}

	printf("\n");
}
//������
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
//��ȡ������Χ�׵ĸ���
char GetMine(char mine[][COLS], int i, int j)
{
	int x = 0;
	int y = 0;
	char num = '0';
	//������Χ�Ÿ�����
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
//չ��һƬ
void Spread(char show[][COLS], char mine[][COLS], int row, int col, int i, int j, int *count)
{
	int x = 0;
	int y = 0;
	//������Χ�Ÿ�����
	for (x = -1; x <= 1; x++)
	{
		for (y = -1; y <= 1; y++)
		{
			//��֤����λ����������δ���Ų��������ֹջ������Ҳ�����
			if (((i + x) >= 1) && ((i + x) <= row)
				&& ((j + y) >= 1) && ((j + y) <= col)
				&& '*' == show[i + x][j + y]
				&& (mine[i + x][j + y] == '0'))
			{
				//���������Χ�׵ĸ���
				show[i + x][j + y] = GetMine(mine, i + x, j + y);
				*count = *count + 1;
				//���������Χû���ף���ͨ���ݹ�չ��һƬ
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
	//��ʱ
	clock_t start, end;
	//ȷ�����Ų���������
	int count = (row * col) - EasyCount;

	while (1)
	{
		int input = 0;
		printf(" �Ų黹�Ǳ���أ��ֻ���ȡ����ǣ�\n 1 �Ų�   0 ��ǻ�ȡ�����\n ��ѡ��:>");
		scanf("%d", &input);

		if (1 == input)
		{
			while (count)
			{
				printf("\n �����Ų��ĸ��ط��أ�������������:>\n");
				printf(" ������:>");
				scanf("%d", &i);
				printf(" ������:>");
				scanf("%d", &j);
				//��ʼ��ʱ
				if (0 == tmp)
				{
					start = clock();
				}
				//�ж������Ƿ�Ϸ�
				if ((i >= 1) && (i <= row) && (j >= 1) && (j <= col))
				{
					//�Ϸ������ж������Ƿ��Ѿ����Ų�
					if (('*' == show[i][j]) || ('?' == show[i][j]))
					{
						//δ���Ų飬���ж������Ƿ�Ϊ��
						if ('0' == mine[i][j])
						{
							//�����ף�����������Χ�׵ĸ���
							show[i][j] = GetMine(mine, i, j);
							//���������Χû���ף���չ��һƬ
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
							//���ף��ҵ�һ���Ų飬��֤���겻����
							if (0 == tmp)
							{
								//��ֹԭ���걻�������ó���
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
								//���ף��Ҳ��ǵ�һ���Ų飬����Ϸ����
								DisplayBoard(mine, row, col);
								printf("  * ������\n\n");
								printf(" !!!!!!!!!!! BOOM !!!!!!!!!!!\n\n");
								printf(" �㲻С�Ĳȵ����ˣ�����һ�ΰɣ�\n\n");
								goto end;
							}

						}

					}
					else
					{
						printf("\n ����ط��Ѿ��Ų����Ŷ���ٿ����ɣ�\n\n");
					}

				}
				else
				{
					printf("\n �Ҳ�������ط�Ŷ���ٿ����ɣ�\n\n");
				}

			}

		}
		else if (0 == input)
		{
			while (1)
			{
				printf("\n �����ǻ�ȡ������ĸ��ط��أ�������������:>\n");
				printf(" ������:>");
				scanf("%d", &i);
				printf(" ������:>");
				scanf("%d", &j);
				//�ж������Ƿ�Ϸ�
				if ((i >= 1) && (i <= row) && (j >= 1) && (j <= col))
				{
					//�ж������Ƿ��Ų����
					if ('*' == show[i][j])
					{
						//���
						show[i][j] = '?';
						DisplayBoard(show, ROW, COL);
						break;
					}
					else if ('?' == show[i][j])
					{
						//ȡ�����
						show[i][j] = '*';
						DisplayBoard(show, ROW, COL);
						break;
					}
					else
					{
						printf("\n ����ط��Ѿ��Ų����Ŷ���ٿ����ɣ�\n\n");
					}

				}
				else
				{
					printf("\n �Ҳ�������ط�Ŷ���ٿ����ɣ�\n\n");
				}

			}

		}
		else
		{
			printf("û�����ѡ��Ŷ��������ѡ��:>\n\n");
		}

	}

end:;
	end = clock();
	printf(" ��ʱ��%f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
}