#include<easyx.h>
#include<time.h>

#define STR_SIZE 20
#define STR_NUM 128

#define STR_WIDTH 15

struct Rain
{
	int x, y;
	char str[STR_SIZE];
	int speed;
};

Rain rain[STR_NUM];

char createChar()
{
	char c;

	int t = rand() % 3;

	switch (t)
	{
		//数字
	case 0:
		c = rand() % 10 + '0';
		break;
		//小写字母
	case 1:
		c = rand() % 26 + 'a';
		break;
		//大写字母
	case 2:
		c = rand() % 26 + 'A';
		break;
	}
	return c;
}

void init()
{
	srand(time(NULL));
	for (int i = 0; i < STR_NUM; ++i)
	{
		rain[i].x = rand() % getwidth() - STR_WIDTH;
		rain[i].y = rand() % getheight();
		rain[i].speed = rand() % 5 + 5;

		for (int j = 0; j < STR_SIZE; ++j)
		{
			rain[i].str[j] = createChar();
		}
	}
}

void draw()
{
	BeginBatchDraw();
	//清屏
	cleardevice();
	//去除背景颜色
	setbkmode(0);


	for (int i = 0; i < STR_NUM; ++i)
	{
		for (int j = 0; j < STR_SIZE; ++j)
		{
			//显示字符雨（从上网下）
			outtextxy(rain[i].x, rain[i].y - j * STR_WIDTH, rain[i].str[j]);
			//设置字符颜色（从淡到深）
			settextcolor(RGB(0, 255 - 13 * j, 0));

		}
	}

	EndBatchDraw();
}

void changeChar()
{
	for (int i = 0; i < STR_NUM; ++i)
	{
		rain[rand() % STR_NUM].str[rand() % STR_SIZE] = createChar();

	}
}

void move()
{
	for (int i = 0; i < STR_NUM; ++i)
	{
		rain[i].y += rain[i].speed;
		//超出屏幕，重新设置位置
		if (rain[i].y - 300 > getheight())
		{
			rain[i].y = 0;
			//重新设置下落速度
			rain[i].speed = rand() % 10 + 5;
		}
	}
}

int main()
{
	//创建窗口
	initgraph(1280, 720);

	//数据初始化
	init();


	//游戏主循环
	while (true)
	{
		//绘制字符
		draw();

		//修改字符
		changeChar();

		//字符下落
		move();

		Sleep(23);

	}

	return 0;
}