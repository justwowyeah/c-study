#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define EasyCount 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[][COLS], int rows, int cols, char set);
void DisplayBoard(char board[][COLS], int row, int col);
void SetMine(char mine[][COLS], int row, int col, int count);
void FindMine(char show[][COLS], char mine[][COLS], int row, int col);