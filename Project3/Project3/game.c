#define _CRT_SECURE_NO_WARNINGS	
#include "game.h"



void menu() {

	printf("*********************\n");
	printf("****1.play 0.exit****\n");
	printf("*********************\n");
}

void entergame()
{
	int input = 0;

	do
	{
		menu();
		printf("�������Ӧ�����֣�\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�ɹ��˳���Ϸ��");
			break;
		case 1:
			startgame();
			break;
		default:
			printf("��Ч���ݣ�no!\n");
			break;
		}
	} while (input);
}

void startgame() {
	char data[ROWs][COLs];
	char show[ROWs][COLs];

	init(data, ROWs, COLs, '0');
	init(show, ROWs, COLs, '*');

	//display(data, ROW, COL);
	display(show, ROW, COL);

	setMine(data,ROW,COL);
	//display(data, ROW, COL);

	findMine(show, data, ROW, COL);

}

void init(char array[ROWs][COLs], int row, int col, char c) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			array[i][j] = c;
		}
	}
}

void display(char array[ROWs][COLs], int row, int col) {
	printf("  ");
	for (int i = 1; i <= row; ++i) {
		printf(" %d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; ++i) {
		printf("%d ", i);
		for (int j = 1; j <= col; ++j) {
			printf(" %c ", array[i][j]);
		}printf("\n");
	}
}

void setMine(char array[ROWs][COLs], int row, int col) {
	int x, y;
	for (int i = 0; i < COUNT; ++i) {
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (array[x][y] == '0') {
			array[x][y] = '1';
		}
		else {
			i--;
		}
	}
}

void findMine(char show[ROWs][COLs], char data[ROWs][COLs], int row, int col) {
	int x, y, i = 0;
	while (1)
	{
		printf("������������������");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (data[x][y] == '1') {
				i++;
				if (i == 1) {
					printf("��������������һ���������ᡣ\n");
					continue;
				}
				display(data, row, col);
				printf("��ʦδ����������\n");
				return;
			}
			else
			{
				recurveSearch(show, data, row, col, x, y);
				display(show, row, col);
				if (isWin(show, data, row, col)) {
					break;
				}
			}
		}
		else
		{
			printf("�������겻�Ϸ�������������\n");
		}
	}
	printf("��ϲ����Ӯ�ˣ�");
}

void recurveSearch(char show[ROWs][COLs], char data[ROWs][COLs], int row, int col, int x, int y) {

	if (x >= 1 && x <= row && y >= 1 && y <= col) {
		if (show[x][y] == ' ') {

			return;
		}
		else if (getNumber(data, x, y) != 0) {
			show[x][y] = getNumber(data, x, y) + '0';
			return;
		}
		show[x][y] = ' ';
		recurveSearch(show, data, row, col, x - 1, y - 1);
		recurveSearch(show, data, row, col, x - 1, y);
		recurveSearch(show, data, row, col, x - 1, y + 1);
		recurveSearch(show, data, row, col, x, y - 1);
		recurveSearch(show, data, row, col, x, y + 1);
		recurveSearch(show, data, row, col, x + 1, y - 1);
		recurveSearch(show, data, row, col, x + 1, y);
		recurveSearch(show, data, row, col, x + 1, y + 1);
	}
}

int getNumber(char data[ROWs][COLs], int x, int y)
{
	int res = data[x - 1][y - 1] + data[x - 1][y] + data[x - 1][y + 1]+data[x][y-1]+data[x][y+1]
		+ data[x + 1][y - 1] + data[x + 1][y] + data[x + 1][y + 1];
	res = res - 8 * '0';
	return res;
}

bool isWin(char show[ROWs][COLs], char data[ROWs][COLs], int row, int col)
{
	for (int i = 1; i < row; i + 1) {
		for (int j = 1; j < col; ++j) {
			if (data[i][j] == '1' || data[i][j] == '0' && show[i][j] != '*'){
				continue;
			}
			else {
				return false;
			}
		}
	}
	return 0;
}
