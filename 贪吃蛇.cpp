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

void Initintergeme();//游戏开始界面
void Initinterface();//游戏界面0
void Initinterface1();//游戏界面1
void Initinterface2();//游戏界面2
void Setpos(int j, int i);//设置光标
void Setcolor(int color);//设置颜色
void Hidecursor();//隐藏光标
void Showtime();//显示时间
void Creatfoof();//食物出现
void Creatshake();//蛇出现
void Moveshake();//蛇移动
void ShowFraction();//显示分数
void Ru_game();//游戏规则
void Saveinformation();//保存信息
void Playmusc();//播放音乐
void LinkNodeinsertion();//数据插入链表
void Readformation();//读取信息
void FirstReadformation();//首次读取信息
void link_order();//链表排序

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
int Gemeflag = 0;//游戏控制
int cursor = 22, fok = 0, fok2 = 0;//游戏选择
int kongzhi = 0, kongzhi2 = 0;//切换界面
int dir = 97;//移动方向
int fd = 0;
int Shakemoveflage = 0;//蛇移动标志位
int Initinterface1_m = 1;
int flag = 0;//继续游戏控制


int main()
{
	int m = 0;
	int x = 0;
	FirstReadformation();//首次读取信息
A:	while (1 && fok2 == 0)
{
	Playmusc();//播放音乐
	if (fok == 0)
	{
		Initintergeme();//游戏开始界面
	}
	if (fok == 2)
	{
		fd = 0;
		fok2 = 1; system("CLS");
		if (flag == 1)
		{
			goto B;
		}
		Creatshake();//蛇出现
		Initinterface1();//游戏界面
		
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
		Creatshake();//蛇出现
		Initinterface();//游戏界面
		Shake_Scores.Scores = 0; dir = 97;
		fok2 = 1;
		shake.length = Minlength;
	}
}
system("CLS");
B:	while (1 && fok2 == 1)
{
	Playmusc();//播放音乐
	kongzhi = 0;
	Initinterface1();//游戏界面
	Creatfoof();//食物出现
	Sleep(Shake_Scores.Speed);
	m++; if (m > 15)
	{
		m = 1;
	}
	Setcolor(m);
	if (Shakemoveflage == 0)
	{
		Moveshake();//蛇移动

	}
	Ru_game();
	ShowFraction();
	Showtime();//显示时间
	if (fok2 == 0)
	{
		fok = 0;
		system("CLS"); goto A;
	}
}
}
//==================================================================
//函 数 名：FirstReadformation()
//功能描述：首次读取文件信息保存到链表
//输入参数：无
//返 回 值：void
//==================================================================
void FirstReadformation()//首次读取信息
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
//函 数 名：Readformation()
//功能描述：读取文件信息
//输入参数：无
//返 回 值：void
//==================================================================
void Readformation()//读取信息
{
	
	
	int t = 4,m=1; 
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode = g_pHead;
	Setpos(20, 3);
	printf( "玩家名称   游戏分数     时间\n");
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
//函 数 名：LinkNodeinsertion()
//功能描述：数据插入链表
//输入参数：无
//返 回 值：void
//==================================================================
void LinkNodeinsertion()//数据插入链表
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
//函 数 名：Playmusc()
//功能描述：播放音乐
//输入参数：无
//返 回 值：void
//==================================================================
void Playmusc()//播放音乐
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
//函 数 名：Saveinformation()
//功能描述：保存信息
//输入参数：无
//返 回 值：void
//==================================================================
void Saveinformation()//保存信息
{
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode = g_pHead;
	FILE* fp = fopen("she.txt", "w+");
	fprintf(fp, "玩家名称   游戏分数     时间\n");
	fseek(fp, 0, SEEK_END);
	while (newnode!=0)
	{
		fprintf(fp, "%s\t  %d\t %s\n", newnode->date.name, newnode->date.Scores, newnode->date.time);
		newnode = newnode->next;
		
	}
	fclose(fp);
}
//==================================================================
//函 数 名：Ru_Moveshake()
//功能描述：蛇移动规则
//输入参数：无
//返 回 值：void
//==================================================================
void Ru_Moveshake()//蛇移动规则
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
//函 数 名： Moveshake()
//功能描述：蛇移动（swad）
//输入参数：无
//返 回 值：void
//==================================================================
void Moveshake()//蛇移动
{
	int temp;
	Setpos(shake.x[shake.length - 1], shake.y[shake.length - 1]);
	printf("  ");
	for (size_t i = shake.length - 1; i > 0; i--)
	{
		shake.x[i] = shake.x[i - 1];
		shake.y[i] = shake.y[i - 1];
		Setpos(shake.x[i], shake.y[i]);

		printf("身");
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
	if (temp == 119 && dir == 115)//防止蛇跑反
	{
		dir = 119;
	}
	if (temp == 115 && dir == 119)//防止蛇跑反
	{
		dir = 115;
	}
	if (temp == 97 && dir == 100)//防止蛇跑反
	{
		dir = 97;
	}
	if (temp == 100 && dir == 97)//防止蛇跑反
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
	printf("蛇");
	if (shake.x[0] == food.x && shake.y[0] == food.y)
	{
		shake.length++; fd = 0; Shake_Scores.Speed -= 10; Shake_Scores.Scores += 10; Initinterface1_m++;
	}
	Hidecursor();
}
//==================================================================
//函 数 名： Creatshake()
//功能描述：在地图上生成初始蛇
//输入参数：无
//返 回 值：void
//==================================================================
void Creatshake()//蛇出现
{
	Setcolor(9);
	shake.length = Minlength;
	shake.y[0] = wallheight / 2;
	shake.x[0] = wallswide / 2 - 20;
	Setpos(shake.x[0], shake.y[0]);
	printf("蛇");
	for (size_t i = 1; i < shake.length; i++)
	{
		shake.x[i] = shake.x[i - 1] + 2;
		shake.y[i] = shake.y[i - 1];
		Setpos(shake.x[i], shake.y[i]);
		printf("身");
	}
	Hidecursor();
}
//==================================================================
//函 数 名： Creatfoof()
//功能描述：在地图上生成食物
//输入参数：无
//返 回 值：void
//==================================================================
void Creatfoof()//食物出现
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
					printf("饼");
					fd = 1;
				}
			}

		}
	}
	Hidecursor();
}
//==================================================================
//函 数 名： Hidecursor()
//功能描述：隐藏光标
//输入参数：无
//返 回 值：void
//==================================================================
void Hidecursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };  // 第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//函数和结构体都在windows.h中定义。
}
/*
0 = 黑色    8 = 灰色    1 = 淡蓝      9 = 蓝色
2 = 淡绿    10= 绿色    3 = 湖蓝      11= 淡浅绿
12= 红色    4 = 淡红    5 = 紫色      13 = 淡紫
6 = 黄色    14 = 淡黄    7 = 白色      15 = 亮白
*/
void Setcolor(int color)//设置颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //颜色设置
}
//==================================================================
//函 数 名： Showtime()
//功能描述：显示时间
//输入参数：无
//返 回 值：void
//==================================================================
void Showtime()//显示时间
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
//函 数 名： Initintergeme()
//功能描述：游戏开始界面
//输入参数：无
//返 回 值：void
//==================================================================
void Initintergeme()//游戏开始界面
{
	int m = 0;
	for (size_t i = 22; i < 117; i += 2)//画下边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 20);
		printf("pl");
	}
	for (size_t k = 1; k < 21; k += 1)//画左边
	{
		m += 2; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(20, k);
		printf("da");
	}
	for (size_t k = 1; k < 21; k += 1)//画左边
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
	for (size_t k = 1; k < 21; k += 1)//画左边
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
	for (size_t k = 1; k < 21; k += 1)//画左边
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

	}for (size_t i = 0; i < 120; i += 2)//画上下边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 0);
		printf("墙");
		Setpos(i, 28);
		printf("墙");
	}
	for (size_t k = 0; k < 28; k += 1)//画左右边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setcolor(m);
		Setpos(0, k);
		printf("墙");
		Setpos(118, k);
		printf("墙");

	}
	for (size_t i = 0; i < 120; i += 2)//画上下边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 0);
		printf("墙");
		Setpos(i, 28);
		printf("墙");
	}
	for (size_t k = 0; k < 28; k += 1)//画左右边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setcolor(m);
		Setpos(0, k);
		printf("墙");
		Setpos(118, k);
		printf("墙");

	}
	for (size_t i = 0; i < 120; i += 2)//画上下边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 0);
		printf("墙");
		Setpos(i, 28);
		printf("墙");
	}
	for (size_t k = 1; k < 28; k += 1)//画左右边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setcolor(m);
		Setpos(0, k);
		printf("墙");
		Setpos(118, k);
		printf("墙");
	}
	Showtime();
	Setcolor(12);
	Setpos(10, 22);
	printf("继续游戏\n");
	Setpos(10, 23);
	Setcolor(10);
	printf("新游戏\n");
	Setpos(10, 24);
	Setcolor(11);
	printf("游戏记录\n");
	Setpos(10, 25);
	Setcolor(12);
	printf("清空游戏记录\n");
	Setpos(100, 25);
	Setcolor(12);
	printf("按p退出游戏\n");
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
					for (size_t i = 0; i < 120; i += 2)//画上下边
					{
						
						m = 10;
						Setcolor(m);
						Setpos(i, 0);
						printf("墙");
						Setpos(i, 28);
						printf("墙");
					}
					for (size_t k = 1; k < 28; k += 1)//画左右边
					{
						
						m = 10;
						Setcolor(m);
						Setcolor(m);
						Setpos(0, k);
						printf("墙");
						Setpos(118, k);
						printf("墙");
					}
					Readformation();
					Setpos(100, 25);
					Setcolor(12);
					printf("按p返回上级");
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
	printf("-》");
	Showtime();
}
//==================================================================
//函 数 名： Setpos(int j, int i)
//功能描述：设置光标
//输入参数：int j, int i
//返 回 值：void
//==================================================================
void Setpos(int j, int i)//设置光标
{
	COORD pos;
	pos.X = j;
	pos.Y = i;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}
//==================================================================
//函 数 名： Initinterface()
//功能描述：游戏第三个界面
//输入参数：无
//返 回 值：void
//==================================================================
void Initinterface()//游戏界面
{
	int m = 0;
	//for (size_t i = 0; i < 120; i += 2)//画上下边
	//{
	//	m++; if (m > 15)
	//	{
	//		m = 1;
	//	}
	//	Setcolor(m);
	//	Setpos(i, 0);
	//	printf("墙");
	//	Setpos(i, 28);
	//	printf("墙");
	//}
	//for (size_t k = 0; k < 28; k += 1)//画左右边
	//{
	//	m++; if (m > 15)
	//	{
	//		m = 1;
	//	}
	//	Setcolor(m);
	//	Setcolor(m);
	//	Setpos(0, k);
	//	printf("墙");
	//	Setpos(118, k);
	//	printf("墙");

	//}
	for (size_t i = 0; i < 120; i += 2)//画上下边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 0);
		printf("墙");
		Setpos(i, 28);
		printf("墙");
	}
	for (size_t k = 0; k < 28; k += 1)//画左右边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setcolor(m);
		Setpos(0, k);
		printf("墙");
		Setpos(118, k);
		printf("墙");

	}
	//for (size_t i = 0; i < 120; i += 2)//画上下边
	//{
	//	m++; if (m > 15)
	//	{
	//		m = 1;
	//	}
	//	Setcolor(m);
	//	Setpos(i, 0);
	//	printf("墙");
	//	Setpos(i, 28);
	//	printf("墙");
	//}
	Showtime();
	Hidecursor();
};
//==================================================================
//函 数 名： Initinterface2()
//功能描述：游戏第二个界面
//输入参数：无
//返 回 值：void
//==================================================================
void Initinterface2()//游戏界面
{
	int m = 0;
	char s[20];
	static int cursor1 = 10;
	for (size_t k = 2; k < 26; k += 1)//画左右边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(20, k);
		printf("墙");
		Setpos(90, k);
		printf("墙");
	}
	for (size_t i = 20; i < 92; i += 2)//画上下边
	{
		m++; if (m > 15)
		{
			m = 1;
		}
		Setcolor(m);
		Setpos(i, 1);
		printf("墙");
		Setpos(i, 26);
		printf("墙");
	}
	Showtime();
	Setcolor(12);
	Setpos(45, 11);
	printf("选择游戏难度\n");
	Setpos(45, 10);
	printf("请输入游戏玩家名称\n");
	Setpos(45, 12);
	printf("查看游戏记录\n");
	Setpos(75, 25);
	printf("按p返回上级");
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
				printf("请输入一个你喜欢的名称\n");
				Setpos(42, 12);
				printf("-》");
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
					for (size_t i = 0; i < 120; i += 2)//画上下边
					{

						m = 12;
						Setcolor(m);
						Setpos(i, 0);
						printf("墙");
						Setpos(i, 28);
						printf("墙");
					}
					for (size_t k = 1; k < 28; k += 1)//画左右边
					{

						m = 12;
						Setcolor(m);
						Setcolor(m);
						Setpos(0, k);
						printf("墙");
						Setpos(118, k);
						printf("墙");
					}
					Readformation();
					Setpos(100, 25);
					Setcolor(14);
					printf("按p返回上级");
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
					printf("困难");
					Setpos(45, 11);
					printf("很困难");
					Setpos(45, 12);
					printf("超级很困难");
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
						printf("-》");
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
	printf("-》");
	Showtime();
	Hidecursor();
}
void Initinterface1()//游戏界面
{

	for (size_t k = 2; k < 26; k += 1)//画左右边
	{
		if (Initinterface1_m > 15)
		{
			Initinterface1_m = 1;
		}
		Setcolor(Initinterface1_m);
		Setpos(20, k);
		printf("墙");
		Setpos(90, k);
		printf("墙");

	}
	for (size_t i = 20; i < 92; i += 2)//画上下边
	{
		if (Initinterface1_m > 15)
		{
			Initinterface1_m = 1;
		}
		Setcolor(Initinterface1_m);
		Setpos(i, 1);
		printf("墙");
		Setpos(i, 26);
		printf("墙");
	}
	Hidecursor();
}
//==================================================================
//函 数 名：ShowFraction()
//功能描述：显示游戏分数
//输入参数：无
//返 回 值：void
//==================================================================
void ShowFraction()//显示游戏分数
{
	char s[] = "高级";
	char s1[] = "中级";
	char s2[] = "普通";
	Setcolor(3);
	Setpos(93, 5);
	printf("游戏状态：");
	Setpos(93, 6);
	printf("得分：%d", Shake_Scores.Scores);
	Setpos(93, 7);
	if (Shake_Scores.Speed < 260)
	{
		printf("难度：%s", s1);
	}
	else if (Shake_Scores.Speed < 230)
	{
		printf("难度：%s", s);
	}
	else
	{
		printf("难度：%s", s2);
	}

}
//==================================================================
//函 数 名：link_order()
//功能描述：链表排序
//输入参数：无
//返 回 值：void
//==================================================================
void link_order()//链表排序
{
	LinkNode* pb, * pf, temp;
	pf = g_pHead;
	if (g_pHead == NULL) {//链表为空
		return;
	}
	if (g_pHead->next == NULL) {//链表有1个节点
		return;
	}
	while (pf->next != NULL) {//以pf指向的节点为基准节点
		pb = pf->next;//pb从基准点的下一个节点开始
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
//函 数 名：Ru_game()
//功能描述：游戏规则
//输入参数：无
//返 回 值：void
//==================================================================
void Ru_game()//游戏规则
{
	int temp = 0; 
	Setcolor(3);
	Setpos(100, 25);
	printf("按P回到主界面");
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
		printf("游戏结束\n");
		Setpos(50, 11);
		printf("按K键回到开始界面");
	}
	rewind(stdin);
	LinkNodeinsertion();//数据插入链表
	link_order();//链表排序
	Saveinformation();//保存信息
	strcpy(Shake_Scores.name, " ");
	fok2 = 0;
	}
}
