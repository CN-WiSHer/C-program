/* ���� Visual C++ 6.0 ���������� */
/*   Turbo C 2.0 �������޷�����   */
#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
int foodx,foody,itemx,itemy,flag=0,speed,i,j,oheadx,oheady,nheadx,nheady,tailx,taily,max,score=0,quyu[30][60]={0};
char direct,direct1;
void start()//����С�߳�ʼλ��
{
	quyu[15][26]=1;
	quyu[15][27]=2;
	quyu[15][28]=3;	
	quyu[15][29]=4;
	quyu[15][30]=5;	
	oheadx=15;
	nheadx=15;
	oheady=26;
	nheady=25;
}

void gotoxy(int x,int y)  //����ƶ�
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void picture()//���С��
{
    for(i=0;i<=29;i++)
    {
    	for(j=0;j<=59;j++)
    	{
    		if(quyu[i][j]==1)//��ͷ
    		{gotoxy(j,i);
    		printf("@");}
    		if(quyu[i][j]>1)//����
    		{gotoxy(j,i);
    		printf("O");}
    	}
    }
}

void makefood()//����ʳ��
{
	while(1)
	{
		foodx=rand()%29;
		foody=rand()%59;
		if(quyu[foodx][foody]==0)//����ǽ�ڡ�������������ʳ��
		{
			quyu[foodx][foody]=-2;
			break;
		}
	}
}
void item()
{
	while(1)
	{
		itemx=rand()%29;
		itemy=rand()%59;
		if(quyu[itemx][itemy]==0)//����ǽ�ڡ������������ɵ���
		{
			quyu[itemx][itemy]=-3;
			gotoxy(itemy,itemx);
			printf("S");
			break;
		}	
	}
}

void move()//С���ƶ����
{
	for(i=0;i<=29;i++)
	{
		for(j=0;j<=59;j++)
		{
			if(quyu[i][j]>0)
			quyu[i][j]++;
		}
	}
	max=0;
	for(i=0;i<=29;i++)
	{
		for(j=0;j<=59;j++)
		{
			if(quyu[i][j]==2)
			{
				oheadx=i;
				oheady=j;
			}
			if(quyu[i][j]>max)
			{
				max=quyu[i][j];
				tailx=i;
				taily=j;
			}
		}
	}
	if	   (direct=='w'&&direct1!='s')
	{
		nheadx=oheadx-1;
		nheady=oheady;
		direct1=direct;
	}
	else if(direct=='a'&&direct1!='d')
	{
		nheadx=oheadx;
		nheady=oheady-1;
		direct1=direct;
	}
	else if(direct=='s'&&direct1!='w')	
	{
		nheadx=oheadx+1;
		nheady=oheady;
		direct1=direct;
	}
	else if(direct=='d'&&direct1!='a')
	{
		nheadx=oheadx;
		nheady=oheady+1;
		direct1=direct;
	}
	else//���벻�Ϲ�صķ�������
	{
		direct=direct1;
		if(direct=='w')
		{
			nheadx=oheadx-1;
			nheady=oheady;
		}
		else if(direct=='a')
		{
			nheadx=oheadx;
			nheady=oheady-1;
		}
		else if(direct=='s')	
		{
			nheadx=oheadx+1;
			nheady=oheady;
		}
		else if(direct=='d')
		{
			nheadx=oheadx;
			nheady=oheady+1;
		}		
	}
	if(quyu[nheadx][nheady]>0||quyu[nheadx][nheady]==-1)//�ж��Ƿ���ײ
	flag=1;
	else
	{
		if(quyu[nheadx][nheady]==-2)//�ж��Ƿ�Ե�ʳ��
		{
			makefood();
			score++;
			gotoxy(foody,foodx);
			printf("$");
		}
		else if(quyu[nheadx][nheady]==-3)//�ж��Ƿ�Ե�����
		{
			score+=2;
			if(rand()%3==0)
			{
				speed=speed+1;//����
			}
			else
			{
				speed=speed-1;//����
			}
		}
		else
		{
			quyu[tailx][taily]=0;
			gotoxy(taily,tailx);
			printf(" ");
		}
		quyu[nheadx][nheady]=1;
	}
}			

void menu()//UI
{
	gotoxy(49,8);
	printf("Gluttonous Snake");
	gotoxy(54,10);
	printf("̰����");
	gotoxy(48,15);
	printf("W��A��S��D���п���");
	gotoxy(42,20);
	printf("�����������Ѷȣ�����ԽСԽ�ѣ�");
	scanf("%d",&speed);
	system("cls");
	gotoxy(80,4);
	printf("Gluttonous Snake");
	gotoxy(85,7);
	printf("̰����");
	gotoxy(80,12);
	printf("W��A��S��D���п���");
	gotoxy(83,15);
	printf("��ǰ�Ѷȣ�%d",speed);
    for(j=0;j<=59;j++)
    {
    	quyu[0][j]=-1;
    	quyu[29][j]=-1;
    	gotoxy(j,0);
    	printf("*");
    	gotoxy(j,29);
    	printf("*");
    }
    for(i=0;i<=29;i++)
    {
    	quyu[i][0]=-1;
    	quyu[i][59]=-1;
    	gotoxy(0,i);
    	printf("*");
    	gotoxy(59,i);
    	printf("*");
    }
	start();
	direct='a';
	direct1='a';
}

void end()//��Ϸ����
{
	flag=0;
	gotoxy(84,19);
	printf("GAME OVER");
	gotoxy(83,22);
	printf("��ķ�����%d",score);
	gotoxy(72,26);
	printf("Press 'Enter' to continue the game ");
	fflush(stdin);
	getchar();
	system("cls");	
}

void main()//������
{
	system("mode con cols=120 lines=30");
	while(1)
	{
		fflush(stdin);
		score=-1;
		for(i=0;i<=29;i++)
		{
			for(j=0;j<=59;j++)
			{
				quyu[i][j]=0;
			}
		}
		menu();
		quyu[15][25]=-2;
		while(1)
		{
			if(kbhit())
			{
				direct=getch();
			}
			move();
			picture();
			if((rand()%149+1)%149==0)
			{item();}
			gotoxy(foody,foodx);
			Sleep(20*(speed+1));
			if(flag)
			break;
		}
		end();
	}
}