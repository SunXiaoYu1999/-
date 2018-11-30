#pragma once
#include <Windows.h>
// ������飬ÿ����ť�ı߽�
typedef struct
{
	int x_l;
	int x_h;
	int y_l;
	int y_h;
}ARRAY;
typedef struct
{
	ARRAY array[225];
	int len;
}MOUSE_ARRAY;
// ��ɫ�ṹ
typedef struct
{
	int R;
	int G;
	int B;
}COLOR;
// ����ṹ��
typedef struct 
{
	int x;
	int y;
}POS;


void GoBang_1();  // ģʽ1�����˶���
void GoBang_GameInterFace(); // ��Ϸ����
void GoBang_DrawPiece(int x, int y, COLOR C); //������ 
POS GoBang_MouseReturn(MOUSE_ARRAY &MOU); // ������
void GoBang_InitMouseArray(MOUSE_ARRAY &MOU); // ��ʼ����귶Χ
int GoBang_GameWin(int MAP[][15], POS pos, int user); // �жϵ�ǰλ����û��Ӯ
int GoBang_GameEnd(const wchar_t *str);  //   ��Ϸ��������
int GoBang_Maze();// ��Ϸ�˵�
void GoBang(); // �˵��߼�
void GoBang_2();
int GoBang_CalculateValue(int MAP[][15], POS temp, int user); // ����temp���Ȩ��
int GoBang_JudgeType(int MAP[][15],POS temp,int user,int Dir, bool IsEnemy);
int GoBang_ValueOfType(int type);
