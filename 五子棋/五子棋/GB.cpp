/**************������С��Ϸ
**  MAP �������̣�MAP[i][j] = 1����˴���һ�����죬2������壬0����û��
**
**
**
****/
#include "stdafx.h"
#include "GB.h"
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
// ��Ϸ����
void GoBang_GameInterFace()
{
	initgraph(902, 702);
	setbkcolor(RGB(255, 150, 150));       //��������ɫ 
	cleardevice();

	IMAGE temp, temp1;
	loadimage(&temp, L"������.jpg", 600, 99, false);
	putimage(300, 0, &temp);

	loadimage(&temp1, L"�û�1.jpg", 300, 700, false);
	putimage(0, 0, &temp1);

	setfillcolor(RGB(206,175,175));      // ���̱�����ɫ
	solidrectangle(300, 100, 900, 700);

	setlinecolor(RGB(0, 0, 0));         // ������ɫ

	for (int x = 300; x <= 900; x += 40) {
		line(x, 100, x, 700);
	}
	for (int y = 100; y <= 700; y += 40) {
		line(300, y, 900, y);
	}
}
// ��Ϸ�߼�
void GoBang_1()
{
	int MAP[15][15] = { 0 };
	GoBang_GameInterFace();
	POS T = { 1,1 };
	COLOR White = { 255,255,255 };             // ��ɫ����
	COLOR Black = { 0,0,0 };                   // ��ɫ����
	MOUSE_ARRAY MOU;                       // �������
	MOU.len = 225;
	GoBang_InitMouseArray(MOU);
	int count = 0;
	while (count <= 225)
	{
		count++;
		do {
			T = GoBang_MouseReturn(MOU);
		} while (MAP[T.x][T.y] != 0);
		if (count % 2 == 1) {
			MAP[T.x][T.y] = 1;
			GoBang_DrawPiece(T.x, T.y, White);
		}
		else {
			MAP[T.x][T.y] = 2;
			GoBang_DrawPiece(T.x, T.y, Black);
		}

		if (GoBang_GameWin(MAP,T,(count % 2))) {
			int reply;
			if (count % 2 == 0) {
				Sleep(2000);
				reply = GoBang_GameEnd(L"����ʤ��");
			}
			else {
				Sleep(2000);

				reply = GoBang_GameEnd(L"����ʤ��");
			}
			if (reply == 1)
				break;
			else 
			{
				count = 0;
				memset(MAP, 0, 225 * sizeof(int));
				GoBang_GameInterFace();
			}
		}
	}
}
// ������
void GoBang_DrawPiece(int x, int y, COLOR C)
{
	x *= 40;
	y *= 40;
	x += 300 + 20;
	y += 100 + 20;
	setfillcolor(RGB(C.R, C.G, C.B));
	solidcircle(x, y, 15);
}
// �����Ӧ����
POS GoBang_MouseReturn(MOUSE_ARRAY &MOU)
{
	MOUSEMSG mou;
	POS temp;
	while (true)
	{
		if(MouseHit())
		{
			mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN)
			{
				for (int i = 0; i < MOU.len; i++)
				{
					if (mou.x >= MOU.array[i].x_l && mou.x <= MOU.array[i].x_h)
					{
						if (mou.y >= MOU.array[i].y_l && mou.y <= MOU.array[i].y_h)
						{
							temp.y = i % 15;
							temp.x = i / 15;
							return temp;
						}
					}
				}
			}
		}
	}
}
// ��ʼ���������
void GoBang_InitMouseArray(MOUSE_ARRAY &MOU)
{
	for (int x = 300,i = 0; x < 900; x += 40)
	{
		for (int y = 100; y < 700; y += 40)
		{
			MOU.array[i].x_l = x;
			MOU.array[i].x_h = x + 40;
			MOU.array[i].y_l = y;
			MOU.array[i].y_h = y + 40;
			i++;
		}
	}
}
// �жϵ�ǰλ����û��Ӯ,user = 0��������壬user = 1�������
int GoBang_GameWin(int MAP[][15], POS pos, int user)
{
	POS temp;
	if (user == 0)
		user = 2;
	POS Dir[4][2] = { 
		{{ 1 , 0 }  ,{ -1 , 0 }},
		{{ 0 , 1 }  ,{  0 ,-1 }},
		{{ 1 ,-1 }  ,{ -1 , 1 }},
		{{ 1 , 1 }  ,{ -1 ,-1 }} 
	};
	for (int i = 0; i < 4; i++) {
		int count = 0;
		temp = pos;
		do{
			temp.x += Dir[i][0].x;
			temp.y += Dir[i][0].y;
			if (MAP[temp.x][temp.y] == user)
				count++;
			else
				break;
		} while (temp.x >=0 && temp.x < 15 && temp.y >= 0 && temp.y < 15 );
		temp = pos;
		do {
			temp.x += Dir[i][1].x;
			temp.y += Dir[i][1].y;
			if (MAP[temp.x][temp.y] == user)
				count++;
			else
				break;
		} while (temp.x >= 0 && temp.x < 15 && temp.y >= 0 && temp.y < 15);
		if (count == 4)
			return 1;
	}
	return 0;
}
// ��Ϸ��������
int GoBang_GameEnd(const wchar_t *str)
{
	initgraph(480, 640);

	setbkcolor(RGB(246,146,212));
	cleardevice();

	setfillcolor(RGB(255,255,255));
	solidroundrect(120, 250, 360, 320, 200,200);
	solidroundrect(120, 400, 360, 470,200, 200);

	settextcolor(RGB(63, 150, 235));
	settextstyle(30, 0, L"����", 0, 0, FW_BLACK, 0, 0, 0);
	setbkmode(TRANSPARENT);
	outtextxy(182,270, L"���ز˵�");

	settextcolor(RGB(63, 150, 235));
	settextstyle(30, 0, L"����", 0, 0, FW_BLACK, 0, 0, 0);
	setbkmode(TRANSPARENT);
	outtextxy(182, 420, L"����һ��");

	MOUSEMSG mou;
	srand((unsigned)time(NULL));
	while (true)
	{
		int R = rand() % 256;
		int G = rand() % 256;
		int B = rand() % 256;
		int T = rand() % 100 + 75;
		settextcolor(RGB(R, G, B));
		settextstyle(60, 0, L"����", 0, 0, FW_BLACK, 0, 0, 0);
		setbkmode(TRANSPARENT);
		outtextxy(110, 50, str);
		while (MouseHit())
		{
			mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN)
			{
				if (mou.x > 120 && mou.x < 360 && mou.y > 250 && mou.y < 320)
					return 1;
				if (mou.x > 120 && mou.x < 360 && mou.y > 400 && mou.y < 470)
					return 2;
			}
		}
		Sleep(T);
	}
}
// ��Ϸ�˵�����
int GoBang_Maze()
{
	initgraph(500, 700);
	setbkcolor(RGB(236,112,161));
	cleardevice();

	settextcolor(RGB(213,234,34));
	setbkmode(TRANSPARENT);
	settextstyle(100, 0, L"�����п�", 0, 0, 900, 0, 0, 0);
	outtextxy(100, 50, L"���˵�");

	setfillcolor(RGB(213,220,219));
	solidroundrect(125, 250, 375, 330, 200, 200);

	setfillcolor(RGB(213, 220, 219));
	solidroundrect(125, 400, 375, 480, 200, 200);

	setfillcolor(RGB(213, 220, 219));
	solidroundrect(125, 550, 375, 630, 200, 200);

	settextcolor(RGB(150, 170, 242));
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, L"�����п�", 0, 0, 900, 0, 0, 0);
	outtextxy(150, 265, L"˫�˶�ս");

	settextcolor(RGB(150, 170, 242));
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, L"�����п�", 0, 0, 900, 0, 0, 0);
	outtextxy(150, 415, L"�˻���ս");

	settextcolor(RGB(150, 170, 242));
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, L"�����п�", 0, 0, 900, 0, 0, 0);
	outtextxy(150, 565, L"�˳���Ϸ");

	MOUSEMSG mou;
	while (true)
	{
		while (MouseHit())
		{
			mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN)
			{
				if (mou.x > 125 && mou.x < 375 && mou.y > 250 && mou.y < 330)
					return 1;
				if (mou.x > 125 && mou.x < 375 && mou.y > 400 && mou.y < 480)
					return 2;
				if (mou.x > 125 && mou.x < 375 && mou.y > 550 && mou.y < 630)
					return 0;
			}
		}
	}
	return 0;
}
// �˵�����
void GoBang()
{
	int re;
	do {
		re = GoBang_Maze();
		switch (re)
		{
		case 1:
			GoBang_1();
			break;
		case 2:
			GoBang_2();
			break;
		}
	} while (re != 0);
}

void GoBang_2()
{
	int MAP[15][15] = { 0 };
	GoBang_GameInterFace();
	POS T = { 1,1 };
	COLOR White = { 255,255,255 };             // ��ɫ����
	COLOR Black = { 0,0,0 };                   // ��ɫ����
	MOUSE_ARRAY MOU;                       // �������
	MOU.len = 225;
	GoBang_InitMouseArray(MOU);
	int temp,max;              // ��¼���Ȩֵ
	int count = 0;
	while (count <= 225)
	{
		count++;
		if (count % 2 == 1)
		{
			do {
				T = GoBang_MouseReturn(MOU);
			} while (MAP[T.x][T.y] != 0);
		}
		else
		{
			max = 0;
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 15; j++)
				{
					if (MAP[i][j] == 0)
					{
						temp = GoBang_CalculateValue(MAP, { i,j }, 2); // ����Ϊ���壬����user = 2��
						if (max <= temp)
						{
							max = temp;
							T.x = i;
							T.y = j;
						}
					}
				}
			}
		}
		if (count % 2 == 1) {
			MAP[T.x][T.y] = 1;
			GoBang_DrawPiece(T.x, T.y, White);
		}
		else {
			MAP[T.x][T.y] = 2;
			Sleep(500);
			GoBang_DrawPiece(T.x, T.y, Black);
		}
		if (GoBang_GameWin(MAP, T, (count % 2))) {
			int reply;
			if (count % 2 == 0) {
				Sleep(2000);
				reply = GoBang_GameEnd(L"����ʤ��");
			}
			else {
				reply = GoBang_GameEnd(L"����ʤ��");
				Sleep(2000);
			}
			if (reply == 1)
				break;
			else
			{
				count = 0;
				memset(MAP, 0, 225 * sizeof(int));
				GoBang_GameInterFace();
			}
		}
	}
}
// ����temp���Ȩ�أ������أ�userΪ���Ե���ɫ
int GoBang_CalculateValue(int MAP[][15], POS temp, int user)
{
	int type, SumOfValue = 0;
	for (int D = 1; D <= 4; D++)                    // �ĸ�����ͳ�Ƶ�ǰ���Ȩֵ
	{
		type = GoBang_JudgeType(MAP, temp, user, D,false);
		SumOfValue += GoBang_ValueOfType(type);
		if (user == 1)
			user = 2;
		else
			user = 1;
		type = GoBang_JudgeType(MAP, temp, user, D,true);
		SumOfValue += GoBang_ValueOfType(type);
	}
	return SumOfValue;
}
// userΪ��ǰ�жϵ�ɫ�飬DirΪ����,IsEnemy�ж��ǲ��ǵз�
int GoBang_JudgeType(int MAP[][15], POS temp, int user,int Dir,bool IsEnemy)
{
	MAP[temp.x][temp.y] = user;
	POS D[2];
	switch (Dir)
	{
	case 1:		D[0] = { 1,0 }; D[1] = { -1,0 };
		break;
	case 2:		D[0] = { 0,1 }; D[1] = { 0,-1 };
		break;
	case 3:		D[0] = { 1,-1 }; D[1] = { -1,1 };
		break;
	case 4:		D[0] = { 1,1 }; D[1] = { -1,-1 };
		break;
	}
	POS posL,posR;  // ����������Ҷ�
	int len = 0;// ���ӳ���
	posL = temp;
	while (posL.x >= 0 && posL.x < 15 && posL.y >= 0 && posL.y < 15 && MAP[posL.x][posL.y] == user)
	{
		posL.x += D[0].x;
		posL.y += D[0].y;
		len++;
	}
	posR = temp;
	while (posR.x >= 0 && posR.x < 15 && posR.y >= 0 && posR.y < 15 && MAP[posR.x][posR.y] == user)
	{
		posR.x += D[1].x;
		posR.y += D[1].y;
		len++;
	}
	len--;       // ���ظ�һ�Σ�����Ҫ����
	MAP[temp.x][temp.y] = 0;
	switch (len)
	{
	case 2:
		if (posL.x >= 0 && posL.x < 15 && posL.y >= 0 && posL.y < 15 && posR.x >= 0 && posR.x < 15 && posR.y >= 0 && posR.y < 15)
		{
			if (MAP[posL.x][posL.y] == 0 && MAP[posR.x][posR.y] == 0)
			{
				if (IsEnemy == false)
					return 4;
				else
					return 11;
			}
		}
	case 3:
		if (posL.x >= 0 && posL.x < 15 && posL.y >= 0 && posL.y < 15 && posR.x >= 0 && posR.x < 15 && posR.y >= 0 && posR.y < 15)
		{
			if (MAP[posL.x][posL.y] == 0 && MAP[posR.x][posR.y] == 0)
			{
				if (IsEnemy == false)
					return 3;
				else
					return 10;
			}
		}
		else
		{
			if (IsEnemy == false)
				return 5;
			else
				return 11;
		}	
		break;
	case 4:
		if (posL.x >= 0 && posL.x < 15 && posL.y >= 0 && posL.y < 15 && posR.x >= 0 && posR.x < 15 && posR.y >= 0 && posR.y < 15)
		{
			if (MAP[posL.x][posL.y] == 0 && MAP[posR.x][posR.y] == 0)
			{
				if (IsEnemy == false)
					return 2;
				else
					return 9;
			}
		}
		else
		{
			if (IsEnemy == false)
				return 3;
			else
				return 8;
		}
		break;
	case 5:
		if (IsEnemy == false)
			return 1;
		else
			return 7;
		break;
	default:
		if (IsEnemy == false)
			return 6;
		else
			return 12;
		break;
	}
//	return 0;
}
// ����������͵�Ȩֵ
int GoBang_ValueOfType(int type)
{
	switch (type)
	{
	case 1:		return 100000;   // ������������
 		break;                
	case 2:		return 10000;    // ��������
		break;
	case 3:		return 1000;     // ��������OR����
		break;
	case 4:		return 100;      // �������
		break;
	case 5:		return 90;       // ��������
		break;
	case 6:		return 10;       // ��������
		break;
	case 7:		return 50000;    // �з���������
		break;
	case 8:		return 2000;     // �з�����
		break;
	case 9:		return 3000;     // �з�����
		break;
	case 10:	return 500;      // �з�����
		break;
	case 11:	return 90;       // �з����OR����
		break;
	case 12:	return 20;       // �з�����
		break;
	default:	return 0;
		break;
	}
}


