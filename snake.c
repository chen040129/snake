#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"



void snakestpos() {
	//��ʼ���ߵ�λ��
	po[0].X = b.pos[0].x = WIGHT / 2;
	po[0].Y = b.pos[0].y = HIGH / 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[0]);
	printf("@");

};



void makefood() {
	//��ʼ��ʳ���λ��
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

	//����ƫ�Ʊ���
	int dx;
	int dy;

	///�ж��Ƿ�Ӽ����ϻ����ĸ�������ã��佫ֵ����char d
	while (_kbhit()) {
		d = _getch();
	}

	 //�ж������ַ������
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



	//���߲����ƶ�
	//�Ӵ��±굽С�±���ֵʱС���긳ֵ�������걣֤���ụ����Ⱦ
	for (int i = b.size; i > 0;i--) {
		b.pos[i].x = b.pos[i - 1].x;
		b.pos[i].y = b.pos[i - 1].y;
	}
	//�ƶ���꣬��size���ߵĳ��ȣ�����ѭ�������ҽ��ߵ������ӡ����
	for (int i = 1; i <= b.size; i++) {

		po[1].X = b.pos[i].x;
		po[1].Y = b.pos[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[1]);
		printf("*");
	}
	//��ӡʳ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[0]);
	printf("#");
	//�ź�����Խ�ǰ��Ĵ��븲�ǣ��������ͷ
	po[1].X = b.pos[0].x += dx;
	po[1].Y = b.pos[0].y += dy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[1]);
	printf("@");

	//����
	if(s>100){
	   s--;
	}

	//�趨�ٶ�
	Sleep(s);

	//��տ���̨����ֹ����Ӱ
	system("cls");

}





void backgroud(){
	//���Ʊ߽�
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


	//������ƶ�����ʼλ�ã����Ʊ߽�
	po[1].X = 0;
	po[1].Y = 0;
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po[1]);
	backgroud();

		//�ж��߳Ե�ʳ��
		if (f.x == b.pos[0].x && f.y == b.pos[0].y) {
			b.size++;
			makefood();
		}


		//�ж��Ƿ񳬳��߽�
		if (b.pos[0].x<0 || b.pos[0].x>WIGHT || b.pos[0].y<0 || b.pos[0].y>HIGH) {
			printf("��Ϸ����");
			break;
		}


		movesnake();

		char d1 = d;


		//����ͷ��������ʱ����
		for (size_t i =1;i <b.size;i++)
		{
			if (b.pos[0].x == b.pos[i].x && b.pos[0].y == b.pos[i].y) {
				printf("��Ϸ����");
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
