#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h >
#pragma warning(disable:4996)
#pragma comment(lib,"winmm.lib")

#define EXAMPLE_MACRO_NAME
#define wallswide 188
#define wallheight 28
#define Minlength 3
#define Maxlength 300

void Initintergeme();//��Ϸ��ʼ����
void Initinterface();//��Ϸ����0
void Initinterface1();//��Ϸ����1
void Initinterface2();//��Ϸ����2
void Setpos(int j, int i);//���ù��
void Setcolor(int color);//������ɫ
void Hidecursor();//���ع��
void Showtime();//��ʾʱ��
void Creatfoof();//ʳ�����
void Creatshake();//�߳���
void Moveshake();//���ƶ�
void ShowFraction();//��ʾ����
void Ru_game();//��Ϸ����
void Saveinformation();//������Ϣ
void Playmusc();//��������
void LinkNodeinsertion();//���ݲ�������
void Readformation();//��ȡ��Ϣ
void FirstReadformation();//�״ζ�ȡ��Ϣ
void link_order();//��������

struct Food
{
	int x;
	int y;
}food;
struct Shake
{
	int x[Maxlength];
	int y[Maxlength];
	int length;
}shake;

struct Shake_Scores
{
	char name[20];
	int Scores=0;
	int Speed = 300;
	char time[20];
}Shake_Scores;

typedef struct LinkNode
{
	struct Shake_Scores date;
	LinkNode* next;
}LinkNode;
LinkNode* g_pHead = NULL;

struct Shake_Scores  Shake_Scores2 = { 0 };
int Gemeflag = 0;//��Ϸ����
int cursor = 22, fok = 0, fok2 = 0;//��Ϸѡ��
int kongzhi = 0, kongzhi2 = 0;//�л�����
int dir = 97;//�ƶ�����
int fd = 0;
int Shakemoveflage = 0;//���ƶ���־λ
int Initinterface1_m = 1;
int flag = 0;//������Ϸ����


int main()
{
	int m = 0;
	int x = 0;
	FirstReadformation();//�״ζ�ȡ��Ϣ
A:	while (1 && fok2 == 0)
{
	Playmusc();//��������
	if (fok == 0)
	{
		Initintergeme();//��Ϸ��ʼ����
	}
	if (fok == 2)
	{
		fd = 0;
		fok2 = 1; system("CLS");
		if (flag == 1)
		{
			goto B;
		}
		Creatshake();//�߳���
		Initinterface1();//��Ϸ����
		
	}
	if(kongzhi2==2)
	{
		kongzhi = 0; kongzhi2 = 0;
	}
	if (fok == 1)
	{
		system("CLS");
		while (kongzhi == 0)
		{
			Initinterface2();
			if (kongzhi2 == 2)
			{
				system("CLS"); fok = 0;
				goto A;
			}
		}
		fd = 0;
		Creatshake();//�߳���
		Initinterface();//��Ϸ����
		Shake_Scores.Scores = 0; dir = 97;
		fok2 = 1;
		shake.length = Minlength;
	}
}
system("CLS");
B:	while (1 && fok2 == 1)
{
	Playmusc();//��������
	kongzhi = 0;
	Initinterface1();//��Ϸ����
	Creatfoof();//ʳ�����
	Sleep(Shake_Scores.Speed);
	m++; if (m > 15)
	{
		m = 1;
	}
	Setcolor(m);
	if (Shakemoveflage == 0)
	{
		Moveshake();//���ƶ�

	}
	Ru_game();
	ShowFraction();
	Showtime();//��ʾʱ��
	if (fok2 == 0)
	{
		fok = 0;
		system("CLS"); goto A;
	}
}
}
//==================================================================
//�� �� ����FirstReadformation()
//�����������״ζ�ȡ�ļ���Ϣ���浽����
//�����������
//�� �� ֵ��void
//==================================================================
void FirstReadformation()//�״ζ�ȡ��Ϣ
{
	int rd = 0, k;
	FILE* fp = fopen("she.txt", "r+");
	if (fp == NULL)
	{
		return;
	}
	if ((k = fgetc(fp)) == EOF)
	{
		return;
	}
	while ((k = fgetc(fp)) != EOF)
	{
		if (k == 10)
		{
			rd++;
		}
	}
	fseek(fp, 30, SEEK_SET);
	for (size_t i = 0; i < rd-1; i++)
	{
		fscanf(fp, "%s\t %d\t %[^\n]\n", Shake_Scores.name, &Shake_Scores.Scores, Shake_Scores.time);
		LinkNodeinsertion();
	}
	fclose(fp);
}
//==================================================================
//�� �� ����Readformation()
//������������ȡ�ļ���Ϣ
//�����������
//�� �� ֵ��void
//==================================================================
void Readformation()//��ȡ��Ϣ
{
	
	
	int t = 4,m=1; 
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode = g_pHead;
	Setpos(20, 3);
	printf( "�������   ��Ϸ����     ʱ��\n");
	while (newnode != NULL)
	{
		Setpos(20, t); t++; Setcolor(m); m++; if (m>15)
		{
			m = 1;
		}
		printf("%4s\t %4d\t %4s\n", newnode->date.name, newnode->date.Scores, newnode->date.time);
		newnode = newnode->next;
		if (t > 25)break;
	}
}
//==================================================================
//�� �� ����LinkNodeinsertion()
//�������������ݲ�������
//�����������
//�� �� ֵ��void
//==================================================================
void LinkNodeinsertion()//���ݲ�������
{
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	strcpy(newnode->date.name, Shake_Scores.name);
	strcpy(newnode->date.time, Shake_Scores.time);
	newnode->date.Scores = Shake_Scores.Scores;
	LinkNode* p = g_pHead;
	newnode->next = NULL;
	if (g_pHead == NULL)
	{
		g_pHead = newnode;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newnode;
	}

}
//==================================================================
//�� �� ����Playmusc()
//������������������
//�����������
//�� �� ֵ��void
//==================================================================
void Playmusc()//��������
{
	switch (fok2)
	{
	case 0:
		mciSendString("stop 1.mp3", NULL, 0, NULL);
		mciSendString("close 1.mp3", NULL, 0, NULL);
		mciSendString("open 3.mp3", NULL, 0, NULL);
		mciSendString("play 3.mp3", NULL, 0, NULL);
		break;
	case 1:
		mciSendString("stop 3.mp3", NULL, 0, NULL);
		mciSendString("close 3.mp3", NULL, 0, NULL);
		mciSendString("open 1.mp3", NULL, 0, NULL);
		mciSendString("play 1.mp3", NULL, 0, NULL);
		break;
	default:
		break;
	}
}
//==================================================================
//�� �� ����Saveinformation()
//����������������Ϣ
//�����������
//�� �� ֵ��void
//==================================================================
void Saveinformation()//������Ϣ
{
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode = g_pHead;
	FILE* fp = fopen("she.txt", "w+");
	fprintf(fp, "�������   ��Ϸ����     ʱ��\n");
	fseek(fp, 0, SEEK_END);
	while (newnode!=0)
	{
		fprintf(fp, "%s\t  %d\t %s\n", newnode->date.name, newnode->date.Scores, newnode->date.time);
		newnode = newnode->next;
		
	}
	fclose(fp);
}
//==================================================================
//�� �� ����Ru_Moveshake()
//�������������ƶ�����
//�����������
//�� �� ֵ��void
//==================================================================
void Ru_Moveshake()//���ƶ�����
{
	if ((shake.x[0] + 2) == shake.x[1])
	{
		dir = 97; Shakemoveflage = 1;
	}
	if ((shake.x[0] - 2) == shake.x[1])
	{
		dir = 100; Shakemoveflage = 1;
	}
	if ((shake.y[0] + 1) == shake.y[1])
	{
		dir = 119; Shakemoveflage = 1;
	}
	if ((shake.y[0] - 1) == shake.y[1])
	{
		dir = 115; Shakemoveflage = 1;
	}
	Sleep(20); Shakemoveflage = 0;
	if (_kbhit())
	{
		Shakemoveflage = 0;
	}
}
//==================================================================
//�� �� ���� Moveshake()
//�������������ƶ���swad��
//�����������
//�� �� ֵ��void
//==================================================================
void Moveshake()//���ƶ�
{
	int temp;
	Setpos(shake.x[shake.length - 1], shake.y[shake.length - 1]);
	printf("  ");
	for (size_t i = shake.length - 1; i > 0; i--)
	{
		shake.x[i] = shake.x[i - 1];
		shake.y[i] = shake.y[i - 1];
		Setpos(shake.x[i], shake.y[i]);

		printf("��");
	}
	temp = dir;
	if (_kbhit())
	{
	
		dir = getch();
			/*if (getch()==119|| getch() == 115||getch() == 100|| getch() == 97)
			{
				dir = getch();
			}*/
	}
	if (temp == 119 && dir == 115)//��ֹ���ܷ�
	{
		dir = 119;
	}
	if (temp == 115 && dir == 119)//��ֹ���ܷ�
	{
		dir = 115;
	}
	if (temp == 97 && dir == 100)//��ֹ���ܷ�
	{
		dir = 97;
	}
	if (temp == 100 && dir == 97)//��ֹ���ܷ�
	{
		dir = 100;
	}
    T:switch (dir)
	{
	case 119:shake.y[0]--; break;//w
	case 115:shake.y[0]++; break;//s
	case 97:
		shake.x[0] -= 2; break;//a
	case 100:
		shake.x[0] += 2; break;//d
		
   case 112:
	system("cls");
	  fok2 = 0; rewind(stdin); flag = 1; dir = temp; goto T; return;
	default:fd = 0; dir = temp; goto T;
		break;
	}
	//for (size_t i = 1; i < shake.length; i++)
	//{
	//	if 
	//	{
	//	if (_kbhit())
	//	dir = getch();
	//	switch (dir)
	//	{
	//	case 119:shake.y[0]--; break;//w
	//	case 115:shake.y[0]++; break;//s
	//	case 97: shake.x[0] -=2; break;//a
	//	case 100:shake.x[0] +=2; break;//d
	//	default:fd = 0;
	//	break;
	//}
	//	}
	//}
	Setpos(shake.x[0], shake.y[0]);
	printf("��");
	if (shake.x[0] == food.x && shake.y[0] == food.y)
	{
		shake.length++; fd = 0; Shake_Scores.Speed -= 10; Shake_Scores.Scores += 10; Initinterface1_m++;
	}
	Hidecursor();
}
//==================================================================
//�� �� ���� Creatshake()
//�����������ڵ�ͼ�����ɳ�ʼ��
//�����������
//�� �� ֵ��void
//==================================================================
void Creatshake()//�߳���
{
	Setcolor(9);
	shake.length = Minlength;
	shake.y[0] = wallheight / 2;
	shake.x[0] = wallswide / 2 - 20;
	Setpos(shake.x[0], shake.y[0]);
	printf("��");
	for (size_t i = 1; i < shake.length; i++)
	{
		shake.x[i] = shake.x[i - 1] + 2;
		shake.y[i] = shake.y[i - 1];
		Setpos(shake.x[i], shake.y[i]);
		printf("��");
	}
	Hidecursor();
}
//==================================================================
//�� �� ���� Creatfoof()
//�����������ڵ�ͼ������ʳ��
//�����������
//�� �� ֵ��void
//==================================================================
void Creatfoof()//ʳ�����
{
	while (fd == 0)
	{
		srand((int)time(NULL));
		food.x = rand() % (88);
		if (food.x <= 22)
		{
			food.x += 22;
		}
		food.y = rand() % (25);
		if (food.y <= 2)
			food.y += 2;
		Setcolor(14);
		if (food.x % 2 == 0)
		{
			for (size_t i = 0; i < shake.length; i++)
			{
				if (food.x != shake.x[i] && food.y != shake.y[i])
				{
					Setpos(food.x, food.y);
					printf("��");
					fd = 1;
				}
			}

		}
	}
	Hidecursor();
}
//==================================================================
//�� �� ���� Hidecursor()
//�������������ع��
//�����������
//�� �� ֵ��void
//==================================================================
void Hidecursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };  // �ڶ���ֵΪ0��ʾ���ع��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//�����ͽṹ�嶼��windows.h�ж��塣
}
/*
0 = ��ɫ    8 = ��ɫ    1 = ����      9 = ��ɫ
2 = ����    10= ��ɫ    3 = ����      11= ��ǳ��
12= ��ɫ    4 = ����    5 = ��ɫ      13 = ����
6 = ��ɫ    14 = ����    7 = ��ɫ      15 = ����
*/
void Setcolor(int color)//������ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //��ɫ����
}
//==================================================================
//�� �� ���� Showtime()
//������������ʾʱ��
//�����������
//�� �� ֵ��void
//==================================================================
void Showtime()//��ʾʱ��
{
	
	time_t rawtime;
	struct tm* ltime;
	time(&rawtime);
	ltime = localtime(&rawtime);
	strftime(Shake_Scores.time, 20, "%Y-%m-%d %H:%M:%S", ltime);
	Setcolor(3);
	Setpos(98, 27);
	printf("%s\n", Shake_Scores.time);
}
//==================================================================
//�� �� ���� Initintergeme()
//������������Ϸ��ʼ����
//�����������
//�� �� ֵ��void
//==================================================================
void Initintergeme()//��Ϸ��ʼ����
{
	int m = 0;
	for (size_t i = 22; i < 117; i += 2)//���±�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 20);
		printf("pl");
	}
	for (size_t k = 1; k < 21; k += 1)//�����
	{
		m += 2; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(20, k);
		printf("da");
	}
	for (size_t k = 1; k < 21; k += 1)//�����
	{
		for (size_t j = 1; j < k; j += 1)
		{
			m += 2; if (m > 15)
			{
				m = 1;
			}
			Setcolor(m);
			Setpos(80 + k, j);
			printf("da");
		}

	}
	for (size_t k = 1; k < 21; k += 1)//�����
	{
		for (size_t j = 1; j < k; j += 1)
		{
			m += 2; if (m > 15)
			{
				m = 1;
			}
			Setcolor(m);
			Setpos(50 + k, j);
			printf("da");
		}

	}
	for (size_t k = 1; k < 21; k += 1)//�����
	{
		for (size_t j = 1; j < k; j += 1)
		{
			m += 2; if (m > 15)
			{
				m = 1;
			}
			Setcolor(m);
			Setpos(20 + k, j);
			printf("da");
		}

	}for (size_t i = 0; i < 120; i += 2)//�����±�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 0);
		printf("ǽ");
		Setpos(i, 28);
		printf("ǽ");
	}
	for (size_t k = 0; k < 28; k += 1)//�����ұ�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setcolor(m);
		Setpos(0, k);
		printf("ǽ");
		Setpos(118, k);
		printf("ǽ");

	}
	for (size_t i = 0; i < 120; i += 2)//�����±�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 0);
		printf("ǽ");
		Setpos(i, 28);
		printf("ǽ");
	}
	for (size_t k = 0; k < 28; k += 1)//�����ұ�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setcolor(m);
		Setpos(0, k);
		printf("ǽ");
		Setpos(118, k);
		printf("ǽ");

	}
	for (size_t i = 0; i < 120; i += 2)//�����±�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 0);
		printf("ǽ");
		Setpos(i, 28);
		printf("ǽ");
	}
	for (size_t k = 1; k < 28; k += 1)//�����ұ�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setcolor(m);
		Setpos(0, k);
		printf("ǽ");
		Setpos(118, k);
		printf("ǽ");
	}
	Showtime();
	Setcolor(12);
	Setpos(10, 22);
	printf("������Ϸ\n");
	Setpos(10, 23);
	Setcolor(10);
	printf("����Ϸ\n");
	Setpos(10, 24);
	Setcolor(11);
	printf("��Ϸ��¼\n");
	Setpos(10, 25);
	Setcolor(12);
	printf("�����Ϸ��¼\n");
	Setpos(100, 25);
	Setcolor(12);
	printf("��p�˳���Ϸ\n");
	if (_kbhit())
	{
		switch (getch())
		{
		case 112:exit(0);
		case 119:
			Setpos(7, cursor);
			printf("  ");
			cursor--;
			if (cursor < 22)
				cursor = 25;
			rewind(stdin);
			break;
		case 115:

			Setpos(7, cursor);
			printf("  ");
			cursor++;
			if (cursor > 25)
				cursor = 22;
			rewind(stdin);
			break;
		case 106:
			if (cursor == 25)
			{
              system("cls");
			  FILE* fp = fopen("she.txt", "w");
			  fprintf(fp, "");
			  fclose(fp);
			  while (g_pHead!=NULL)
			  {
				  g_pHead = NULL;
			/*	  g_pHead = g_pHead->next;*/

			  }

			}
			if (cursor == 23)
				fok = 1;
			if (cursor == 22)
				fok = 2;
			if (cursor == 24)
			{
				system("cls");
				int temp = 0;
				while (temp==0)
				{
					Hidecursor();
					for (size_t i = 0; i < 120; i += 2)//�����±�
					{
						
						m = 10;
						Setcolor(m);
						Setpos(i, 0);
						printf("ǽ");
						Setpos(i, 28);
						printf("ǽ");
					}
					for (size_t k = 1; k < 28; k += 1)//�����ұ�
					{
						
						m = 10;
						Setcolor(m);
						Setcolor(m);
						Setpos(0, k);
						printf("ǽ");
						Setpos(118, k);
						printf("ǽ");
					}
					Readformation();
					Setpos(100, 25);
					Setcolor(12);
					printf("��p�����ϼ�");
					if (_kbhit())
					{
						if (getch() == 112)
						{
							temp = 1; system("cls");
						}
					}
		
				}
			}
				
			rewind(stdin);
			break;
		}
	}
	Setpos(7, cursor);
	printf("-��");
	Showtime();
}
//==================================================================
//�� �� ���� Setpos(int j, int i)
//�������������ù��
//���������int j, int i
//�� �� ֵ��void
//==================================================================
void Setpos(int j, int i)//���ù��
{
	COORD pos;
	pos.X = j;
	pos.Y = i;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}
//==================================================================
//�� �� ���� Initinterface()
//������������Ϸ����������
//�����������
//�� �� ֵ��void
//==================================================================
void Initinterface()//��Ϸ����
{
	int m = 0;
	//for (size_t i = 0; i < 120; i += 2)//�����±�
	//{
	//	m++; if (m > 15)
	//	{
	//		m = 1;
	//	}
	//	Setcolor(m);
	//	Setpos(i, 0);
	//	printf("ǽ");
	//	Setpos(i, 28);
	//	printf("ǽ");
	//}
	//for (size_t k = 0; k < 28; k += 1)//�����ұ�
	//{
	//	m++; if (m > 15)
	//	{
	//		m = 1;
	//	}
	//	Setcolor(m);
	//	Setcolor(m);
	//	Setpos(0, k);
	//	printf("ǽ");
	//	Setpos(118, k);
	//	printf("ǽ");

	//}
	for (size_t i = 0; i < 120; i += 2)//�����±�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 0);
		printf("ǽ");
		Setpos(i, 28);
		printf("ǽ");
	}
	for (size_t k = 0; k < 28; k += 1)//�����ұ�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setcolor(m);
		Setpos(0, k);
		printf("ǽ");
		Setpos(118, k);
		printf("ǽ");

	}
	//for (size_t i = 0; i < 120; i += 2)//�����±�
	//{
	//	m++; if (m > 15)
	//	{
	//		m = 1;
	//	}
	//	Setcolor(m);
	//	Setpos(i, 0);
	//	printf("ǽ");
	//	Setpos(i, 28);
	//	printf("ǽ");
	//}
	Showtime();
	Hidecursor();
};
//==================================================================
//�� �� ���� Initinterface2()
//������������Ϸ�ڶ�������
//�����������
//�� �� ֵ��void
//==================================================================
void Initinterface2()//��Ϸ����
{
	int m = 0;
	char s[20];
	static int cursor1 = 10;
	for (size_t k = 2; k < 26; k += 1)//�����ұ�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(20, k);
		printf("ǽ");
		Setpos(90, k);
		printf("ǽ");
	}
	for (size_t i = 20; i < 92; i += 2)//�����±�
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 1);
		printf("ǽ");
		Setpos(i, 26);
		printf("ǽ");
	}
	Showtime();
	Setcolor(12);
	Setpos(45, 11);
	printf("ѡ����Ϸ�Ѷ�\n");
	Setpos(45, 10);
	printf("��������Ϸ�������\n");
	Setpos(45, 12);
	printf("�鿴��Ϸ��¼\n");
	Setpos(75, 25);
	printf("��p�����ϼ�");
	if (_kbhit())
	{
		switch (getch())
		{
		case 112:
			system("cls");
			fok = 0; fok2 = 0; kongzhi2 = 2;kongzhi=1; rewind(stdin); break;
			return;
		case 119:
			Setpos(42, cursor1);
			printf("  ");
			cursor1--;
			if (cursor1 < 10)
				cursor1 = 12;
			rewind(stdin);
			break;
		case 115:
			Setpos(42, cursor1);
			printf("  ");
			cursor1++;
			if (cursor1 > 12)
				cursor1 = 10;
			rewind(stdin);
			break;
		case 106:
			if (cursor1 == 10)
			{
				int temp = 0;
				
				Setpos(42, 10);
				printf("                                   ");
				Setpos(45, 11);
				printf("                                    ");
				Setpos(45, 12);
				printf("                                     ");
				Setpos(45, 11);
				printf("������һ����ϲ��������\n");
				Setpos(42, 12);
				printf("-��");
				Setpos(42, 11);
				printf("   ");
				Setpos(45, 12);
				while (temp == 0)
				{
					scanf("%s", s);
					strcpy(Shake_Scores.name,s);
					if (Shake_Scores.name != NULL)
					{
						temp = 1;
						Setpos(45, 11);
						printf("                                    ");
						Setpos(42, 12);
						printf("  ");
					}
				}
			}
			if (cursor1 == 12)
			{
				system("cls");
				int temp = 0;
				while (temp == 0)
				{
					Hidecursor();
					for (size_t i = 0; i < 120; i += 2)//�����±�
					{

						m = 12;
						Setcolor(m);
						Setpos(i, 0);
						printf("ǽ");
						Setpos(i, 28);
						printf("ǽ");
					}
					for (size_t k = 1; k < 28; k += 1)//�����ұ�
					{

						m = 12;
						Setcolor(m);
						Setcolor(m);
						Setpos(0, k);
						printf("ǽ");
						Setpos(118, k);
						printf("ǽ");
					}
					Readformation();
					Setpos(100, 25);
					Setcolor(14);
					printf("��p�����ϼ�");
					if (_kbhit())
					{
						if (getch() == 112)
						{
							temp = 1; system("cls");
						}
					}

				}
			}
			if (cursor1 == 11)
			{
				int flag = 0;
				int cursor2 = 10;
				Setcolor(12);
				Setpos(42, 12);
				printf("  ");
				Setpos(43, 10);
				printf("                    ");
				Setpos(42, 11);
				printf("                    ");
				Setpos(45, 12);
				printf("                    ");
				Setpos(45, 10);
				printf("                    ");
				while (flag == 0)
				{
					Setcolor(12);
					Setpos(45, 10);
					printf("����");
					Setpos(45, 11);
					printf("������");
					Setpos(45, 12);
					printf("����������");
					if (_kbhit())
					{
						switch (getch())
						{
						case 119:
							Setpos(42, cursor2);
							printf("  ");
							cursor2--;
							if (cursor2 < 10)
								cursor2 = 12;
							rewind(stdin);
							break;
						case 115:
							Setpos(42, cursor2);
							printf("  ");
							cursor2++;
							if (cursor2 > 12)
								cursor2 = 10;
							rewind(stdin);
							break;
						case 106:
							switch (cursor2)
							{
							case 10:Shake_Scores.Speed = 300; kongzhi = 1; return;
							case 11:Shake_Scores.Speed = 250; kongzhi = 1; return;
							case 12:Shake_Scores.Speed = 200; kongzhi = 1; return;
							default:
								break;
							}
							rewind(stdin); break;
					    case 112: flag = 1; rewind(stdin); break;
						}
					}
					if (flag == 1)
					{
						
						Setpos(42, cursor2);
						printf("   ");
						Setpos(45, 20);
						printf("            ");
					}
					if (flag == 0)
					{
						
						Setpos(42, cursor2);
						printf("-��");
					}

				}
			}
			if (cursor1 == 22)
			{
				fok = 2;
			}
			if (cursor1 == 24)
				fok = 3;
			rewind(stdin);
			break;
		}
	}
	Setpos(42, cursor1);
	printf("-��");
	Showtime();
	Hidecursor();
}
void Initinterface1()//��Ϸ����
{

	for (size_t k = 2; k < 26; k += 1)//�����ұ�
	{
		if (Initinterface1_m > 15)
		{
			Initinterface1_m = 1;
		}
		Setcolor(Initinterface1_m);
		Setpos(20, k);
		printf("ǽ");
		Setpos(90, k);
		printf("ǽ");

	}
	for (size_t i = 20; i < 92; i += 2)//�����±�
	{
		if (Initinterface1_m > 15)
		{
			Initinterface1_m = 1;
		}
		Setcolor(Initinterface1_m);
		Setpos(i, 1);
		printf("ǽ");
		Setpos(i, 26);
		printf("ǽ");
	}
	Hidecursor();
}
//==================================================================
//�� �� ����ShowFraction()
//������������ʾ��Ϸ����
//�����������
//�� �� ֵ��void
//==================================================================
void ShowFraction()//��ʾ��Ϸ����
{
	char s[] = "�߼�";
	char s1[] = "�м�";
	char s2[] = "��ͨ";
	Setcolor(3);
	Setpos(93, 5);
	printf("��Ϸ״̬��");
	Setpos(93, 6);
	printf("�÷֣�%d", Shake_Scores.Scores);
	Setpos(93, 7);
	if (Shake_Scores.Speed < 260)
	{
		printf("�Ѷȣ�%s", s1);
	}
	else if (Shake_Scores.Speed < 230)
	{
		printf("�Ѷȣ�%s", s);
	}
	else
	{
		printf("�Ѷȣ�%s", s2);
	}

}
//==================================================================
//�� �� ����link_order()
//������������������
//�����������
//�� �� ֵ��void
//==================================================================
void link_order()//��������
{
	LinkNode* pb, * pf, temp;
	pf = g_pHead;
	if (g_pHead == NULL) {//����Ϊ��
		return;
	}
	if (g_pHead->next == NULL) {//������1���ڵ�
		return;
	}
	while (pf->next != NULL) {//��pfָ��Ľڵ�Ϊ��׼�ڵ�
		pb = pf->next;//pb�ӻ�׼�����һ���ڵ㿪ʼ
		while (pb != NULL) {
			if (pf->date.Scores < pb->date.Scores) {
				temp = *pf;
				*pf = *pb;
				*pb = temp;
				temp.next = pf->next;
				pf->next = pb->next;
				pb->next = temp.next;
			}
			pb = pb->next;
		}
		pf = pf->next;
	}
	return;
}
//==================================================================
//�� �� ����Ru_game()
//������������Ϸ����
//�����������
//�� �� ֵ��void
//==================================================================
void Ru_game()//��Ϸ����
{
	int temp = 0; 
	Setcolor(3);
	Setpos(100, 25);
	printf("��P�ص�������");
	for (size_t i = 1; i < shake.length; i++)
	{
		if ((shake.x[0] == shake.x[i] && shake.y[0] == shake.y[i]) || (shake.x[0] <= 20 ||
			shake.x[0] >= 90) || (shake.y[0] <= 1 || shake.y[0] >= 26))
		{
			temp = 1;
		}
	} 
	if (temp == 1)
	{
		while (_kbhit() == 0)
	{
		Setcolor(3);
		Setpos(50, 10);
		printf("��Ϸ����\n");
		Setpos(50, 11);
		printf("��K���ص���ʼ����");
	}
	rewind(stdin);
	LinkNodeinsertion();//���ݲ�������
	link_order();//��������
	Saveinformation();//������Ϣ
	strcpy(Shake_Scores.name, " ");
	fok2 = 0;
	}
}
