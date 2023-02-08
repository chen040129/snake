#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define WIGHT 100
#define HIGH  30


typedef struct snakepos
{
	int x;
	int y;
};


typedef struct body {
	int size;
	struct snakepos pos[WIGHT * HIGH];
};


typedef  struct food {
	int x;
	int y;
};


struct body b;
COORD po[2];
struct food f;
int s=300;

void snakestpos();
void backgroud();