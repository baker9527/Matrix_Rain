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
		//����
	case 0:
		c = rand() % 10 + '0';
		break;
		//Сд��ĸ
	case 1:
		c = rand() % 26 + 'a';
		break;
		//��д��ĸ
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
	//����
	cleardevice();
	//ȥ��������ɫ
	setbkmode(0);


	for (int i = 0; i < STR_NUM; ++i)
	{
		for (int j = 0; j < STR_SIZE; ++j)
		{
			//��ʾ�ַ��꣨�������£�
			outtextxy(rain[i].x, rain[i].y - j * STR_WIDTH, rain[i].str[j]);
			//�����ַ���ɫ���ӵ����
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
		//������Ļ����������λ��
		if (rain[i].y - 300 > getheight())
		{
			rain[i].y = 0;
			//�������������ٶ�
			rain[i].speed = rand() % 10 + 5;
		}
	}
}

int main()
{
	//��������
	initgraph(1280, 720);

	//���ݳ�ʼ��
	init();


	//��Ϸ��ѭ��
	while (true)
	{
		//�����ַ�
		draw();

		//�޸��ַ�
		changeChar();

		//�ַ�����
		move();

		Sleep(23);

	}

	return 0;
}