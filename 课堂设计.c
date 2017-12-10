/* ���� Visual C++ 6.0 ���������� */
/*   Turbo C 2.0 �������޷�����   */
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "windows.h"
#define  Limit 10

/* �������� */
void gotoxy(int x,int y);
void    sign();
void  finish();
void   input();
void  output();
void process();
void    sort();
void  demand();
void     del();
void  search();
void   sheet();
void    menu();
int    query();
float average(int x);
/* �������� */

struct singer			//�ṹ��
{
	int   age;		//����
	char  ID[15];		//���
	char  name[15];		//����
	char  sex [15];		//�Ա�
	char  tel[15];		//�绰
	float score[5];		//����
}player[Limit];




int Num=0;
void main()//main����
{
	char option;
	sign();
	while(1)
	{
		menu();
		do
		{option=getch(),fflush(stdin);}
		while(option!='1'&&option!='2'&&option!='3'&&option!='0');
		if(option=='0')
		{break;}
		else switch(option)
		{
			case '1':
			{input();break;}
			case '2':
			{process();break;}
			case '3':
			{search();break;}
		}
	}
	finish();
}



void sign()//����
{
	system("mode con cols=40 lines=10");
	gotoxy(4,1);
	printf("������Ϊ �����ֱ����ɼ�����ϵͳ��");
	gotoxy(7,3);
	printf("�����ˣ����1703��-��˼��");
	gotoxy(9,5);
	printf("�������ڣ�2017��12��");
	gotoxy(11,8);
	printf("��������������");
	gotoxy(27,8);
	getch(),fflush(stdin);
}

void finish()//������
{
	system("cls");
	system("mode con cols=40 lines=20");
	gotoxy(13,1);
	printf("��л����ʹ�ã�\n\n");
	printf("         __..._.-. \n");
	printf("        /.-.   '-.) \n");
	printf("        \\',       \\ \n");
	printf("         |       o'--D\n");
	printf("         \\      /    |\n");
	printf("          ;._  _\\ '-/\n");
	printf("        .'    __ `\\`.-'-. .-'-.\n");
	printf("      .'    .'  '.|'     '     ',\n");
	printf("     /      \\     '._,          |\n");
	printf("    ;        '-._     \\         /\n");
	printf("   (|           /'-.__/       .'\n");
	printf("    \\  __     ,'     '-.   .-'\n");
	printf("     `/  `\\.-'|         '.'\n");
	printf("      |    |  '-.\n");
	printf("      |    '-.   )\n");
	printf("      \\       )-'\n");
	printf("       '-----' ");
	gotoxy(27,1);
	Sleep(3000);
}

void input()//��������
{
	int i,k;
	char j;
	system("cls");
	gotoxy(25,2);
	printf("����ѡ��¼������");
	gotoxy(19,7);
	printf("����1�����ȫ�����ݲ�����¼�� ");
	gotoxy(19,10);
	printf("����2�������һ���µĸ�����Ϣ ");
	gotoxy(19,17);
	printf("����0�����ɷ������˵�     ");
	gotoxy(0,0);
	while(1)
	{
		do
		{j=getch(),fflush(stdin);}
		while(j!='1'&&j!='2'&&j!='0');
		switch(j)
		{
			case '1':
			{
				system("cls");
				printf("\n              ��������Ҫ¼�������(����0,С�ڵ���%d)   ",Limit);
				scanf("%d",&Num),fflush(stdin);
				while(1)
				{
					if(Num>Limit||Num<=0)
					{
						printf("\n                �������ݲ��Ϸ�������������!   ");
						scanf("%d",&Num),fflush(stdin);
					}
					else
					{break;}
				}
				sheet();
				for(i=0;i<Num;i++)
				{
					gotoxy(2,i*2+3);
					scanf("%s",player[i].ID),fflush(stdin);
					gotoxy(13,i*2+3);
					scanf("%s",player[i].name),fflush(stdin);
					gotoxy(26,i*2+3);
					scanf("%s",player[i].sex),fflush(stdin);
					gotoxy(34,i*2+3);
					scanf("%d",&player[i].age),fflush(stdin);
					gotoxy(42,i*2+3);
					scanf("%s",player[i].tel),fflush(stdin);
					for(k=0;k<5;k++)
					{
						gotoxy(68+7*k,i*2+3);
						scanf("%f",&player[i].score[k]),fflush(stdin);
					}
					gotoxy(106,i*2+3);
					printf("%.1f",average(i));
				}
				gotoxy(34,26);
				printf("��ϲ��¼����ɣ��밴������������˵�   ");
				getch(),fflush(stdin);
				system("cls");
				break;
			}
			case '2':
			{
				system("cls");
				if(Num>=Limit)
				{
					gotoxy(17,6);
					printf("������Ϣ����%d�����޷�����¼��   ",Limit);
					gotoxy(19,10);
					printf("�밴������������˵�   ");
					getch(),fflush(stdin);
					break;
				}
				printf("\n��������ֱ��:          ");
				scanf("%s",player[Num].ID),fflush(stdin);
				printf("\n�������������:          ");
				scanf("%s",player[Num].name),fflush(stdin);
				printf("\n����������Ա�:          ");
				scanf("%s",player[Num].sex),fflush(stdin);
				printf("\n�������������:          ");
				scanf("%d",&player[Num].age),fflush(stdin);
				printf("\n��������ֵ绰����:      ");
				scanf("%s",player[Num].tel),fflush(stdin);
				printf("\n");
				for(i=0;i<5;i++)
				{
					printf("�����������ί %d ����:   ",i+1);
					scanf("%f",&player[Num].score[i]),fflush(stdin);
				}
				printf("\n\n��ϲ��¼����ɣ��밴������������˵� ");
				Num+=1;
				gotoxy(0,0);
				getch(),fflush(stdin);
				break;
			}
			case '0':
			{break;}
		}
		break;
	}
}

void output()//�������
{
	int i,j;
	sheet();
	for(i=0;i<Num;i++)
	{
		gotoxy(2,i*2+3);
		printf("%s",player[i].ID);
		gotoxy(13,i*2+3);
		printf("%s",player[i].name);
		gotoxy(26,i*2+3);
		printf("%s",player[i].sex);
		gotoxy(34,i*2+3);
		printf("%d",player[i].age);
		gotoxy(42,i*2+3);
		printf("%s",player[i].tel);
		for(j=0;j<5;j++)
		{
			gotoxy(68+7*j,i*2+3);
			printf("%.1f",player[i].score[j]);
		}
		gotoxy(106,i*2+3);
		printf("%.1f",average(i));
	}
}

void process()//���ݴ���
{
	char j;
	output();
	gotoxy(17,27);
	printf("<   1.��������           2.�����޸�          3.����ɾ��          0.�������   >");
	gotoxy(43,25);
	printf("����Ӧ���ּ�ִ�ж�Ӧ����");
	do
	{j=getch(),fflush(stdin);}
	while(j!='1'&&j!='2'&& j!='3'&&j!='0');
	switch(j)
	{
		case '1':
		{sort();break;}
		case '2':
		{demand();break;}
		case '3':
		{del();break;}
		case '0':
		{break;}
	}
}

void sort()//��������
{
	int i,j;
	struct singer vocalist;
	for(i=0;i<Num-1;i++)
	{
		for(j=0;j<Num-1-i;j++)
		{
			if(average(j)>average(j+1))
			{
				vocalist=player[j];
				player[j]=player[j+1];
				player[j+1]=vocalist;
			}
		}
	}
	process();
}

void demand()//�����޸�
{
	int i;
	system("cls");
	output();
	gotoxy(45,25);
	printf("��������޸ĵĸ�������   ");
	i=query();
	if(i==-1)
	{
		gotoxy(45,27);
		printf("���޴��ˣ���������˳�");
		getch(),fflush(stdin);
	}
	else
	{
		gotoxy(35,27);
		printf("��ϣ���޸�%s�ĵ绰���룬�������޸ĺ�ĵ绰���룺   ",player[i].name);
		scanf("%s",player[i].tel);
		gotoxy(45,31);
		printf("�޸ĳɹ��������������");
		getch(),fflush(stdin);
	}	
		process();
}

void del()//����ɾ��
{
	int i,k;
	char j;
	system("cls");
	output();
	gotoxy(45,25);
	printf("�������ɾ����Ϣ�ĸ�������   ");
	i=query();
	if(i==-1)
	{
		gotoxy(47,27);
		printf("���޴��ˣ���������˳�");
		getch(),fflush(stdin);
	}
	else
	{
		gotoxy(40,27);
		printf("��ϣ��ɾ��%s��������Ϣ���Ƿ�ȷ��?(Y/N)��   ",player[i].name);
		do
		{j=getch(),fflush(stdin);}
		while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
		if(j=='Y'||j=='y')
		{
			for(i;i<Num;i++)
			{
				for(k=0;k<=15;k++)
				{
				player[i].ID[k]=player[i+1].ID[k];
				player[i].name[k]=player[i+1].name[k];
				player[i].sex[k]=player[i+1].sex[k];
				player[i].tel[k]=player[i+1].tel[k];
				}
				player[i].age=player[i+1].age;
				for(k=0;k<5;k++)
				{
				player[i].score[k]=player[i+1].score[k];
				}
			}
			Num-=1;
			gotoxy(45,31);
			printf("ɾ���ɹ��������������");
			getch(),fflush(stdin);
		}
	}
	process();
}

void search()//���ݲ�ѯ
{
	int i;
	system("cls");
	gotoxy(20,8);
	printf("���������ѯ�ĸ�������   ");
	i=query();
	if(i==-1)
	{
		gotoxy(20,12);
		printf("���޴��ˣ���������˳�");
		getch(),fflush(stdin);
	}
	else
	{
		system("cls");
		printf("����Ϊ�ø��ֵ�ȫ����Ϣ\n\n");
		printf("���:        %s\n\n",player[i].ID);
		printf("����:        %s\n\n",player[i].name);
		printf("�Ա�:        %s\n\n",player[i].sex);
		printf("����:        %d\n\n",player[i].age);
		printf("�绰����:    %s\n\n",player[i].tel);
		printf("��ί����:\n");
		printf("��\n");
		printf("��:          %.1f\n",player[i].score[0]);
		printf("��:          %.1f\n",player[i].score[1]);
		printf("��:          %.1f\n",player[i].score[2]);
		printf("��:          %.1f\n",player[i].score[3]);
		printf("��:          %.1f\n",player[i].score[4]);
		printf("��\n");
		printf("ƽ���ɼ���   %.1f          �밴��Enter�����˳�   ",average(i));
		getchar(),fflush(stdin);
	}
}

void sheet()//��ӡ���
{
	int i;
	system("mode con cols=117 lines=33");
	system("cls");
	printf("��----------------------------------------------------------------------------------------------------------------��\n");
	printf("��  ���   |    ����    | �Ա� | ���� |     �绰����     |  ���֣�<  ��  |  ��  |  ��  |  ��  |  ��  > | ƽ���ɼ� ��\n");
	for(i=0;i<Num;i++)
	{
	printf("��----------------------------------------------------------------------------------------------------------------��\n");
	printf("��         |            |      |      |                  |        <      |      |      |      |      > |          ��\n");
	}
	printf("��----------------------------------------------------------------------------------------------------------------��\n");
}

void menu()//��ӡ�˵�
{
	system("mode con cols=70 lines=22");
	printf("          **************************************************\n");
	printf("          *                                  ___   ___     *\n");
	printf("          *                  �� �˵� ��     ( @ \\Y/ @ )    *\n");
	printf("          *                                  \\__+|+__/     *\n");
	printf("          *                                   {_/ \\_}      *\n");
	printf("          *                  1.¼������                    *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                  2.��ʾ����                    *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                  3.��������                    *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *       ____()()   0.�˳�����                    *\n");
	printf("          *      /      @@                                 *\n");
	printf("          *`~~~~~\\_;m__m._>o                               *\n");
	printf("          **************************************************\n");
	printf("\n             ע�������޸ġ�ɾ�����ܼ�������ʾ���ݹ�����   ");
	gotoxy(13,20);
}

void gotoxy(int x,int y)//����ƶ�
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

int query()//��������
{
	char name[15];
	int i;
	gets(name),fflush(stdin);
	for(i=0;i<Num;i++)
	{
		if(strcmp(name,player[i].name)==0)
		{return i;}
	}
	return -1;
}

float average(int x)//��ƽ���ɼ�
{
	int i=0;
	float add=0,max=player[x].score[0],min=player[x].score[0];
	for(i=0;i<5;i++)
	{
		add+=player[x].score[i];
		if(player[x].score[i]>max)
		{max=player[x].score[i];}
		if(player[x].score[i]<min)
		{min=player[x].score[i];}
	}
	return (add-max-min)/3;
}

