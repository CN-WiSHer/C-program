/* ���� Visual C++ 6.0 ���������� */
/*   Turbo C 2.0 �������޷�����   */
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "windows.h"
#define  Limit 10

/* �������� */
float       average(int x);
void inputing(int x,int y);
void   gotoxy(int x,int y);
void          sheet(int x);
void    menu();
void    sign();
void  finish();
void   input();
void  output();
void process();
void    sort();
void  demand();
void     del();
void  search();
void    save();
void    load();

int    query();
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
		system("cls");
		menu(1);
		gotoxy(30,5);
		printf("�� �˵� ��");
		gotoxy(30,8);
		printf("1.¼������");
		gotoxy(30,10);
		printf("2.��ʾ����");
		gotoxy(30,12);
		printf("3.��������");
		gotoxy(30,14);
		printf("4.��������");
		gotoxy(30,16);
		printf("5.��ȡ����");
		gotoxy(30,18);
		printf("0.�˳�����");
		gotoxy(0,0);
		do
		{option=getch(),fflush(stdin);}
		while(option!='1'&&option!='2'&&option!='3'&&option!='4'&&option!='5'&&option!='0');
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
			case '4':
			{save();break;}
			case '5':
			{load();break;}
		}
	}
	finish();
}



void sign()//����
{
	system("mode con cols=40 lines=10");
	gotoxy(8,1);
	printf("�����ֱ����ɼ�����ϵͳ��");
	gotoxy(7,3);
	printf("����ߣ����1703��-��˼��");
	gotoxy(9,5);
	printf("������ڣ�2017��12��");
	gotoxy(11,8);
	printf("��������������˵�");
	gotoxy(0,0);
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
	char j;
	system("cls");
	menu();
	gotoxy(25,5);
	printf("������ѡ��¼������");
	gotoxy(25,9);
	printf("1.������ݲ�����¼��");
	gotoxy(25,13);
	printf("2.����µĸ�����Ϣ");
	gotoxy(25,17);
	printf("0.�������˵�");
	gotoxy(0,0);
	do
	{j=getch(),fflush(stdin);}
	while(j!='1'&&j!='2'&&j!='0');
	switch(j)
	{
		case '1':
		{
			do
			{
				system("cls");
				menu();
				gotoxy(20,5);
				printf("����ǰѡ��������ݲ�����¼��");
				gotoxy(15,11);
				printf("������Ҫ¼�������(���ڵ���0,С�ڵ���%d) ",Limit);
				gotoxy(15,14);
				scanf("%d",&Num),fflush(stdin);
			}
			while(Num<0||Num>Limit);
			inputing(Num,0);
			break;
		}
		case '2':
		{
			int i;
			if(Num>=Limit)
			{
				system("cls");
				menu(3);
				gotoxy(20,10);
				printf("������Ϣ����%d�����޷�����¼��   ",Limit);
				gotoxy(25,15);
				printf("�밴������������˵�   ");
				getch(),fflush(stdin);
				break;
			}
			else
			{
				do
				{
					system("cls");
					menu();
					gotoxy(20,5);
					printf("����ǰѡ������µĸ�����Ϣ");
					gotoxy(15,11);
					printf("������Ҫ¼�������(���ڵ���0,С�ڵ���%d) ",Limit-Num);
					gotoxy(15,14);
					scanf("%d",&i),fflush(stdin);
				}
				while(i<0||i>Limit-Num);
				inputing(i,Num);
				Num+=i;
				break;
			}
		}
		case '0':
		{break;}
	}
}

void inputing(int x,int y)//��������
{
	int i,k;
	float n;
	sheet(x);
	for(i=0;i<x;i++)
	{
		gotoxy(2,i*2+3);
		scanf("%s",player[y+i].ID),fflush(stdin);
		gotoxy(13,i*2+3);
		scanf("%s",player[y+i].name),fflush(stdin);
		gotoxy(26,i*2+3);
		scanf("%s",player[y+i].sex),fflush(stdin);
		gotoxy(33,i*2+3);
		scanf("%d",&player[y+i].age),fflush(stdin);
		gotoxy(42,i*2+3);
		scanf("%s",player[y+i].tel),fflush(stdin);
		for(k=0;k<5;k++)
		{
			do
			{
				gotoxy(68+7*k,i*2+3);
				printf("    ");
				gotoxy(68+7*k,i*2+3);
				scanf("%f",&n),fflush(stdin);
			}
			while(n<0||n>10);
			player[y+i].score[k]=n;
		}
		gotoxy(106,i*2+3);
		printf("%.1f",average(y+i));
	}
	gotoxy(40,26);
	printf("��ϲ��¼����ɣ��밴������������˵�   ");
	getch(),fflush(stdin);
	system("cls");
}

void output()//�������
{
	int i,j;
	sheet(Num);
	for(i=0;i<Num;i++)
	{
		gotoxy(2,i*2+3);
		printf("%s",player[i].ID);
		gotoxy(13,i*2+3);
		printf("%s",player[i].name);
		gotoxy(26,i*2+3);
		printf("%s",player[i].sex);
		gotoxy(33,i*2+3);
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
	int i,k;
	char j;
	float l;
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
		gotoxy(1,25);
		printf("��ѡ���޸�ѡ��<   1.���          2.����          3.�Ա�          4.�绰          5.����          0.ȡ��   >");
		do
		{j=getch(),fflush(stdin);}
		while(j!='1'&&j!='2'&&j!='3'&&j!='4'&&j!='5'&&j!='0');
		switch(j)
		{
			case '1':
			{
				gotoxy(42,28);
				printf("��ϣ���޸�%s�ı�ţ��Ƿ�ȷ��?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(47,30);
					printf("�������޸ĺ�ı�ţ�   ");
					scanf("%s",player[i].ID);
				}
				break;
			}
			case '2':
			{
				gotoxy(42,28);
				printf("��ϣ���޸�%s���������Ƿ�ȷ��?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(47,30);
					printf("�������޸ĺ��������   ");
					scanf("%s",player[i].name);
				}
				break;
			}
			case '3':
			{
				gotoxy(42,28);
				printf("��ϣ���޸�%s���Ա��Ƿ�ȷ��?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(47,30);
					printf("�������޸ĺ���Ա�   ");
					scanf("%s",player[i].sex);
				}
				break;
			}
			case '4':
			{
				gotoxy(42,28);
				printf("��ϣ���޸�%s�ĵ绰���Ƿ�ȷ��?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(47,30);
					printf("�������޸ĺ�ĵ绰��   ");
					scanf("%s",player[i].tel);
				}
				break;
			}
			case '5':
			{
				gotoxy(42,28);
				printf("��ϣ���޸�%s�����֣��Ƿ�ȷ��?(Y/N)     ",player[i].name);
				do
				{j=getch(),fflush(stdin);}
				while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
				if(j=='Y'||j=='y')
				{
					gotoxy(38,30);
					printf("�������޸ĺ�����֣���ʽ����ί�ţ����֣�   ");
					scanf("%d,%f",&k,&l),fflush(stdin);
					player[i].score[k-1]=l;
				}
				break;
			}
			case '0':{break;}
		}
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
		printf("��ϣ��ɾ��%s��������Ϣ���Ƿ�ȷ��?(Y/N)     ",player[i].name);
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
		}
	}
	process();
}

void search()//���ݲ�ѯ
{
	int i;
	system("cls");
	menu();	
	gotoxy(25,5);
	printf("������ѡ�񣺲�ѯ����");
	gotoxy(24,10);
	printf("���������ѯ�ĸ�������");
	gotoxy(24,13);
	i=query();
	if(i==-1)
	{
		gotoxy(24,16);
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

void sheet(int x)//��ӡ���
{
	int i;
	system("mode con cols=117 lines=33");
	system("cls");
	printf("��----------------------------------------------------------------------------------------------------------------��\n");
	printf("��  ���   |    ����    | �Ա� | ���� |     �绰����     |  ���֣�<  ��  |  ��  |  ��  |  ��  |  ��  > | ƽ���ɼ� ��\n");
	for(i=0;i<x;i++)
	{
	printf("��----------------------------------------------------------------------------------------------------------------��\n");
	printf("��         |            |      |      |                  |        <      |      |      |      |      > |          ��\n");
	}
	printf("��----------------------------------------------------------------------------------------------------------------��\n");
}

void menu()//��ӡ�˵�
{
	system("mode con cols=70 lines=23");
	printf("\n                      ��   ���ֱ����ɼ�����ϵͳ   ��      \n\n");
	printf("          **************************************************\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          **************************************************\n");
}

void save()//��������
{
	FILE *fp;
	int i;
	char j;
	system("cls");
	menu();
	gotoxy(20,10);
	printf("��ϣ���������ݣ��Ƿ�ȷ��?(Y/N)  ");
	do
	{j=getch(),fflush(stdin);}
	while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
	if(j=='N'||j=='n')
	return;
	if((fp=fopen("D:\\information.dat","wb"))==NULL)
	{
		gotoxy(18,14);
		printf("�����޷��������棡�밴���������");
		getch();
		return;
	}
	for(i=0;i<Limit;i++)
	{
		if(fwrite(&player[i],sizeof(struct singer),1,fp)!=1)
		{
			gotoxy(18,14);
			printf("�����޷��������棡�밴���������");
			getch();
		}
	}
	gotoxy(18,14);
	printf("��ϲ���������ݳɹ����밴���������");
	getch();
	fclose(fp);
}

void load()//��ȡ����
{
	int i;
	char j;
	FILE *fp;
	system("cls");
	menu();
	gotoxy(20,10);
	printf("��ϣ����ȡ���ݣ��Ƿ�ȷ��?(Y/N)  ");
	do
	{j=getch(),fflush(stdin);}
	while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
	if(j=='N'||j=='n')
	return;
	if((fp=fopen("D:\\information.dat","rb"))==NULL)
	{
		gotoxy(18,14);
		printf("�����޷�������ȡ���밴���������");
		getch();
		return;
	}
	for(i=0;i<Limit;i++)
	{
		fread(&player[i],sizeof(struct singer),1,fp);
		if(strcmp(player[i].name,"\0")==0)
		{break;}
	}
/*	for(i=0;i<Limit;i++)
	{
		if(strcmp(player[i].name,"\0")==0)
		{break;}
	}*/
	Num=i;
	gotoxy(18,14);
	printf("��ϲ����ȡ���ݳɹ����밴���������");
	getch();
	fclose(fp);
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
