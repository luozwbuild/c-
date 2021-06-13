#include<iostream>
#include"MAKE.h"
using namespace std;
void MAKE::KeyBoard()
{
	if (key == 'w')
	{
		if (snake.key != KEY_DOWN && num != 1 && isGame == 1)
			snake.key = key;
	}
	else if (key == 's')
	{
		if (snake.key != KEY_UP && num != 1 && isGame == 1)
			snake.key = key;
	}
	else if (key == 'a')
	{
		if (snake.key != KEY_RIGHT && num != 1 && isGame == 1)
			snake.key = key;
	}
	else if (key == 'd')
	{
		if (snake.key != KEY_LEFT && num != 1 && isGame == 1)
			snake.key = key;
	}
	else if (key == KEY_SPACE)
	{
		if (num == 0 && isGame == 1) num = 1;
		else if (num == 1 && isGame == 1) num = 0;
	}
	else if (key == KEY_PAUSE)
	{
		num = 1;
		ID = MessageBox(hwnd, "ͨ�������ϵķ�����ٿ��ߵ��ƶ����ո����ͣ��Ϸ��E���˳���Ϸ", "��ʾ", MB_OK);
		if (ID == IDOK) num = 0; //���Ķ������ĵ���ʱ����Ϸ��ͣ
	}
	else if (key == KEY_EXIT)
	{
		num = 1;
		ID = MessageBox(hwnd, _T("�Ƿ��˳���Ϸ"), _T("����"), MB_YESNO);
		if (ID == IDYES) exit(0);
		else num = 0;
	}
}
char* MAKE::inttowchar(int xnum)
{
	memset(str, '\0', sizeof(str));//����
	sprintf(str, "%d", xnum);
	return str;
}
void MAKE::GameInit()
{
	srand((unsigned int)time(NULL));//��ʼ�����������
	hwnd = initgraph(1000, 740);  //��Ϸ���ڣ���1000px����740px
	num = 1; //��ʼ��Ϸ����ͣ��
	isGame = 0; //��ʼ�ǲ˵����棬������Ϸ���棬��������Ϊ0
	food.iseat = true; //��ʼ����ʳ��
	setbkmode(TRANSPARENT); //�������ֱ���Ϊ͸��ɫ����ֹ���ֱ�����ɫ����
	snake.key = KEY_RIGHT; //��ʼ���ǳ����ұߵ�
	snake.node = 3;  //��ʼ�ߵĽ�����3��
	snake.Spos[0].x = 260; snake.Spos[0].y = 240;  //��ͷ
	snake.Spos[1].x = 240; snake.Spos[1].y = 240;
	snake.Spos[2].x = 220; snake.Spos[2].y = 240;
	//barrier[740][1000] = { 0 };
}
void MAKE::DrawColor()
{
	settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	settextstyle(60, 30, "����");
	outtextxy(440, 100, ("��ͷ"));
	settextcolor(LIGHTGREEN);
	settextstyle(30, 20, "����");
	outtextxy(360, 200, "R:�ı���ͷ��ɫ");//�ı���ͷ��ɫ
	settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	settextstyle(60, 30, "����");
	outtextxy(440, 270, ("����"));
	settextcolor(WHITE);
	settextstyle(30, 20, "����");
	outtextxy(360, 350, "K:�ı�������ɫ");//������ɫ
	settextstyle(60, 30, "����");
	outtextxy(440, 420, ("ʳ��"));
	settextcolor(LIGHTRED);
	settextstyle(30, 20, "����");
	outtextxy(360, 490, "O:�ı�ʳ����ɫ");//ʳ����ɫ
	key = _getch();
	if (key == 'R')
	{
		ID = MessageBox(hwnd, ("��Ҫ���ֱ�ʾ"), ("��ܰ��ʾ"), MB_OK);
		if (ID == IDOK)
		{
			char mid[6];
			InputBox(mid, 6, _T("����������Ҫ����ͷ��ɫ(�����1,��2,��3)"));//����һ���û�����Ŀ�ܴ���
			sscanf(mid, "%d", &snakehead);
			flag_head = 1;
		}
		if (flag_head == 1)
		{
			cleardevice();
			ID = MessageBox(hwnd, ("��������Ҫ���ز˵�������?"), ("��ܰ��ʾ"), MB_YESNO);
			if (ID == IDYES)
			{
				cleardevice();
				GameInit();
				flag_head = 0;
				DrawMenu();
			}
			else if (ID == IDNO)
			{
				flag_head = 0;
				cleardevice();
				GameInit();
				DrawColor();
			}
		}
	}
	else if (key == 'K')
	{
		ID = MessageBox(hwnd, ("��Ҫ���ֱ�ʾ"), ("��ܰ��ʾ"), MB_OK);
		if (ID == IDOK)
		{
			char mid[6];
			InputBox(mid, 6, _T("����������Ҫ��������ɫ(�����1,��2,��3)"));//����һ���û�����Ŀ�ܴ���
			sscanf(mid, "%d", &snakebody);
			flag_body = 1;
		}
		if (flag_body == 1)
		{
			cleardevice();
			ID = MessageBox(hwnd, ("��������Ҫ���ز˵�������?"), ("��ܰ��ʾ"), MB_YESNO);
			if (ID == IDYES)
			{
				cleardevice();
				GameInit();
				flag_body = 0;
				DrawMenu();
			}
			else if (ID == IDNO)
			{
				flag_body = 0;
				cleardevice();
				GameInit();
				DrawColor();
			}
		}
	}
	else if (key == 'O')
	{
		ID = MessageBox(hwnd, ("��Ҫ���ֱ�ʾ"), ("��ܰ��ʾ"), MB_OK);
		if (ID == IDOK)
		{
			char mid[6];
			InputBox(mid, 6, _T("����������Ҫ��ʳ����ɫ(�����1,��2,��3)"));//����һ���û�����Ŀ�ܴ���
			sscanf(mid, "%d", &food1);
			flag_food = 1;
		}
		if (flag_food == 1)
		{
			cleardevice();
			ID = MessageBox(hwnd, ("��������Ҫ���ز˵�������?"), ("��ܰ��ʾ"), MB_YESNO);
			if (ID == IDYES)
			{
				cleardevice();
				GameInit();
				flag_food = 0;
				DrawMenu();
			}
			else if (ID == IDNO)
			{
				flag_food = 0;
				cleardevice();
				GameInit();
				DrawColor();
			}
		}
	}
	else
	{
		cleardevice();
		DrawColor();
	}
}
void MAKE::Draw_choose_barriers()
{
	cleardevice();
	//MessageBox(hwnd, "�ؿ�һ�ر�һ����", "��ܰ��ʾ", MB_OK);
	settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	settextstyle(60, 30, "����");
	outtextxy(380, 30, "�ؿ�ѡ��");
	settextcolor(WHITE);
	settextstyle(20, 15, "����");
	outtextxy(400, 150, "P:�޹ؿ�");
	settextcolor(GREEN);
	settextstyle(20, 15, "����");
	outtextxy(400, 250, "K:�ؿ�һ");
	settextcolor(WHITE);
	settextstyle(20, 15, "����");
	outtextxy(400, 350, "U:�ؿ���");
	settextcolor(LIGHTBLUE);
	settextstyle(30, 30, "����");
	outtextxy(360, 500, "T:���ز˵�");
	MessageBox(hwnd, "�ؿ�һ�ر�һ����", "��ܰ��ʾ", MB_OK);
	key = _getch();
	if (key == 'T')
	{
		MessageBox(hwnd, ("��������˵�����"), ("��ܰ��ʾ"), MB_OK);
		cleardevice();
		DrawMenu();
	}
	else if (key == 'P')
	{
		flag_barriers = 0;
		ID==MessageBox(hwnd, ("��Ϸ���������úã��뷵�ز˵�����"), ("��ܰ��ʾ"), MB_OK);
		cleardevice();
		DrawMenu();
	}
	else if (key == 'K')
	{
		flag_barriers = 1;
		ID == MessageBox(hwnd, ("��Ϸ���������úã��뷵�ز˵�����"), ("��ܰ��ʾ"), MB_OK);
		cleardevice();
		DrawMenu();
	}
	else if (key == 'U')
	{
		flag_barriers = 2;
		ID == MessageBox(hwnd, ("��Ϸ���������úã��뷵�ز˵�����"), ("��ܰ��ʾ"), MB_OK);
		cleardevice();
		DrawMenu();
	}
	else
	{
		cleardevice();
		Draw_choose_barriers();
	}
}
void MAKE::Drawbarriers()
{
	;
	if (flag_barriers == 1)
	{
		barrier[739][999] = { 0 };
		setfillcolor(LIGHTGRAY);
		solidrectangle(200, 300, 340, 450);
		for (int x = 300; x < 450; x++)
		{
			for (int y = 200; y < 340; y++)
			{
				barrier[x][y] = 1;
			}
		}
		solidrectangle(600, 500, 610, 640);
		for (int x = 500; x < 640; x++)
		{
			for (int y = 600; y < 610; y++)
			{
				barrier[x][y] = 1;
			}
		}
		solidrectangle(600, 100, 610, 340);
		for (int x = 100; x < 340; x++)
		{
			for (int y = 600; y < 610; y++)
			{
				barrier[x][y] = 1;
			}
		}
	}
	if (flag_barriers == 2)
	{
		barrier[739][999] = { 0 };
		//barrier[739][999] = { 0 };
		setfillcolor(RED);
		solidrectangle(100, 90, 140, 120);
		for (int x = 90; x < 120; x++)
		{
			for (int y = 100; y < 140; y++)
			{
				barrier[x][y] = 1;
			}
		}
		solidrectangle(400, 390, 540, 420);
		for (int x = 390; x < 420; x++)
		{
			for (int y = 400; y < 540; y++)
			{
				barrier[x][y] = 1;
			}
		}
		solidrectangle(500, 430, 520, 500);
		for (int x = 430; x < 500; x++)
		{
			for (int y = 500; y < 520; y++)
			{
				barrier[x][y] = 1;
			}
		}
		solidrectangle(100, 520, 140, 550);
		for (int x = 520; x < 550; x++)
		{
			for (int y = 100; y < 140; y++)
			{
				barrier[x][y] = 1;
			}
		}
		solidrectangle(600, 90, 620, 260);
		for (int x = 90; x < 260; x++)
		{
			for (int y = 600; y < 620; y++)
			{
				barrier[x][y] = 1;
			}
		}
		solidrectangle(120, 200, 140, 230);
		for (int x = 200; x < 230; x++)
		{
			for (int y = 120; y < 140; y++)
			{
				barrier[x][y] = 1;
			}
		}
		solidrectangle(400, 600, 600, 620);
		for (int x = 600; x < 620; x++)
		{
			for (int y = 400; y < 600; y++)
			{
				barrier[x][y] = 1;
			}
		}
	}
}
void MAKE::Check_the_record()
{
	int flag = 0;
	int new_i = 0;
	cleardevice();
	settextcolor(WHITE);
	settextstyle(20, 15, "����");
	outtextxy(450, 20, "��¼");
	//��ʾ��������
	for (int former = 0; former < sequence - 1; former++)
	{
		for (int latter = former + 1; latter < sequence; latter++)
		{
			int fill_in = score[former];
			if (score[former] < score[latter])
			{
				score[former] = score[latter];
				score[latter] = fill_in;
			}
		}
	}//�Ӵ�С����
	for (int i = 0; i < sequence; i++)
	{
		if (score[i] != 0)
		{
			flag = 1;
			settextstyle(20, 15, "����");
			outtextxy(300, 40 + new_i * 20, inttowchar(score[i]));
			new_i++;
		}
	}
	if (flag == 0)
	{
		settextstyle(10, 10, "����");
		outtextxy(300, 40 + new_i * 10, inttowchar(0));
	}
	settextcolor(RED);
	settextstyle(20, 15, "����");
	outtextxy(400, 720, "T:�ص��˵�");
	key = _getch();
	if (key == 'T')
	{
		cleardevice();
		DrawMenu();
	}
	else
	{
		cleardevice();
		Check_the_record();
	}
}
void MAKE::DrawMenu()
{
	settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));  //��������Ϊ���ɫ
	settextstyle(100, 40, _T("����"));
	outtextxy(160, 100, _T("Gluttonous snake"));
	//settextcolor(YELLOW);  //��������Ϊ����ɫ
	settextstyle(20, 20, _T("����"));
	settextcolor(RED);
	outtextxy(350, 320, _T("X:��ʼ��Ϸ"));
	settextcolor(WHITE);
	outtextxy(350, 370, _T("Y:�ı�����"));
	settextcolor(LIGHTBLUE);
	outtextxy(350, 420, ("Z:�ı���ɫ"));
	settextcolor(YELLOW);
	outtextxy(350, 470, ("L:�鿴��¼"));
	settextcolor(GREEN);
	outtextxy(350, 520, ("M:ѡ��ؿ�"));
	settextcolor(WHITE);
	outtextxy(350, 570, ("N:�˳���Ϸ"));
	key = _getch();
	if (key == 'X')
	{
		ID = MessageBox(hwnd, _T("��Ϸ��ʼ��������ͣ�ģ����ո��������Ϸ"), _T("��ܰ��ʾ"), MB_OK);
		if (ID == IDOK)
		{
			isGame = 1;  //��������Ϸ�е�״̬��
			num = 1; //��Ϸ�ոտ�ʼ��ͣ���棬��space����ʼ��Ϸ
			cleardevice();
			MessageBox(hwnd, "����ΪСдwsad", "��ܰ��ʾ", MB_OK);
			DrawMap();
		}
	}
	else if (key == 'Y')
	{
		char mid[6];
		InputBox(mid, 4, _T("����������ָ�����ߵ��ٶ�(����100-250)"));//����һ���û�����Ŀ�ܴ���
		sscanf(mid, "%d", &SP);
		cleardevice();
		DrawMenu();
	}
	else if (key == 'Z')
	{
		ID = MessageBox(hwnd, ("�����л�����Ϊ���ý���"), ("��ܰ��ʾ"), MB_YESNO);
		if (ID == IDNO)
		{
			cleardevice();
			DrawMenu();
		}
		else if (ID == IDYES)
		{
			cleardevice();
			DrawColor();
		}
	}
	else if (key == 'L')
	{
		ID = MessageBox(hwnd, ("�����л�����Ϊ��¼����"), ("��ܰ��ʾ"), MB_YESNO);
		if (ID == IDNO)
		{
			cleardevice();
			DrawMenu();
		}
		else if (ID == IDYES)
		{
			MessageBox(hwnd, ("��¼���������������С"), ("��ܰ��ʾ"), MB_OK);
			cleardevice();
			Check_the_record();
		}
	}
	else if (key == 'M')
	{
		ID = MessageBox(hwnd, ("�����л�����Ϊѡ��ؿ�����"), ("��ܰ��ʾ"), MB_OK);
		cleardevice();
		Draw_choose_barriers();

	}
	else if (key == 'N')
	{
		ID = MessageBox(hwnd, _T("�Ƿ��˳���Ϸ"), _T("����"), MB_YESNO);
		if (ID == IDYES) exit(0);
		cleardevice();
		DrawMenu();
	}
	else { cleardevice(); DrawMenu(); }
}
void MAKE::DrawMap()
{
	setfillstyle(BS_HATCHED, HS_CROSS);//���û�����ʽ��ͼ���ڲ�Ϊ����״
	BeginBatchDraw();  //��ʼ������ͼ
	setfillcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	for (int i = 0; i < 37; ++i)  //������ľ��α߽�
	{
		solidrectangle(0, i * 20, 30, (i + 1) * 20);
		solidrectangle(750, i * 20, 780, (i + 1) * 20);
	}
	for (int i = 0; i < 24; ++i) //������ľ��α߽�
	{
		solidrectangle(30 * (i + 1), 0, 30 * (i + 2), 30);
		solidrectangle(30 * (i + 1), 710, 30 * (i + 2), 740);
	}
	setfillstyle(NULL);
	EndBatchDraw();     //����������ͼ
	barrier[739][999] = { 0 };
	Drawbarriers();
	
	
}

void MAKE::DrawData()
{
	clearrectangle(780, 0, 1000, 740);//���һ��������
	setfillcolor(WHITE);  //������汳��Ϊǳ��ɫ;
	solidrectangle(780, 0, 1000, 740);
	settextcolor(BLACK);  //����Ϊ����ɫ�Ļ���
	settextstyle(30, 20, _T("����")); //�����ı������20px����15px����������Ϊ�����塱
	outtextxy(840, 40, _T("�Ŷ�"));
	outtextxy(760, 300, _T(" ��ͷ������"));
	outtextxy(780, 350, _T("x="));
	outtextxy(880, 350, _T("y="));
	outtextxy(780, 500, _T("  ��Ϸ�÷�"));
	settextcolor(RED);
	outtextxy(780, 700, _T("�����ĵ���Q��"));
	settextcolor(RED);
	settextstyle(30, 20, _T("����")); //�����ı������20px����15px����������Ϊ��΢����塱
	outtextxy(790, 90, _T("c + +С ��"));
	settextcolor(BLACK);
	settextstyle(20, 15, ("����"));
	outtextxy(830, 360, inttowchar(snake.Spos[0].x));
	outtextxy(930, 360, inttowchar(snake.Spos[0].y));
	settextcolor(RED);
	outtextxy(880, 550, inttowchar(score[sequence]));
	//outtextxy(880, 600, inttowchar(barrier[snake.Spos[0].x][snake.Spos[0].y]));
	//outtextxy(880, 600, inttowchar(barrier[270][260]));
}
void MAKE::DrawSnake()
{
	
	isGame = 1; //1�����������Ϸ����
	BeginBatchDraw();  //��ʼ������ͼ
	Sleep(SP);//��ͣʱ��
	for (int i = 0; i < snake.node; ++i)
	{
		if (i == 0)//��ͷ
		{
			//setfillstyle(BS_HATCHED, HS_BDIAGONAL);//����ڲ�ͼ������Ϊб���ͣ�HS_BDIAGONAL��
			if (snakehead == 1)
			{
				setfillcolor(WHITE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//����ΪԲ��
				//setfillstyle(NULL);
			}
			else if (snakehead == 2)
			{
				setfillcolor(GREEN);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//����ΪԲ��
			}
			else if (snakehead == 3)
			{
				setfillcolor(BLUE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//����ΪԲ��
			}
			else
			{
				setfillcolor(WHITE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//����ΪԲ��
			}
		}
		else//����
		{
			//setfillcolor(RGB(rand() % 256, rand() % 256, rand() % 256));//���û����ͼ�ε���ɫΪ3��
			//�����ɫ�ĺϳ�ɫ
			if (snakebody == 1)
			{
				setfillcolor(WHITE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//����ÿ���ߵ�x��y���껭һ���ޱ߽�����Բ
			}
			else if (snakebody == 2)
			{
				setfillcolor(GREEN);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//����ÿ���ߵ�x��y���껭һ���ޱ߽�����Բ
			}
			else if (snakebody == 3)
			{
				setfillcolor(BLUE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//����ÿ���ߵ�x��y���껭һ���ޱ߽�����Բ
			}
			else
			{
				setfillcolor(YELLOW);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//����ÿ���ߵ�x��y���껭һ���ޱ߽�����Բ
			}
		}

	}
	EndBatchDraw();     //����������ͼ
}
void MAKE::DrawFood()
{
	if (food1 == 1)
	{
		setfillcolor(WHITE);
		solidcircle(food.Fpos.x, food.Fpos.y, 10);
	}
	else if (food1 == 3)
	{
		setfillcolor(BLUE);
		solidcircle(food.Fpos.x, food.Fpos.y, 10);
	}
	else if (food1 == 2)
	{
		setfillcolor(GREEN);
		solidcircle(food.Fpos.x, food.Fpos.y, 10);
	}
	else
	{
		setfillcolor(WHITE);
		solidcircle(food.Fpos.x, food.Fpos.y, 10);
	}
}
void MAKE::CreateFood()
{
	while (food.iseat == true)
	{
		int flag = 0;//�ж�ʳ������ĵط������ܳ�����������
		food.Fpos.x = (unsigned int)(rand() % 630) + 65;
		food.Fpos.y = (unsigned int)(rand() % 600) + 65;
		for (int i = 0; i < snake.node; ++i)
		{
			if (fabs(food.Fpos.x - snake.Spos[i].x) <= 20 && fabs(food.Fpos.y - snake.Spos[i].y) <= 20)
			{
				flag = 1; //������������
				break;
			}
			for (int y = food.Fpos.y - 10; y < food.Fpos.y + 10; y++)
			{
				for (int x = food.Fpos.x - 10; x < food.Fpos.x + 10; x++)
				{
					if (barrier[y][x] == 1)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					break;
				}
			}
			if (flag) continue;
			else
			{
				food.iseat = false;
				break;
			}
		}
	}
}
void MAKE::SnakeMove()
{
	
	for (int i = snake.node-1 ; i > 0; --i)//�����ߵĽڵ����꣬�����ƶ���Ч��   ����β����
	{
		if (i == snake.node-1 ) clearcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//������β
		snake.Spos[i].x = snake.Spos[i - 1].x;
		snake.Spos[i].y = snake.Spos[i - 1].y;//����ǰ��  
	}
	if (snake.key == 'w')
	{
		snake.Spos[0].y -= 20;
	}
	else if (snake.key == 's')
	{
		snake.Spos[0].y += 20;
	}
	else if (snake.key == 'a')
	{
		snake.Spos[0].x -= 20;
	}
	else if (snake.key == 'd')
	{
		snake.Spos[0].x += 20;
	}
}
void MAKE::SnakeEatFood()
{
	if (fabs(snake.Spos[0].x - food.Fpos.x) < 15 && fabs(snake.Spos[0].y - food.Fpos.y) < 15)
	{
		score[sequence] += 1;  //������1
		clearcircle(food.Fpos.x, food.Fpos.y, 10);
		if (snake.key == KEY_LEFT)
		{
			snake.Spos[snake.node].x = snake.Spos[snake.node - 1].x + 20;
			snake.Spos[snake.node].y = snake.Spos[snake.node - 1].y;
		}
		else if (snake.key == KEY_RIGHT)
		{
			snake.Spos[snake.node].x = snake.Spos[snake.node - 1].x - 20;
			snake.Spos[snake.node].y = snake.Spos[snake.node - 1].y;
		}
		else if (snake.key == KEY_UP)
		{
			snake.Spos[snake.node].y = snake.Spos[snake.node - 1].y + 20;
			snake.Spos[snake.node].x = snake.Spos[snake.node - 1].x;
		}
		else if (snake.key == KEY_DOWN)
		{
			snake.Spos[snake.node].y = snake.Spos[snake.node - 1].y - 20;
			snake.Spos[snake.node].x = snake.Spos[snake.node - 1].x;
		}
		++snake.node;  //�ߵĽ���+1
		food.iseat = true;  //��ʱʳ���Ѿ����Ե�����Ҫ��������
	}
}
void MAKE::SnakeDeath()
{
	
	int flag = 0;
	if (flag_barriers == 1||flag_barriers==2)
	{
		for (int i = snake.Spos[0].y - 9; i < snake.Spos[0].y + 10; i++)
		{
			for (int m = snake.Spos[0].x - 9; m < snake.Spos[0].x + 10; m++)
			{
				if (barrier[i][m] == 1)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
		if (flag == 1)
		{
			sequence++;//�±��һ��������һ�μ�¼��
			Sleep(300);
			GameOver();
			return;
		}
		if (snake.Spos[0].x >= 741 || snake.Spos[0].x <= 39 || snake.Spos[0].y <= 39 || snake.Spos[0].y >= 701)  //ײǽ����
		{
			sequence++;//�±��һ��������һ�μ�¼��
			GameOver();
			return;
		}
		else
		{
			for (int i = 1; i < snake.node; ++i)//��ͷײ
				if (snake.Spos[i].x == snake.Spos[0].x && snake.Spos[i].y == snake.Spos[0].y)//ײ���Լ�
				{
					sequence++;//ͬ��
					GameOver();
					return;
				}
		}
	}
	else
	{
		if (snake.Spos[0].x >= 741 || snake.Spos[0].x <= 39 || snake.Spos[0].y <= 39 || snake.Spos[0].y >= 701)  //ײǽ����
		{
			sequence++;//�±��һ��������һ�μ�¼��
			GameOver();
			return;
		}
		else
		{
			for (int i = 1; i < snake.node; ++i)//��ͷײ
				if (snake.Spos[i].x == snake.Spos[0].x && snake.Spos[i].y == snake.Spos[0].y)//ײ���Լ�
				{
					sequence++;//ͬ��
					GameOver();
					return;
				}
		}
	}
	}

void MAKE::GameOver()
{
	isGame = 2;   //��ʱ����Ϸ�����׶�
	num = 1; //��Ϸ������ͣ���棬�����ٲ���
	settextcolor(LIGHTRED);  //��������Ϊ����ɫ
	settextstyle(120, 80, ("Consolas"));
	//TCHAR p[] = _T("Game Over!");
	outtextxy(30, 280, "Game over");
	settextcolor(YELLOW);  //��������Ϊ����ɫ
	settextstyle(30, 30, _T("Consolas"));
	outtextxy(100, 520, _T("��������˳���Ϸ!"));
	memset(barrier, 0, sizeof(barrier));
	if (_kbhit())
	{
		cleardevice();
		GameInit();
		DrawMenu();
	}
}
