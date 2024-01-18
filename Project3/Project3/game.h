#pragma once
#include <stdio.h>
#define ROW 9
#define COL 9
#define ROWs 11
#define COLs 11
#define COUNT 10
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void menu();

void entergame();
void startgame();

void init(char array[ROWs][COLs], int row, int col, char c);
void display(char array[ROWs][COLs], int row, int col);

void setMine(char array[ROWs][COLs], int row, int col);
void findMine(char show[ROWs][COLs], char data[ROWs][COLs], int row, int col);

void recurveSearch(char show[ROWs][COLs], char data[ROWs][COLs], int row, int col,int x,int y);

int getNumber(char data[ROWs][COLs], int x, int y);

bool isWin(char show[ROWs][COLs],char data[ROWs][COLs], int row, int col);