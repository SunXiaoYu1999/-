#pragma once
#define START 5
#define END 6
#define WALL 0
#define WAY -1
#define FIND_FLAG 7
#define MAX_SIZE 5000
typedef struct D
{
	int Dx;
	int Dy;
	int dir;
} Data;
typedef struct 
{
	Data pos[MAX_SIZE];
	int top;
} STA;
typedef struct 
{
	Data data[MAX_SIZE];
	int prior;//��ͷָ��
	int rear;//��βָ��
}QUE;
// ����Ϊ���ʱ�������ݽṹ
typedef struct {
	int x;
	int y;
	int DIR[4];
	int dir; 
} m_node;       // ÿ�����߷�������ݽṹ

typedef struct {
	int top;
	m_node *St;
}stock;         // ջ���ݽṹ

class Maze
{
private:
	int ** MAP; // ��ͼ
	int line;   // ����
	int col;    // ����
public:
	Maze();
	~Maze();
	void Init_Lize();
	void Get_XY();
	void Print_Way(int x, int y);
	void Print_Space(int x, int y);
	void Create_Map();
	void Get_Dir(int *Dir);
	void Flag_Way(m_node temp, int **MAP);
	void Find_Way_1();
	void Find_Way_1(Data start,Data end);
	void Find_Way_2();
	void Find_Way_2(Data start, Data end);
	void Out();
	void Print_Data_1(int top);
	void Print_Map();
};
void Push_In(STA &p, Data e);
bool Is_Equal(Data A, Data B);