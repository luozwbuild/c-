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
		ID = MessageBox(hwnd, "通过键盘上的方向键操控蛇的移动。空格键暂停游戏，E键退出游戏", "提示", MB_OK);
		if (ID == IDOK) num = 0; //在阅读帮助文档的时候游戏暂停
	}
	else if (key == KEY_EXIT)
	{
		num = 1;
		ID = MessageBox(hwnd, _T("是否退出游戏"), _T("警告"), MB_YESNO);
		if (ID == IDYES) exit(0);
		else num = 0;
	}
}
char* MAKE::inttowchar(int xnum)
{
	memset(str, '\0', sizeof(str));//清零
	sprintf(str, "%d", xnum);
	return str;
}
void MAKE::GameInit()
{
	srand((unsigned int)time(NULL));//初始化随机数种子
	hwnd = initgraph(1000, 740);  //游戏窗口，宽1000px，高740px
	num = 1; //初始游戏是暂停的
	isGame = 0; //初始是菜单界面，不是游戏界面，所以设置为0
	food.iseat = true; //初始生成食物
	setbkmode(TRANSPARENT); //设置文字背景为透明色，防止文字背景颜色干扰
	snake.key = KEY_RIGHT; //初始蛇是朝向右边的
	snake.node = 3;  //初始蛇的节数是3节
	snake.Spos[0].x = 260; snake.Spos[0].y = 240;  //蛇头
	snake.Spos[1].x = 240; snake.Spos[1].y = 240;
	snake.Spos[2].x = 220; snake.Spos[2].y = 240;
	//barrier[740][1000] = { 0 };
}
void MAKE::DrawColor()
{
	settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	settextstyle(60, 30, "宋体");
	outtextxy(440, 100, ("蛇头"));
	settextcolor(LIGHTGREEN);
	settextstyle(30, 20, "宋体");
	outtextxy(360, 200, "R:改变蛇头颜色");//改变蛇头颜色
	settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	settextstyle(60, 30, "宋体");
	outtextxy(440, 270, ("蛇身"));
	settextcolor(WHITE);
	settextstyle(30, 20, "宋体");
	outtextxy(360, 350, "K:改变蛇身颜色");//蛇身颜色
	settextstyle(60, 30, "宋体");
	outtextxy(440, 420, ("食物"));
	settextcolor(LIGHTRED);
	settextstyle(30, 20, "宋体");
	outtextxy(360, 490, "O:改变食物颜色");//食物颜色
	key = _getch();
	if (key == 'R')
	{
		ID = MessageBox(hwnd, ("需要数字表示"), ("温馨提示"), MB_OK);
		if (ID == IDOK)
		{
			char mid[6];
			InputBox(mid, 6, _T("请输入你想要的蛇头颜色(建议白1,绿2,蓝3)"));//创建一个用户输入的框架窗口
			sscanf(mid, "%d", &snakehead);
			flag_head = 1;
		}
		if (flag_head == 1)
		{
			cleardevice();
			ID = MessageBox(hwnd, ("请问你需要返回菜单界面吗?"), ("温馨提示"), MB_YESNO);
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
		ID = MessageBox(hwnd, ("需要数字表示"), ("温馨提示"), MB_OK);
		if (ID == IDOK)
		{
			char mid[6];
			InputBox(mid, 6, _T("请输入你想要的蛇身颜色(建议白1,绿2,蓝3)"));//创建一个用户输入的框架窗口
			sscanf(mid, "%d", &snakebody);
			flag_body = 1;
		}
		if (flag_body == 1)
		{
			cleardevice();
			ID = MessageBox(hwnd, ("请问你需要返回菜单界面吗?"), ("温馨提示"), MB_YESNO);
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
		ID = MessageBox(hwnd, ("需要数字表示"), ("温馨提示"), MB_OK);
		if (ID == IDOK)
		{
			char mid[6];
			InputBox(mid, 6, _T("请输入你想要的食物颜色(建议白1,绿2,蓝3)"));//创建一个用户输入的框架窗口
			sscanf(mid, "%d", &food1);
			flag_food = 1;
		}
		if (flag_food == 1)
		{
			cleardevice();
			ID = MessageBox(hwnd, ("请问你需要返回菜单界面吗?"), ("温馨提示"), MB_YESNO);
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
	//MessageBox(hwnd, "关卡一关比一关难", "温馨提示", MB_OK);
	settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	settextstyle(60, 30, "宋体");
	outtextxy(380, 30, "关卡选择");
	settextcolor(WHITE);
	settextstyle(20, 15, "宋体");
	outtextxy(400, 150, "P:无关卡");
	settextcolor(GREEN);
	settextstyle(20, 15, "宋体");
	outtextxy(400, 250, "K:关卡一");
	settextcolor(WHITE);
	settextstyle(20, 15, "宋体");
	outtextxy(400, 350, "U:关卡二");
	settextcolor(LIGHTBLUE);
	settextstyle(30, 30, "宋体");
	outtextxy(360, 500, "T:返回菜单");
	MessageBox(hwnd, "关卡一关比一关难", "温馨提示", MB_OK);
	key = _getch();
	if (key == 'T')
	{
		MessageBox(hwnd, ("即将返会菜单界面"), ("温馨提示"), MB_OK);
		cleardevice();
		DrawMenu();
	}
	else if (key == 'P')
	{
		flag_barriers = 0;
		ID==MessageBox(hwnd, ("游戏界面已设置好，请返回菜单界面"), ("温馨提示"), MB_OK);
		cleardevice();
		DrawMenu();
	}
	else if (key == 'K')
	{
		flag_barriers = 1;
		ID == MessageBox(hwnd, ("游戏界面已设置好，请返回菜单界面"), ("温馨提示"), MB_OK);
		cleardevice();
		DrawMenu();
	}
	else if (key == 'U')
	{
		flag_barriers = 2;
		ID == MessageBox(hwnd, ("游戏界面已设置好，请返回菜单界面"), ("温馨提示"), MB_OK);
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
	settextstyle(20, 15, "宋体");
	outtextxy(450, 20, "记录");
	//显示分数排名
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
	}//从大到小排名
	for (int i = 0; i < sequence; i++)
	{
		if (score[i] != 0)
		{
			flag = 1;
			settextstyle(20, 15, "宋体");
			outtextxy(300, 40 + new_i * 20, inttowchar(score[i]));
			new_i++;
		}
	}
	if (flag == 0)
	{
		settextstyle(10, 10, "宋体");
		outtextxy(300, 40 + new_i * 10, inttowchar(0));
	}
	settextcolor(RED);
	settextstyle(20, 15, "宋体");
	outtextxy(400, 720, "T:回到菜单");
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
	settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));  //设置字体为随机色
	settextstyle(100, 40, _T("宋体"));
	outtextxy(160, 100, _T("Gluttonous snake"));
	//settextcolor(YELLOW);  //设置字体为亮红色
	settextstyle(20, 20, _T("宋体"));
	settextcolor(RED);
	outtextxy(350, 320, _T("X:开始游戏"));
	settextcolor(WHITE);
	outtextxy(350, 370, _T("Y:改变蛇速"));
	settextcolor(LIGHTBLUE);
	outtextxy(350, 420, ("Z:改变颜色"));
	settextcolor(YELLOW);
	outtextxy(350, 470, ("L:查看记录"));
	settextcolor(GREEN);
	outtextxy(350, 520, ("M:选择关卡"));
	settextcolor(WHITE);
	outtextxy(350, 570, ("N:退出游戏"));
	key = _getch();
	if (key == 'X')
	{
		ID = MessageBox(hwnd, _T("游戏初始界面是暂停的，按空格键开启游戏"), _T("温馨提示"), MB_OK);
		if (ID == IDOK)
		{
			isGame = 1;  //现在是游戏中的状态了
			num = 1; //游戏刚刚开始暂停界面，按space键开始游戏
			cleardevice();
			MessageBox(hwnd, "按键为小写wsad", "温馨提示", MB_OK);
			DrawMap();
		}
	}
	else if (key == 'Y')
	{
		char mid[6];
		InputBox(mid, 4, _T("请输入你想指定的蛇的速度(建议100-250)"));//创建一个用户输入的框架窗口
		sscanf(mid, "%d", &SP);
		cleardevice();
		DrawMenu();
	}
	else if (key == 'Z')
	{
		ID = MessageBox(hwnd, ("即将切换界面为设置界面"), ("温馨提示"), MB_YESNO);
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
		ID = MessageBox(hwnd, ("即将切换界面为记录界面"), ("温馨提示"), MB_YESNO);
		if (ID == IDNO)
		{
			cleardevice();
			DrawMenu();
		}
		else if (ID == IDYES)
		{
			MessageBox(hwnd, ("记录行数不超过界面大小"), ("温馨提示"), MB_OK);
			cleardevice();
			Check_the_record();
		}
	}
	else if (key == 'M')
	{
		ID = MessageBox(hwnd, ("即将切换界面为选择关卡界面"), ("温馨提示"), MB_OK);
		cleardevice();
		Draw_choose_barriers();

	}
	else if (key == 'N')
	{
		ID = MessageBox(hwnd, _T("是否退出游戏"), _T("警告"), MB_YESNO);
		if (ID == IDYES) exit(0);
		cleardevice();
		DrawMenu();
	}
	else { cleardevice(); DrawMenu(); }
}
void MAKE::DrawMap()
{
	setfillstyle(BS_HATCHED, HS_CROSS);//设置画填充格式的图案内部为网格状
	BeginBatchDraw();  //开始批量画图
	setfillcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	for (int i = 0; i < 37; ++i)  //画纵向的矩形边界
	{
		solidrectangle(0, i * 20, 30, (i + 1) * 20);
		solidrectangle(750, i * 20, 780, (i + 1) * 20);
	}
	for (int i = 0; i < 24; ++i) //画横向的矩形边界
	{
		solidrectangle(30 * (i + 1), 0, 30 * (i + 2), 30);
		solidrectangle(30 * (i + 1), 710, 30 * (i + 2), 740);
	}
	setfillstyle(NULL);
	EndBatchDraw();     //结束批量画图
	barrier[739][999] = { 0 };
	Drawbarriers();
	
	
}

void MAKE::DrawData()
{
	clearrectangle(780, 0, 1000, 740);//清空一个矩形面
	setfillcolor(WHITE);  //设置描绘背景为浅灰色;
	solidrectangle(780, 0, 1000, 740);
	settextcolor(BLACK);  //设置为亮红色的画笔
	settextstyle(30, 20, _T("宋体")); //设置文本字体高20px，宽15px，字体类型为“黑体”
	outtextxy(840, 40, _T("团队"));
	outtextxy(760, 300, _T(" 蛇头的坐标"));
	outtextxy(780, 350, _T("x="));
	outtextxy(880, 350, _T("y="));
	outtextxy(780, 500, _T("  游戏得分"));
	settextcolor(RED);
	outtextxy(780, 700, _T("帮助文档按Q键"));
	settextcolor(RED);
	settextstyle(30, 20, _T("宋体")); //设置文本字体高20px，宽15px，字体类型为“微软黑体”
	outtextxy(790, 90, _T("c + +小 组"));
	settextcolor(BLACK);
	settextstyle(20, 15, ("宋体"));
	outtextxy(830, 360, inttowchar(snake.Spos[0].x));
	outtextxy(930, 360, inttowchar(snake.Spos[0].y));
	settextcolor(RED);
	outtextxy(880, 550, inttowchar(score[sequence]));
	//outtextxy(880, 600, inttowchar(barrier[snake.Spos[0].x][snake.Spos[0].y]));
	//outtextxy(880, 600, inttowchar(barrier[270][260]));
}
void MAKE::DrawSnake()
{
	
	isGame = 1; //1代表进入了游戏界面
	BeginBatchDraw();  //开始批量画图
	Sleep(SP);//暂停时间
	for (int i = 0; i < snake.node; ++i)
	{
		if (i == 0)//蛇头
		{
			//setfillstyle(BS_HATCHED, HS_BDIAGONAL);//填充内部图形设置为斜线型（HS_BDIAGONAL）
			if (snakehead == 1)
			{
				setfillcolor(WHITE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//设置为圆形
				//setfillstyle(NULL);
			}
			else if (snakehead == 2)
			{
				setfillcolor(GREEN);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//设置为圆形
			}
			else if (snakehead == 3)
			{
				setfillcolor(BLUE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//设置为圆形
			}
			else
			{
				setfillcolor(WHITE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//设置为圆形
			}
		}
		else//蛇身
		{
			//setfillcolor(RGB(rand() % 256, rand() % 256, rand() % 256));//设置画填充图形的颜色为3种
			//随机颜色的合成色
			if (snakebody == 1)
			{
				setfillcolor(WHITE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//按照每节蛇的x，y坐标画一个无边界填充的圆
			}
			else if (snakebody == 2)
			{
				setfillcolor(GREEN);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//按照每节蛇的x，y坐标画一个无边界填充的圆
			}
			else if (snakebody == 3)
			{
				setfillcolor(BLUE);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//按照每节蛇的x，y坐标画一个无边界填充的圆
			}
			else
			{
				setfillcolor(YELLOW);
				solidcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//按照每节蛇的x，y坐标画一个无边界填充的圆
			}
		}

	}
	EndBatchDraw();     //结束批量画图
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
		int flag = 0;//判断食物产生的地方，不能出现在蛇身上
		food.Fpos.x = (unsigned int)(rand() % 630) + 65;
		food.Fpos.y = (unsigned int)(rand() % 600) + 65;
		for (int i = 0; i < snake.node; ++i)
		{
			if (fabs(food.Fpos.x - snake.Spos[i].x) <= 20 && fabs(food.Fpos.y - snake.Spos[i].y) <= 20)
			{
				flag = 1; //出现在蛇身上
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
	
	for (int i = snake.node-1 ; i > 0; --i)//迭代蛇的节点坐标，制作移动的效果   从蛇尾进行
	{
		if (i == snake.node-1 ) clearcircle(snake.Spos[i].x, snake.Spos[i].y, radius);//消除蛇尾
		snake.Spos[i].x = snake.Spos[i - 1].x;
		snake.Spos[i].y = snake.Spos[i - 1].y;//后往前移  
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
		score[sequence] += 1;  //分数加1
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
		++snake.node;  //蛇的节数+1
		food.iseat = true;  //此时食物已经被吃掉，需要重新生成
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
			sequence++;//下标加一，方便下一次记录。
			Sleep(300);
			GameOver();
			return;
		}
		if (snake.Spos[0].x >= 741 || snake.Spos[0].x <= 39 || snake.Spos[0].y <= 39 || snake.Spos[0].y >= 701)  //撞墙死亡
		{
			sequence++;//下标加一，方便下一次记录。
			GameOver();
			return;
		}
		else
		{
			for (int i = 1; i < snake.node; ++i)//蛇头撞
				if (snake.Spos[i].x == snake.Spos[0].x && snake.Spos[i].y == snake.Spos[0].y)//撞到自己
				{
					sequence++;//同上
					GameOver();
					return;
				}
		}
	}
	else
	{
		if (snake.Spos[0].x >= 741 || snake.Spos[0].x <= 39 || snake.Spos[0].y <= 39 || snake.Spos[0].y >= 701)  //撞墙死亡
		{
			sequence++;//下标加一，方便下一次记录。
			GameOver();
			return;
		}
		else
		{
			for (int i = 1; i < snake.node; ++i)//蛇头撞
				if (snake.Spos[i].x == snake.Spos[0].x && snake.Spos[i].y == snake.Spos[0].y)//撞到自己
				{
					sequence++;//同上
					GameOver();
					return;
				}
		}
	}
	}

void MAKE::GameOver()
{
	isGame = 2;   //此时是游戏结束阶段
	num = 1; //游戏结束暂停界面，不能再操作
	settextcolor(LIGHTRED);  //设置字体为亮红色
	settextstyle(120, 80, ("Consolas"));
	//TCHAR p[] = _T("Game Over!");
	outtextxy(30, 280, "Game over");
	settextcolor(YELLOW);  //设置字体为亮红色
	settextstyle(30, 30, _T("Consolas"));
	outtextxy(100, 520, _T("按任意键退出游戏!"));
	memset(barrier, 0, sizeof(barrier));
	if (_kbhit())
	{
		cleardevice();
		GameInit();
		DrawMenu();
	}
}
