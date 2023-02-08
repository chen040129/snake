#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"



void snakestpos() {
	//初始化蛇的位置
	po[0].X = b.pos[0].x = WIGHT / 2;
	po[0].Y = b.pos[0].y = HIGH / 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[0]);
	printf("@");

};



void makefood() {
	//初始化食物的位置
    f.x = po[0].X = rand() % WIGHT;
    f.y = po[0].Y = rand() % HIGH;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[0]);
	printf("#");
}




char d = 'd';
char  d1;
void movesnake() {

	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	//设置偏移变量
	int dx;
	int dy;

	///判断是否从键盘上获得字母，如果获得，变将值赋给char d
	while (_kbhit()) {
		d = _getch();
	}

	 //判断输入字符的类别
	switch (d)
	{
	case 'd':
		dx = 1;
		dy = 0;
		break;
	case 'a':
		dx = -1;
		dy = 0;
		break;
	case 'w':
		dx = 0;
		dy = -1;
		break;
	case 's':
		dx = 0;
		dy = 1;
		break;
	default:
		break;
	}



	//让蛇产生移动
	//从大下标到小下表，赋值时小坐标赋值给大坐标保证不会互相污染
	for (int i = b.size; i > 0;i--) {
		b.pos[i].x = b.pos[i - 1].x;
		b.pos[i].y = b.pos[i - 1].y;
	}
	//移动光标，将size（蛇的长度）进行循环，并且将蛇的身体打印出来
	for (int i = 1; i <= b.size; i++) {

		po[1].X = b.pos[i].x;
		po[1].Y = b.pos[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[1]);
		printf("*");
	}
	//打印食物
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[0]);
	printf("#");
	//放后面可以将前面的代码覆盖，来获得蛇头
	po[1].X = b.pos[0].x += dx;
	po[1].Y = b.pos[0].y += dy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[1]);
	printf("@");

	//变速
	if(s>100){
	   s--;
	}

	//设定速度
	Sleep(s);

	//清空控制台，防止留残影
	system("cls");

}





void backgroud(){
	//绘制边界
	for (size_t i = 0; i <= HIGH+1; i++)
	{
		if ( i == HIGH+1) {
			for (int j = 0; j < WIGHT+3; j++) {
				printf("+");
			}
		printf("\n");
		}
		else
		{
			for (int j = 0; j <= WIGHT+1; j++) {
					printf(" ");
			}
				printf("+\n");
		}
	}
}


void game() {
	while (1) {

	while (_kbhit()) {
		d = _getch();
	}


	//将光标移动到初始位置，绘制边界
	po[1].X = 0;
	po[1].Y = 0;
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[1]);
	backgroud();

		//判定蛇吃掉食物
		if (f.x == b.pos[0].x && f.y == b.pos[0].y) {
			b.size++;
			makefood();
		}


		//判断是否超出边界
		if (b.pos[0].x<0 || b.pos[0].x>WIGHT || b.pos[0].y<0 || b.pos[0].y>HIGH) {
			printf("游戏结束");
			break;
		}


		movesnake();

		char d1 = d;


		//当蛇头碰到身子时死亡
		for (size_t i =1;i <b.size;i++)
		{
			if (b.pos[0].x == b.pos[i].x && b.pos[0].y == b.pos[i].y) {
				printf("游戏结束");
					return;
			}
		}

	}
}



int main() {
	srand((unsigned int)time(NULL));

	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	snakestpos();
	makefood();
	game();
	return 0;
}
