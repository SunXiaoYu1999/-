#include "stdafx.h"
#include "M.h"
#include <graphics.h>
#include <easyx.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

int  N_M = 20;                 // ������
int  N_E = 10;         // �߿���
int  N_B = 39;             // ÿ�з������

// ��ʼ��һ����Ϸ����
void Maze_Inti_Game()
{
	initgraph(1200,800);
//	setfillcolor(CYAN);                       // ������ʾ���������ɫ

//	HRGN rgn = CreateRectRgn(800,0,1200,800); // ����һ��������
//	setcliprgn(rgn);                          // ����rgn�������
//	DeleteObject(rgn);                        // ɾ��rgn������
//	solidrectangle(800, 0, 1200, 800);        // ��һ��ʵ�ĵľ���

	setbkcolor(RGB(50, 60, 25));                  // ����һ��������ɫ
	cleardevice();                                // �����Ļ

	IMAGE imag;
	loadimage(&imag,L"Back_1.jpg",400,800,0);
	putimage(800, 0, &imag);

// ���������ʾ
	setcolor(WHITE);
	setfillcolor(RGB(255,255,255));
	fillcircle(860, 530, 9);
	setcolor(RED);                    // ������ɫ
	settextstyle(25, 0, L"����");     // ���������С25��������
	setbkmode(TRANSPARENT);           // ͸�������屳�����
	outtextxy(902, 514, L":�յ�");

// �����յ���ʾ
	setcolor(WHITE);
	setfillcolor(RGB(255,255,0));
	fillcircle(860, 590, 9);
	setcolor(RED);                    // ������ɫ
	settextstyle(25, 0, L"����");     // ���������С25��������
	setbkmode(TRANSPARENT);           // ͸�������屳�����
	outtextxy(902, 575, L":���");

	setcolor(RGB(3,12,65));                    // ������ɫ
	settextstyle(60, 0, L"����");     // ���������С50��������
	setbkmode(TRANSPARENT);           // ͸�������屳�����
	outtextxy(945, 50, L"�Թ�");      // ��850,50,�ĵط��������
	RECT rect = {850,150,1150,750 };
	settextstyle(25, 0, L"����");     // ���������С50��������
	drawtext(_T("[��Ϸ˵��]\n\n����һ���Թ���Ϸ\n\nw   :��\n\ns   :��\n\na   :��\n\nd   :��\n\nesc :�˳�"), &rect, DT_WORDBREAK);

//	HRGN rgn_2 = CreateRectRgn(0, 0, 800 - N_E , N_E);    // ����һ��������
//	setcliprgn(rgn_2);                            // ����rgn�������
//	DeleteObject(rgn_2);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, 0, 800 - N_E, N_E);             // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                  // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_3 = CreateRectRgn(0, N_E, N_E, 800);    // ����һ��������
//	setcliprgn(rgn_3);                            // ����rgn�������
//	DeleteObject(rgn_3);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, N_E, N_E, 800);             // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                  // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_4 = CreateRectRgn(800 - N_E, 0, 800, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_4);                            // ����rgn�������
//	DeleteObject(rgn_4);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(800 - N_E, 0, 800, 800 - N_E);             // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                  // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_5 = CreateRectRgn(N_E, 800 - N_E, 800, 800);    // ����һ��������
//	setcliprgn(rgn_5);                            // ����rgn�������
//	DeleteObject(rgn_5);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(N_E, 800 - N_E, 800, 800);             // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                  // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_1 = CreateRectRgn(N_E, N_E, 800 - N_E, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_1);                            // ����rgn�������
//	DeleteObject(rgn_1);                          // ɾ��rgn������
//	solidrectangle(N_E, N_E, 800 - N_E, 800 - N_E);             // ��һ��ʵ�ĵľ���
	
}
// ��x,y����һ��С����
void Maze_Print_Box(int x, int y)
{
	x = x * N_M + N_E;
	y = y * N_M + N_E;
	setcolor(WHITE);                     // ����������ɫ
	setfillcolor(LIGHTGRAY);                 // ���������ɫ 
	fillrectangle(x + 1, y + 1, x + N_M - 1, y + N_M - 1);    // ����һ��������
}
// ��ӡ��Ϸ��㣬�յ㷽��
void Maze_Print_Start_End(int x_1, int y_1, int x_2, int y_2)
{
	x_1 = x_1 * N_M + N_E;
	x_2 = x_2 * N_M + N_E;
	y_1 = y_1 * N_M + N_E;
	y_2 = y_2 * N_M + N_E;
	setcolor(WHITE);
	setfillcolor(RGB(255, 255, 0));
	fillcircle(x_1 + N_M / 2, y_1 + N_M / 2, N_M / 2 - 1);

	setcolor(WHITE);
	setfillcolor(RGB(255,255,255));
	fillcircle(x_2 + N_M / 2, y_2 + N_M / 2, N_M / 2 - 1);
}
// �û������뷽����Ӧ������Ӧ������б任
void Maze_Game_Move(box_2 &A, char ch)
{
	switch (ch)
	{
	case 'w':
		A.y--;
		A.dir = 'w';
		break;
	case 'W':
		A.dir = 'w';
		A.y--;
		break;
	case 's':
		A.dir = 's';
		A.y++;
		break;
	case 'S':
		A.dir = 's';
		A.y++;
		break;
	case 'a':
		A.dir = 'a';
		A.x--;
		break;
	case 'A':
		A.dir = 'a';
		A.x--;
		break;
	case 'd':
		A.dir = 'd';
		A.x++;
		break;
	case 'D':
		A.dir = 'd';
		A.x++;
		break;
	default:
		break;
	}
}
// ��ӡ�û�����
void Maze_Print_user(int x, int y)
{
	x = x * N_M + N_E;
	y = y * N_M + N_E;
	setcolor(WHITE);
	setfillcolor(RGB(255,255,0));
	fillcircle(x + N_M / 2, y + N_M / 2, N_M / 2 - 1);
	
}
// ��ӡ����ɫ�Իָ�����
void Maze_Print_Clear(int x, int y)
{
	x = x * N_M + N_E;
	y = y * N_M + N_E;
	setcolor(RGB(50, 60, 25));
	setfillcolor(RGB(50, 60, 25));
	fillcircle(x + N_M / 2, y + N_M / 2, N_M / 2 - 1);
}
// ��ӡxyz�е��Թ���ͼ
void Maze_Print_Map(int xyz[][NUM_MAP])
{
	for (int i = 0; i < N_B; i++) {
		for (int j = 0; j < N_B; j++) {
			if (xyz[i][j] == 1)
				Maze_Print_Box(i, j);
		}
	}
}
// �жϵ�ǰ�����ǲ���ͨ·���Ƿ���true�����Ƿ���false�����˻�ԭ����
bool Maze_Is_Way(int Map[][NUM_MAP], box_2 &A)
{
	if (Map[A.x][A.y] == 1) {
		switch (A.dir)
		{
		case 'w':
			A.y++;
			break;
		case 's':
			A.y--;
			break;
		case 'a':
			A.x++;
			break;
		case 'd':
			A.x--;
			break;
		default:
			break;
		}
		return false;
	}
	return true;
}
// �Թ���Ϸ����
void Maze_Game()
{
	int MAP[NUM_MAP][NUM_MAP];
	time_t T_1, T_2;         // ����ʱ�䣬��¼�û���Ϸ��ʱ��
	char ch;                  			 // �û�����ķ���
	do {
		Maze_MakeMaze_Random_1(MAP, false);
		Maze_Inti_Game();                                // ��ʼ��һ����Ϸ���� 
		Maze_Print_Map(MAP);                             // ��ӡ�Թ���ͼ
		box_2 start,end,user;                            // ����һ����ʼ�㣬һ�������㣬һ���û��ṹ  
		Maze_Game_GetStartEnd(start, end, MAP);          // ������һ������յ�����
		user.x = start.x;              
		user.y = start.y;                                // �û������ʼ��Ϊ�������
		Maze_Print_Start_End(start.x, start.y, end.x, end.y); // ��ӡ������յ�����
		T_1 = time(NULL);                                     // ��õ�ǰϵͳʱ��
		while (!(user.x == end.x && user.y == end.y)) {
			box_2 temp;                              // ��¼��ǰ�ķ���
			temp.x = user.x;           
			temp.y = user.y;      
			ch = _getch();
			if (ch == 27)
				break;
			Maze_Game_Move(user, ch);                     // ���û�����ķ����λ�� 
			if (Maze_Is_Way(MAP, user))                   // �����һ��������ͨ·�������ԭ���ķ���
				Maze_Print_Clear(temp.x, temp.y);   
			Maze_Print_user(user.x, user.y);              // ��ӡ�û��������һ������
		}
		T_2 = time(NULL);
		if (ch == 27)
			break;
	} while(Maze_Init_GameEnd((int)T_2 - (int)T_1));
}
// ��Ϸ���ش��ڣ�����1��������һ�֡�������0����������Ϸ��
int Maze_Init_GameEnd(int Time)
{
	initgraph(480, 640);
	// ���ñ���ͼƬ
	IMAGE end;
	loadimage(&end,L"end.jpg",480, 640, 0);
	putimage(0, 0, &end);

	settextstyle(60, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(175, 50, L"���أ�");
	// �����������
	settextstyle(40, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(120, 150, L"������ʱ    ��");

	// ��Timeת��Ϊ��������ַ���
	settextstyle(40, 0, L"����");
	TCHAR s[5];                            
	swprintf_s(s, _T("%d"), Time);     
	outtextxy(290,150 , s);

	// ����button1��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(100, 250, 380, 350, 50, 50);
	// ��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(140, 275, L"����һ��");
	// ����button2��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(100, 450, 380, 550, 50, 50);
	//��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(140, 475, L"�����˵�");
	// ���������Ϣ
	int m_x, m_y;
	MOUSEMSG mou;
	while (true) {
		while (MouseHit()) {
			mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN) {
				m_x = mou.x;
				m_y = mou.y;
				if ((m_x >= 100 && m_x <= 380) && (m_y >= 250 && m_y <= 350)) {
					return 1;
				}
				else if ((m_x >= 100 && m_x <= 380) && (m_y >= 450 && m_y <= 550)) {
					return 0;
				}
			}
		}
	}
}
// �����ȡ��ʼ���������
void Maze_Game_GetStartEnd(box_2 &start, box_2 &end,int MAP[][NUM_MAP])
{
	srand((unsigned)time(NULL));
	do {
		do {
			start.x = rand() % (N_B - 2) + 1;
			start.y = rand() % (N_B - 2) + 1;
		} while (MAP[start.x][start.y] == 1);
		do {
			end.x = rand() % (N_B - 2) + 1;
			end.y = rand() % (N_B - 2) + 1;
		} while (MAP[end.x][end.y] == 1);
	} while (start.x == end.x && start.y == end.y);
}
// �������һ���Թ�����,MAPΪ�Թ����飬palyΪ�Ƿ���ʾ���ɹ���
void Maze_MakeMaze_Random(int MAP[][NUM_MAP], bool play)
{
	int T = 21;                                   // ��ʱʱ��
	box_2 start;
	Maze_MakeMaze_Random_init(MAP);                // ��ʼ��һ������ͨͼ
	if (play)                                      // �Ƿ���Ҫ��ʾ
		Maze_Print_Map(MAP);
	Maze_MakeMaze_Random_GetStart(start);  // ������һ����ʼλ��
	stock A; A.top = -1;                           // ����һ��ջ
	A.St = new box_1[(N_B-1)*(N_B-1)/4];
	box_1 temp;                                    // ����һ����������
	temp.x = start.x; temp.y = start.y; temp.dir = 0;  // temp��ʼ��
	for (int i = 0; i < 4; i++)
		temp.Dir[i] = i + 1;
	Maze_MakeMaze_Random_GetDir(temp.Dir);             // ����һ�������������
	Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], temp);     // ��ʼλ�ý�ջ
	MAP[start.x][start.y] = -1;                        // �߹���·�����Ϊ -1
	if (play) {
		Maze_MakeMaze_Random_PrintWay(start.x, start.y);
		Sleep(T);
	}
	int dir = A.St[A.top].dir;                       // ���������±꣬������ڼ�������
	int Dir = A.St[A.top].Dir[dir];                  // �����������ݣ���������
	int find, x, y;                                  // �ҵ�·����ǣ�����
	while (A.top > -1) { // ջ����ѭ��
		if (_kbhit()) {          // ��Ӽ��̼����Լӿ������ٶ�
			char ch = _getch();
			if (ch == 'q')
				T += 4;
			else if (ch == 'e')
				T -= 4;
		}
		find = 0;
		while (dir < 4 && find == 0) {               // ����һ�����߷���
			switch (Dir)
			{
			case 1:
				x = A.St[A.top].x - 2;
				y = A.St[A.top].y;
				break;
			case 2:
				x = A.St[A.top].x;
				y = A.St[A.top].y - 2;
				break;
			case 3:
				x = A.St[A.top].x + 2;
				y = A.St[A.top].y;
				break;
			case 4:
				x = A.St[A.top].x;
				y = A.St[A.top].y + 2;
				break;
			}
			if (x >= 0 && y >= 0 && x <= N_B - 1 && y <= N_B - 1 && MAP[x][y] == 0) {
				find = 1;
				if (play) {
					Maze_MakeMaze_Random_PrintWay((A.St[A.top].x + x) / 2, (A.St[A.top].y + y) / 2);
					if(T > 0)
						Sleep(T);
					Maze_MakeMaze_Random_PrintWay(x, y);
					if(T > 0)
						Sleep(T);
				}
			}
			else {
				dir++;
				Dir = A.St[A.top].Dir[dir];
			}	
		}
		if (find == 1) {
			A.St[A.top].dir = dir;                               // ����ֵ
			temp.x = x; temp.y = y; temp.dir = 0;
			Maze_MakeMaze_Random_GetDir(temp.Dir); 
			Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], temp);     // ��һ�����߷����ջ
			MAP[(A.St[A.top - 1].x + A.St[A.top].x)/2][(A.St[A.top - 1].y + A.St[A.top].y)/2] = -1;
			MAP[x][y] = -1;
			dir = A.St[A.top].dir;
			Dir = A.St[A.top].Dir[dir];                          
		}
		else {
			if (play) {
				Maze_MakeMaze_Random_PrintClean(A.St[A.top].x, A.St[A.top].y);
				if(T > 0)
					Sleep(T);
				if(A.top > 0)
					Maze_MakeMaze_Random_PrintClean((A.St[A.top - 1].x + A.St[A.top].x) / 2, (A.St[A.top - 1].y + A.St[A.top].y) / 2);
				if(T > 0)
					Sleep(T);
			}
			A.top--;
			if (A.top > -1) {
				dir = A.St[A.top].dir + 1;
				Dir = A.St[A.top].Dir[dir];
			}
		}
 	}
	for (int i = 0; i < N_B; i++) {
		for (int j = 0; j < N_B; j++) {
			if (MAP[i][j] == -1)
				MAP[i][j] = 0;
		}
	}
	delete[] A.St;
}
// ��ʼ���Թ���ͼΪ����ͨͼ
void Maze_MakeMaze_Random_init(int MAP[][NUM_MAP])
{
	for (int i = 0; i < N_B; i++) {
		for (int k = 0; k < N_B; k++) {
			if (i % 2 != 0 && k % 2 != 0)
				MAP[i][k] = 0;
			else
				MAP[i][k] = 1;
		}
	}
}
// ��ʾ����
void Maze_Meum_Play()
{
	int MAP[NUM_MAP][NUM_MAP];
	initgraph(1200, 800);

	setbkcolor(RGB(50, 60, 25));                         // ����һ��������ɫ
	cleardevice();

//	HRGN rgn = CreateRectRgn(800, 0, 1200, 800); // ����һ��������
//	setcliprgn(rgn);                          // ����rgn�������
//	DeleteObject(rgn);                        // ɾ��rgn������
											  //	solidrectangle(800, 0, 1200, 800);        // ��һ��ʵ�ĵľ���
	IMAGE imag;
	loadimage(&imag, L"Back_1.jpg", 400, 800, 0);
	putimage(800, 0, &imag);

	// ����button1��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 50, 1150, 100, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(895, 60, L"�����Թ�(��ʽһ)");

	// ����button2��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 150, 1150, 200, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(905, 160, L"�����Թ�(��ʽ��)");

	// ����button3��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 250, 1150, 300, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(940, 260, L"�������˵�");

	// ����Ϊ������ʾ����
//	HRGN rgn_1 = CreateRectRgn(0, 0, 800 - N_E, N_E);    // ����һ��������
//	setcliprgn(rgn_1);                            // ����rgn�������
//	DeleteObject(rgn_1);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, 0, 800 - N_E, N_E);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();                                // �ñ�����ɫ����

//	HRGN rgn_2 = CreateRectRgn(800 - N_E, 0, 800, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_2);                            // ����rgn�������
//	DeleteObject(rgn_2);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(800 - N_E, 0, 800, 800 - N_E);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_3 = CreateRectRgn(0, N_E, N_E, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_3);                            // ����rgn�������
//	DeleteObject(rgn_3);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, N_E, N_E, 800 - N_E);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_4 = CreateRectRgn(0, 800 - N_E, 800, 800);    // ����һ��������
//	setcliprgn(rgn_4);                            // ����rgn�������
//	DeleteObject(rgn_4);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, 800 - N_E, 800, 800);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();
	// ����Ϊ������
//	HRGN rgn_5 = CreateRectRgn(N_E, N_E, 800 - N_E, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_5);                            // ����rgn�������
//	DeleteObject(rgn_5);                          // ɾ��rgn������
//	solidrectangle(N_E, N_E, 800 - N_E, 800 - N_E);                // ��һ��ʵ�ĵľ���
	

	int flag = 0;
	int mouse;
	do {
		mouse = Maze_Slove_Mouse();                    // ��������Ϣ
		switch (mouse)
		{
		case 1:
			Maze_Map_clear();
			Maze_MakeMaze_Random(MAP, true);
			break;
		case 2:
			Maze_Map_clear();
			Maze_MakeMaze_Random_1(MAP, true);
			break;
		case 3:
			flag = 1;
			break;
		}
	} while (flag != 1);
}
// ������һ����ʼ����
void Maze_MakeMaze_Random_GetStart(box_2 &start)
{
	srand((unsigned)time(NULL));
	start.x = rand() % (N_B - 2) + 1;
	start.y = rand() % (N_B - 2) + 1;
	if (start.x % 2 == 0)
		start.x++;
	if (start.y % 2 == 0)
		start.y++;
}
// ��������������
void Maze_MakeMaze_Random_GetDir(int Dir[4])
{
	srand((unsigned)time(NULL));
	int p, temp;
	for (int i = 0; i < 77; i++) {
		p = rand() % 4;
		temp = Dir[0];
		Dir[0] = Dir[p];
		Dir[p] = temp;
	}
}
// ��ӡ��ʾ����
void Maze_MakeMaze_Random_PrintWay(int x, int y)
{
	x = x * N_M + N_E;
	y = y * N_M + N_E;
	setcolor(LIGHTBLUE);
	setfillcolor(LIGHTBLUE);
	fillrectangle(x + 1, y + 1, x + N_M - 1, y + N_M - 1);
}
// �����ʾ����
void Maze_MakeMaze_Random_PrintClean(int x, int y)
{
	x = x * N_M + N_E;
	y = y * N_M + N_E;
	setcolor(RGB(50, 60, 25));
	setfillcolor(RGB(50, 60, 25));
	fillrectangle(x + 1, y + 1, x + N_M - 1, y + N_M - 1);
}
// ��B��ֵ��A
void Maze_MakeMaze_Random_Fuzhi(box_1 &A, box_1 &B)
{
	A.x = B.x;
	A.y = B.y;
	A.dir = B.dir;
	for (int i = 0; i < 4; i++) {
		A.Dir[i] = B.Dir[i];
	}
}
// �˵�����
int Maze_inti()
{
	initgraph(600, 800);
	// �������˵�����ͼƬ
	IMAGE end;
	loadimage(&end, L"meum.jpg", 600, 800, 0);
	putimage(0, 0, &end);
	// ����
	settextstyle(70, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(200, 50, L"���˵�");

	// ����button1��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 150, 450, 250 , 50, 50);
	// ��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(200, 175, L"�Թ���Ϸ");

	// ����button2��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 300, 450, 400, 50, 50);
	// ��ť����
	settextstyle(45, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(165,325, L"�����Թ���ʾ");

	// ����button3��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 450, 450, 550, 50, 50);
	// ��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(220, 475, L"DFS���");

	// ����button4��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 600, 450, 700, 50, 50);
	// ��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(220, 625, L"BFS���");

	// ����button5��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(425, 725, 575, 775, 50, 50);
	// ��ť����
	settextstyle(25, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(480, 735, L"�˳�");

	// ����button5��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(25, 725, 175, 775, 50, 50);
	// ��ť����
	settextstyle(25, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(65, 735, L"�ı��С");

	// ���������Ϣ
	int m_x, m_y;
	MOUSEMSG mou;
	while (true) {
		while (MouseHit()) {
			mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN) {
				m_x = mou.x;
				m_y = mou.y;
				if ((m_x >= 150 && m_x <= 450) && (m_y >= 150 && m_y <= 250)) {
					return 1;
				}
				else if ((m_x >= 150 && m_x <= 450) && (m_y >= 300 && m_y <= 400)) {
					return 2;
				}
				else if ((m_x >= 150 && m_x <= 450) && (m_y >= 450 && m_y <= 550)) {
					return 3;
				}
				else if ((m_x >= 150 && m_x <= 450) && (m_y >= 600 && m_y <= 700 )) {
					return 4;
				}
				else if ((m_x >= 425 && m_x <= 575) && (m_y >= 725 && m_y <= 775)) {
					return 0;
				}
				else if ((m_x >= 25 && m_x <= 175) && (m_y >= 725 && m_y <= 775)) {
					return 5;
				}
			}
		}
	}
}
// ���˵��
void Maze()
{
	int flag;
	mciSendString(L"open MazeMusic.mp3 alias ARNO", 0, 0, 0);
	mciSendString(L"play ARNO repeat", 0, 0, 0);
	Maze_Caloulater_Num();
	do {
		flag = Maze_inti();
		switch (flag)
		{
		case 1:
			Maze_Game();
			break;
		case 2:
			Maze_Meum_Play();
			break;
		case 3:
			Maze_DFS();
			break;
		case 4:
			Maze_BFS();
			break;
		case 5:
			N_M = Maze_Input();
			Maze_Caloulater_Num();
			break;
		default:
			break;
		}
	} while (flag != 0);
	
}
// DFS ����Թ�
void Maze_DFS()
{
	int MAP[NUM_MAP][NUM_MAP];
	initgraph(1200, 800);
//	HRGN rgn = CreateRectRgn(800, 0, 1200, 800); // ����һ��������
//	setcliprgn(rgn);                          // ����rgn�������
//	DeleteObject(rgn);                        // ɾ��rgn������
//	solidrectangle(800, 0, 1200, 800);        // ��һ��ʵ�ĵľ���
	setbkcolor(RGB(50, 60, 25));                         // ����һ��������ɫ
	cleardevice();

	IMAGE imag;
	loadimage(&imag, L"Back_1.jpg", 400, 800, 0);
	putimage(800, 0, &imag);

	Maze_DFS_Button();                            // ����Ӧ�ĵط�����Button��ť

	// ����Ϊ������ʾ����
//	HRGN rgn_1 = CreateRectRgn(0, 0, 800 - N_E, N_E);    // ����һ��������
//	setcliprgn(rgn_1);                            // ����rgn�������
//	DeleteObject(rgn_1);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, 0, 800 - N_E, N_E);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();                                // �ñ�����ɫ����

//	HRGN rgn_2 = CreateRectRgn(800 - N_E, 0, 800, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_2);                            // ����rgn�������
//	DeleteObject(rgn_2);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(800 - N_E, 0, 800, 800 - N_E);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_3 = CreateRectRgn(0, N_E, N_E, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_3);                            // ����rgn�������
//	DeleteObject(rgn_3);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, N_E, N_E, 800 - N_E);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_4 = CreateRectRgn(0, 800 - N_E, 800, 800);    // ����һ��������
//	setcliprgn(rgn_4);                            // ����rgn�������
//	DeleteObject(rgn_4);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, 800 - N_E, 800, 800);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();
	// ����Ϊ������
//	HRGN rgn_5 = CreateRectRgn(N_E, N_E, 800 - N_E, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_5);                            // ����rgn�������
//	DeleteObject(rgn_5);                          // ɾ��rgn������
//	solidrectangle(N_E, N_E, 800 - N_E, 800 - N_E);                // ��һ��ʵ�ĵľ���

	int flag = 0;
	int mouse;
	do {
		mouse = Maze_Slove_Mouse();                    // ��������Ϣ
		switch (mouse)
		{
		case 1:
			Maze_Map_clear();
			Maze_MakeMaze_Random_1(MAP, false);
			Maze_Print_Map(MAP);
			flag = 1;
			break;
		case 2:
			Maze_Map_clear();
			Maze_MakeMaze_Random_1(MAP, true);
			flag = 1;
			break;
		case 3:
			if (flag == 1) {
				Maze_Map_clear();
				Maze_DFS_Solve(MAP, true, true);
			}
			else {
				Maze_Map_clear();
				Maze_DFS_Solve(MAP, true, false);
			}
			break;
		}
	} while (mouse);

	
}
// BFS ����Թ�
void Maze_BFS()
{
	int MAP[NUM_MAP][NUM_MAP];
	initgraph(1200, 800);
//	HRGN rgn = CreateRectRgn(800, 0, 1200, 800); // ����һ��������
//	setcliprgn(rgn);                          // ����rgn�������
//	DeleteObject(rgn);                        // ɾ��rgn������
//	solidrectangle(800, 0, 1200, 800);        // ��һ��ʵ�ĵľ���
	
	setbkcolor(RGB(50, 60, 25));                         // ����һ��������ɫ
	cleardevice();

	IMAGE imag;
	loadimage(&imag, L"Back_1.jpg", 400, 800, 0);
	putimage(800, 0, &imag);

	Maze_BFS_Button();                            // ����Ӧ�ĵط�����Button��ť                 // �ñ�����ɫ����

												  // ����Ϊ������ʾ����
//	HRGN rgn_1 = CreateRectRgn(0, 0, 800 - N_E, N_E);    // ����һ��������
//	setcliprgn(rgn_1);                            // ����rgn�������
//	DeleteObject(rgn_1);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, 0, 800 - N_E, N_E);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();                                // �ñ�����ɫ����

//	HRGN rgn_2 = CreateRectRgn(800 - N_E, 0, 800, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_2);                            // ����rgn�������
//	DeleteObject(rgn_2);                          // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(800 - N_E, 0, 800, 800 - N_E);                // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_3 = CreateRectRgn(0, N_E, N_E, 800 - N_E);    // ����һ��������
//	setcliprgn(rgn_3);                                 // ����rgn�������
//	DeleteObject(rgn_3);                               // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, N_E, N_E, 800 - N_E);                    // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                              // ����һ��������ɫ
//	cleardevice();

//	HRGN rgn_4 = CreateRectRgn(0, 800 - N_E, 800, 800);       // ����һ��������
//	setcliprgn(rgn_4);                                  // ����rgn�������
//	DeleteObject(rgn_4);                                // ɾ��rgn������
	setfillcolor(LIGHTRED);
	solidrectangle(0, 800 - N_E, 800, 800);                   // ��һ��ʵ�ĵľ���
//	setbkcolor(LIGHTRED);                               // ����һ��������ɫ
//	cleardevice();
	// ����Ϊ������
//	HRGN rgn_5 = CreateRectRgn(N_E, N_E, 800 - N_E, 800 - N_E);        // ����һ��������
//	setcliprgn(rgn_5);                                   // ����rgn�������
//	DeleteObject(rgn_5);                                 // ɾ��rgn������
//	solidrectangle(N_E, N_E, 800 - N_E, 800 - N_E);                    // ��һ��ʵ�ĵľ���
	

	int flag = 0;
	int mouse;
	do {
		mouse = Maze_Slove_Mouse();                    // ��������Ϣ
		switch (mouse)
		{
		case 1:
			Maze_Map_clear();
			Maze_MakeMaze_Random_1(MAP, false);
			Maze_Print_Map(MAP);
			flag = 1;
			break;
		case 2:
			Maze_Map_clear();
			Maze_MakeMaze_Random_1(MAP, true);
			flag = 1;
			break;
		case 3:
			if (flag == 1) {
				Maze_Map_clear();
				Maze_BFS_Solve(MAP, true, true);
			}
			else {
				Maze_Map_clear();
				Maze_BFS_Solve(MAP, true, false);
			}
			break;
		}
	} while (mouse);
}
// DFS��� play �Ƿ���Ҫ��ʾ�����̣�CreateMaze�Ƿ���Ҫ�������һ���Թ�
void Maze_DFS_Solve(int MAP[][NUM_MAP], bool play,bool CreateMaze)
{
	int T = 220;                        // ��ʱ������
	box_1 start, end, temp;
	if (CreateMaze == false)
		Maze_MakeMaze_Random_1(MAP, false);    // �������һ���Թ�
	Maze_Print_Map(MAP);                     // ��ӡ�Թ�����
	stock A; A.top = -1;                 // ����һ��ջ
	A.St = new box_1[(N_B - 1)*(N_B - 1) / 4];
	Maze_Solve_GetStartEnd(start, end, MAP);           // ������һ�������һ���յ�
	if (play) {
		Maze_Print_Start_End(start.x, start.y, end.x, end.y);  // ��ӡ������յ�
		Sleep(2000);
	}
	temp.dir = 1;                                          // tempΪ��������
	Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], start);      // ��Ԫ�ؽ�ջ
	if (play) {
		Maze_MakeMaze_Random_PrintWay(start.x, start.y);
		Sleep(T);
	}
	MAP[start.x][start.y] = -1;                           // �����Ԫ���Ѿ��߹�
	while (A.top > -1 && !(A.St[A.top].x == end.x && A.St[A.top].y == end.y)) {
		if (_kbhit()) {          // ��Ӽ��̼����Լӿ������ٶ�
			char ch = _getch();
			if (ch == 'q')
				T += 50;
			else if (ch == 'e' && T > 51)
				T -= 50;
		}
		int find = 0;                                      // ����Ƿ��ҵ����߷���
		while (temp.dir < 5 && find == 0) {
			switch (temp.dir)
			{
			case 1:
				temp.x = A.St[A.top].x - 1;
				temp.y = A.St[A.top].y;
				break;
			case 2:
				temp.x = A.St[A.top].x;
				temp.y = A.St[A.top].y - 1;
				break;
			case 3:
				temp.x = A.St[A.top].x + 1;
				temp.y = A.St[A.top].y;
				break;
			case 4:
				temp.x = A.St[A.top].x;
				temp.y = A.St[A.top].y + 1;
				break;
			}
			if (temp.x > 0 && temp.y > 0 && temp.x < N_B - 1 && temp.y < N_B - 1 && MAP[temp.x][temp.y] == 0) {
				find = 1;
			}
			else
				temp.dir++;
		}
		if (find == 1) {
			A.St[A.top].dir = temp.dir;
			Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], temp);
			if (play) {
				Maze_MakeMaze_Random_PrintWay(temp.x, temp.y);
				Sleep(T);
			}
			temp.dir = 1;
			MAP[temp.x][temp.y] = -1;
		}
		else {
			MAP[A.St[A.top].x][A.St[A.top].y] = 0;
			if (play) {
				Maze_MakeMaze_Random_PrintClean(A.St[A.top].x, A.St[A.top].y);
				Sleep(T);
			}
			temp.dir = A.St[--A.top].dir + 1;
		}
	}
	for (int i = 0; i <= A.top; i++)
		MAP[A.St[i].x][A.St[i].y] = 0;
	delete[] A.St;
}
// BFS��� play �Ƿ���Ҫ��ʾ�����̣�CreateMaze�Ƿ���Ҫ�������һ���Թ�
void Maze_BFS_Solve(int MAP[][NUM_MAP], bool play, bool CreateMaze)
{
	int T = 110; // ��ʱ������
	if (CreateMaze == false)
		Maze_MakeMaze_Random_1(MAP, false);          // �������һ���Թ�
	Maze_Print_Map(MAP);
	queue A;
	A.prior = -1; A.rear = -1;                      // ���岢�ҳ�ʼ��һ������
	box_1 temp, start, end;                            // ����������յ�͵�������
	Maze_Solve_GetStartEnd(start, end, MAP);           // ������һ�������һ���յ�
	Maze_MakeMaze_Random_Fuzhi(A.Qu[++A.rear], start);      // ��Ԫ�ؽ���

	A.Qu[A.rear].dir = -1;

	MAP[A.Qu[A.rear].x][A.Qu[A.rear].y] = -1;                //  ����Ԫ�ر��
	if (play) {
		Maze_Print_Start_End(start.x, start.y, end.x, end.y);  // ��ӡ������յ�
		Sleep(2000);
	}
	if (play) {
		Maze_MakeMaze_Random_PrintWay(start.x, start.y);           // ��ӡ��Ԫ��
		Sleep(T);
	}
	while (A.rear != A.prior) {
		if (_kbhit()) {          // ��Ӽ��̼����Լӿ������ٶ�
			char ch = _getch();
			if (ch == 'q')
				T += 10;
			else if (ch == 'e' && T > 11)
				T -= 10;
		}
		A.prior++;                            // ��Ԫ�س���
		int find = 0;
		for (int i = 1; i <= 4; i++) {
			switch (i) {
			case 1:
				temp.x = A.Qu[A.prior].x - 1;
				temp.y = A.Qu[A.prior].y;
				temp.dir = A.prior;
				break;
			case 2:
				temp.x = A.Qu[A.prior].x;
				temp.y = A.Qu[A.prior].y - 1;
				temp.dir = A.prior;
				break;
			case 3:
				temp.x = A.Qu[A.prior].x + 1;
				temp.y = A.Qu[A.prior].y;
				temp.dir = A.prior;
				break;
			case 4:
				temp.x = A.Qu[A.prior].x;
				temp.y = A.Qu[A.prior].y + 1;
				temp.dir = A.prior;
				break;
			}
			if (temp.x > 0 && temp.y > 0 && temp.x < N_B - 1 && temp.y < N_B - 1 && MAP[temp.x][temp.y] == 0) {
				Maze_MakeMaze_Random_Fuzhi(A.Qu[++A.rear], temp);     // �ҵ���Ԫ�ض�
				if (play) {
					Maze_MakeMaze_Random_PrintWay(temp.x, temp.y);
					Sleep(T);
				}
				MAP[temp.x][temp.y] = -1;
				if (A.Qu[A.rear].x == end.x && A.Qu[A.rear].y == end.y) {
					find = 1;
					break;
				}
			}
		}
		if (find == 1)
			break;
	}
	Sleep(2000);
//	for (int i = A.rear; i >= 0; i--) {
//		if (play) {
//			Maze_MakeMaze_Random_PrintClean(A.Qu[i].x, A.Qu[i].y);
//			Maze_Print_Start_End(start.x, start.y, end.x, end.y);
//			if (T < 1000)
//				Sleep(T);
//		}
//		MAP[A.Qu[i].x][A.Qu[i].y] = 0;
//	}
	int p = A.rear;
	if (play) {
		for (; p > -1;) {
			int temp = p;
			p = A.Qu[p].dir;
			A.Qu[temp].dir = -1;
			
		}
	}
	for (int i = A.rear; i >= 0; i--) {
				if (play) {
					if(A.Qu[i].dir != -1)
						Maze_MakeMaze_Random_PrintClean(A.Qu[i].x, A.Qu[i].y);
					if (T < 1000)
						Sleep(T);
				}
		MAP[A.Qu[i].x][A.Qu[i].y] = 0;
	}

	/*
	if (play) {
		for (; p > 0 ;) {
			Maze_MakeMaze_Random_PrintWay(A.Qu[p].x,A.Qu[p].y);
			if (T < 1000)
				Sleep(T);
			p = A.Qu[p].dir;
		}
	}
	if(play)
		Maze_MakeMaze_Random_PrintWay(A.Qu[0].x, A.Qu[0].y);
	*/
}
// �Թ����ʱ����ʼ�����ȡ
void Maze_Solve_GetStartEnd(box_1 &start, box_1 &end,int MAP[][NUM_MAP])
{
	srand((unsigned)time(NULL));
	do {
		do {
			start.x = rand() % (N_B - 2) + 1;
			start.y = rand() % (N_B - 2) + 1;
		} while (MAP[start.x][start.y] == 1);
		do {
			end.x = rand() % (N_B - 2) + 1;
			end.y = rand() % (N_B - 2) + 1;
		} while (MAP[end.x][end.y] == 1);
	} while (start.x == end.x && start.y == end.y);
}
//  BFS����İ�ťͼ��
void Maze_DFS_Button()
{
	// ����button1��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 50, 1150, 100, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(895, 60 , L"�����Թ�(����ʾ����)");

	// ����button2��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 150, 1150, 200, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(905, 160, L"�����Թ�(��ʾ����)");

	// ����button3��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 250, 1150, 300, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(930, 260, L"DFS������");

	// ����button4��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 350, 1150, 400, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(945, 360, L"�������˵�");
}
// DFS��BFS�����������
int Maze_Slove_Mouse()
{
	int m_x, m_y;
	MOUSEMSG msg;
	while (true) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				m_x = msg.x;
				m_y = msg.y;
				if ((m_x >= 850 && m_x <= 1150) && (m_y >= 50 && m_y <= 100)) {
					return 1;
				}
				else if ((m_x >= 850 && m_x <= 1150) && (m_y >= 150 && m_y <= 200)) {
					return 2;
				}
				else if ((m_x >= 850 && m_x <= 1150) && (m_y >= 250 && m_y <= 300)) {
					return 3;
				}
				else if ((m_x >= 850 && m_x <= 1150) && (m_y >= 350 && m_y <= 400)) {
					return 0;
				}
			}
		}
	}
}
// BFS����İ�ťͼ��
void Maze_BFS_Button()
{
	// ����button1��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 50, 1150, 100, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(895, 60, L"�����Թ�(����ʾ����)");

	// ����button2��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 150, 1150, 200, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(905, 160, L"�����Թ�(��ʾ����)");

	// ����button3��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 250, 1150, 300, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(930, 260, L"BFS������");

	// ����button4��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 350, 1150, 400, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(945, 360, L"�������˵�");
}/********************************************************************
/*�����ǵڶ��������Թ��ķ���*/
void Maze_MakeMaze_Random_1(int MAP[][NUM_MAP], bool play)
{
	int T = 210;
	srand((unsigned)time(NULL));
	Maze_MakeMaze_Random_init(MAP);
	if(play)
		Maze_Print_Map(MAP);
	box_1 temp, start;
	start.x = rand() % (N_B - 4) + 1;
	start.y = rand() % (N_B - 4) + 1;
	if (start.x % 2 == 0)
		start.x++;
	if (start.y % 2 == 0)
		start.y++;
	temp.x = start.x;
	temp.y = start.y;

	MAP[start.x][start.y] = -1;
	box_1 *A = new box_1[118008];
	int p = -1, q;
	do{
		if (_kbhit()) {          // ��Ӽ��̼����Լӿ������ٶ�
			char ch = _getch();
			if (ch == 'q')
				T += 50;
			else if (ch == 'e')
				T -= 50;
		}
		Maze_MakeMaze_Random_1_FindWall(temp, MAP, A, p);
		q = rand() % (p + 1);
		if (Maze_MakeMaze_Random_1_FindWay(q, A,MAP,temp)) {
			MAP[temp.x][temp.y] = -1;
			if (play) {
				Maze_MakeMaze_Random_PrintClean(A[q].x, A[q].y);
				if(T > 0)
					Sleep(T);
			}
			MAP[A[q].x][A[q].y] = -1;
		}
		Maze_MakeMaze_Random_1_Dele(q, A,p);	
	} while (p > -1);
	for (int i = 0; i < N_B; i++) {
		for (int j = 0; j < N_B; j++) {
			if (MAP[i][j] == -1)
				MAP[i][j] = 0;
			else
				MAP[i][j] = 1;
		}
	}
	if(!play)
		Maze_Print_Map(MAP); // ��ӡ��ͼ 
	delete[] A;
}

void Maze_MakeMaze_Random_1_FindWall(box_1 temp,int MAP[][NUM_MAP],box_1 *A,int &p)
{
	int x, y;
	for (int i = 1; i <= 4; i++) {
		switch (i)
		{
		case 1:
			x = temp.x + 1;
			y = temp.y;
			break;
		case 2:
			x = temp.x;
			y = temp.y + 1;
			break;
		case 3:
			x = temp.x - 1;
			y = temp.y;
			break;
		case 4:
			x = temp.x;
			y = temp.y - 1;
			break;
		}
		if (x > 0 && y > 0 && x < N_B - 1 && y < N_B - 1 && MAP[x][y] == 1) {
			A[++p].x = x;
			A[p].y = y;
			MAP[x][y] = 2;
		}
	}
}

bool Maze_MakeMaze_Random_1_FindWay(int q, box_1 *A,int MAP[][NUM_MAP],box_1 &tem)
{
	int x, y;
	box_1 temp;
	temp.x = A[q].x;
	temp.y = A[q].y;
	for (int i = 1; i <= 4; i++) {
		switch (i)
		{
		case 1:
			x = temp.x + 1;
			y = temp.y;
			break;
		case 2:
			x = temp.x;
			y = temp.y + 1;
			break;
		case 3:
			x = temp.x - 1;
			y = temp.y;
			break;
		case 4:
			x = temp.x;
			y = temp.y - 1;
			break;
		}
		if (x > 0 && y > 0 && x < N_B - 1 && y < N_B - 1 && MAP[x][y] == 0) {
			tem.x = x;
			tem.y = y;
			return true;
		}
	}
	return false;
}

void Maze_MakeMaze_Random_1_Dele(int q,box_1 *A,int &p)
{
	for (int i = q; i < p; i++) {
		A[i] = A[i + 1];
	}
	p--;
}
/*�����ǵڶ��������Թ��ķ���*/
void Maze_Caloulater_Num()
{
	int n = 800 / N_M;
	if (n % 2 == 0) {
		N_B = n - 1;
		N_E = (800 - N_B * N_M) / 2;
	}
	else {
		N_B = n;
		N_E = (800 - N_B * N_M) / 2;
	}
}

int Maze_Input()
{
	WCHAR s[5];
	InputBox(s, 4, L"�Թ�����ռ�������أ�", L"����", L"20", 300, 2, true);
	int i, n = 0, sum = 0, temp;
	int A[3] = { 1,10,100 };
	for (i = 0; s[i] != '\0'; i++);
	for (--i; i >= n; i--, n++) {
		temp = s[i];
		s[i] = s[n];
		s[n] = temp;
	}
	for (i = 0; s[i] != '\0'; i++) {
		sum += (s[i] - 48)*A[i];
	}
	return sum;
}

void Maze_Map_clear()
{
	setfillcolor(RGB(50, 60, 25));
	solidrectangle(N_E, N_E, 800 - N_E, 800 - N_E);
}
