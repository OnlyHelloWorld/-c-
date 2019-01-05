#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define N1 100
#define N2 100
HANDLE hOut;
struct Course//�γ�
{ int num;//�γ̱��
  char name[50];//�γ�����
  char nature[50];//�γ�����
  int toperiod;//�γ���ѧʱ
  int giperiod;//�γ��ڿ�ѧʱ
  int experiod;//�γ��ϻ���ʵ��ѧʱ
  float credit;//�γ�ѧ��
  int term;//�γ�ѧ��
};
struct Student//ѧ��
{   int num;//ѧ��ѧ��
	char name[50];//ѧ������
	int course[10];//ѧ����ѧ�γ̵ı��
};
  
int main()
{
    int color(int c);
	void gotoxy(int x, int y);
    void title();
    void welcome();
    void coursemod();
    void studentmod();
	void classcheck();
	void stucheck();
	title();
	welcome();
}

int color(int c) //����������ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0; 
}

void gotoxy(int x, int y) //��������λ��
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void title() //�������
{ 
	color(10);
	gotoxy(24, 5);
	printf("ѧ��ѡ����Ϣ����ϵͳ\n");

}

void welcome() //�˵�ѡ��
{
	int i,j, n;
	color(13);
	for (i=6; i<=30; i++)
	{
		for (j=15; j<=60; j++)
		{
			gotoxy(j, i);
			if(i==6||i==30)
			{
				printf("=");
			}
			else if(j==15||j==60)
			{
				printf("||");
			}
		}

	}
	color(12);
	gotoxy(30, 10);
	printf("1.ѡ����Ϣ��ѯ");
	gotoxy(30, 13);
	printf("2.ѧ����Ϣ��ѯ");
	gotoxy(30, 16);
	printf("3.ѡ����Ϣ�޸�");
	gotoxy(30, 19);
	printf("4.ѧ����Ϣ�޸�");
	gotoxy(30, 22);
	printf("5.�˳�");
	gotoxy(21,25);
	color(3);
	printf("��ѡ��[1 2 3 4 5]:[ ]\b\b");
	color(14);
	scanf("%d", &n);
	switch(n)
	{ 
	case 1: system("cls");classcheck();break;
	case 2: system("cls");stucheck();break;
	case 3:system("cls");coursemod();break;
	case 4: system("cls");studentmod();break;
	case 5: exit(0);break;
	}
}

void coursemod() //ѡ����Ϣ�޸�
{   int n, i=0, n1, s; 
    FILE *fp, *fp1, *fp2, *fp3;
	struct Course temp, cour[N1];
	color(15);
	gotoxy(26, 5);
    printf("*****ѡ����Ϣ�޸�ģ��*****\n");
    gotoxy(26, 6);
    printf("  ��ѯǰ����ˢ��ϵͳ \n");
    gotoxy(26, 7);
    printf(" ********************* \n");
    gotoxy(26, 8);
    printf("  * 1.��ӿγ����� *\n");
    gotoxy(26, 9);
    printf(" ********************* \n"); 
    gotoxy(26, 10);
    printf("  * 2.�޸Ŀγ����� *\n");
    gotoxy(26, 11);
    printf(" ********************* \n");
    gotoxy(26, 12);
    printf("  * 3.ɾ���γ����� *\n");
    gotoxy(26, 13);
    printf(" ********************* \n");
    gotoxy(26,14);
    printf("  * 4.�ָ����� *\n");
    gotoxy(26,15);
    printf(" ********************* \n");
    gotoxy(26, 16);
    printf("  * 5.������һ��   *\n");
    gotoxy(26, 17);
    printf(" ********************* \n");
    gotoxy(26, 18);
    printf("  * 6.�˳�         * \n");
    gotoxy(26, 19);
    printf(" ********************* \n");
    gotoxy(26, 20);
    printf("��ѡ��[1 2 3 4 5 6]:[ ]\b\b");
    color(14);
	scanf("%d", &n);
	switch(n)
	{ 
	case 1: 
		color(10);
		printf("����������γ̱�š����ơ����ʡ���ѧʱ���ڿ�ѧʱ��ʵ����ϻ�ѧʱ��ѧ�֡�����ѧ��\n");
		color(14);
		scanf("%d%s%s%d%d%d%f%d", &temp.num, temp.name, temp.nature, &temp.toperiod, &temp.giperiod, &temp.experiod, &temp.credit, &temp.term);
	    if((fp=fopen("d:\\course.txt", "a+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
		fprintf(fp, "%d %s %s %d %d %d %.2f %d\n",temp.num, temp.name, temp.nature, temp.toperiod, temp.giperiod, temp.experiod, temp.credit, temp.term);
		fclose(fp);break;


	case 2: 
		color(10);
		printf("��������Ҫ�޸ĵĿγ̱��\n");
		color(14);
		scanf("%d", &temp.num);
        if((fp1=fopen("d:\\course.txt", "r+"))==NULL) {printf("�޷��򿪴��ļ�\n");exit(0);}
        while(!feof(fp1)){
		 fscanf(fp1, "%d%s%s%d%d%d%f%d\n", &cour[i].num, cour[i].name, cour[i].nature, &cour[i].toperiod, &cour[i].giperiod, &cour[i].experiod, &cour[i].credit, &cour[i].term);
        i++;}
	    for(s=0;s<i;s++)
	    if(cour[s].num==temp.num) {temp=cour[s];break;}
	    if(s==i) {printf("������Ŀγ̱�Ų�����\n");exit(0);}//Q1�жϿγ��Ƿ�������
        printf("��������Ҫ�޸���Ŀ����ţ�1.����2.����3.��ѧʱ4.�ڿ�ѧʱ5.ʵ����ϻ�ѧʱ6.ѧ��7.����ѧ��\n");
		scanf("%d", &n1);
		switch(n1){		
		case 1: printf("�������µ�����\n"); scanf("%s", temp.name);break;
		case 2: printf("�������µ�����\n");scanf("%s", temp.nature); break;
		case 3: printf("�������µ�����\n");scanf("%d", &temp.toperiod);break;
		case 4: printf("�������µ�����\n");scanf("%d", &temp.giperiod);break;
		case 5:  printf("�������µ�����\n");scanf("%d", &temp.experiod);break;
		case 6:  printf("�������µ�����\n");scanf("%f", &temp.credit);break;
		case 7:  printf("�������µ�����\n");scanf("%d", &temp.term);break;}	
		cour[s]=temp;
        color(10);
		fp2=fopen("d:\\course.txt", "w+");
		for(s=0;s<i;s++)
        fprintf(fp2, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
		fclose(fp1);
		fclose(fp2);
		break;
		
		
	case 3:
		color(10); 
		printf("��������Ҫɾ���Ŀγ̱��\n");
		color(14);
		scanf("%d", &temp.num); 
		if((fp=fopen("d:\\course.txt", "r+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
		while(!feof(fp)){
		            fscanf(fp, "%d%s%s%d%d%d%f%d\n", &cour[i].num, cour[i].name, cour[i].nature, &cour[i].toperiod, &cour[i].giperiod, &cour[i].experiod, &cour[i].credit, &cour[i].term);
		            i++;}//Q2\n�������
		fp1=fopen("d:\\course.txt", "w+");
		color(10);
		printf("��ѡ��ɾ������\n1.����ɾ��2.�߼�ɾ��\n");
		color(14);
		scanf("%d",&n1);

		switch(n1){
		case 1:	
			for(s=0;s<i;s++)		
				if(cour[s].num!=temp.num)
             	fprintf(fp1, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
				fclose(fp1);fclose(fp);break;
		case 2:
			if((fp3=fopen("d:\\courserecycle.txt", "a+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
			for(s=0;s<i;s++)		
				if(cour[s].num!=temp.num)
			     	fprintf(fp1, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
				else
					fprintf(fp3, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
				fclose(fp3);fclose(fp1);fclose(fp);break;}
		break;


	case 4: color(10);
		printf("��������Ҫ�ָ��Ŀγ̱��:\n");
		color(14);
		scanf("%d",&temp.num);

		if((fp=fopen("d:\\course.txt", "a+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
	    if((fp1=fopen("d:\\courserecycle.txt", "r+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
		while(!feof(fp1)){
			fscanf(fp1, "%d%s%s%d%d%d%f%d\n", &cour[i].num, cour[i].name, cour[i].nature, &cour[i].toperiod, &cour[i].giperiod, &cour[i].experiod, &cour[i].credit, &cour[i].term);
			i++;
		}
		for(s=0;s<i;s++){
			if(temp.num==cour[s].num)
			fprintf(fp, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
		}fclose(fp1);fclose(fp);break;


	case 5: system("cls");welcome();break;
	case 6: exit(0);break;
	}
	color(10);
	printf("��ѡ��1.������һ�� 2.����������3.�˳�\n");
	scanf("%d",&n1);
	switch(n1){
	case 1:system("cls");coursemod();break;
	case 2:system("cls");welcome();break;
	case 3:exit(0);break;}
}
void studentmod() //ѧ����Ϣ�޸�
{   int n, i=0, n1, s, k; 
    FILE *fp, *fp1, *fp2, *fp3;
	struct Student temp, stu[N2];
	color(15);
	gotoxy(26, 5);
    printf("*****ѧ����Ϣ�޸�ģ��*****\n");
    gotoxy(26, 6);
    printf("  ��ѯǰ����ˢ��ϵͳ \n");
    gotoxy(26, 7);
    printf(" ********************* \n");
    gotoxy(26, 8);
    printf("  * 1.���ѧ������ *\n");
    gotoxy(26, 9);
    printf(" ********************* \n"); 
    gotoxy(26, 10);
    printf("  * 2.�޸�ѧ������ *\n");
    gotoxy(26, 11);
    printf(" ********************* \n");
    gotoxy(26, 12);
    printf("  * 3.ɾ��ѧ������ *\n");
    gotoxy(26, 13);
    printf(" ********************* \n");
    gotoxy(26, 14);
    printf("  * 4.�ָ�����     *\n");
    gotoxy(26, 15);
    printf(" ********************* \n");
    gotoxy(26, 16);
    printf("  * 5.������һ��   *\n");
    gotoxy(26, 17);
    printf(" ********************* \n");
    gotoxy(26, 18);
    printf("  * 6.�˳�         * \n");
    gotoxy(26, 19);
    printf(" ********************* \n");
    gotoxy(26, 20);
    printf("��ѡ��[1 2 3 4 5 6]:[ ]\b\b");
    color(14);
	scanf("%d", &n);
	switch(n){ 
	case 1:
		color(10);
		printf("����������ѧ�š�������ѡ�εĿγ̱�ţ�10����\n");
		color(14);
		scanf("%d%s%d%d%d%d%d%d%d%d%d%d", &temp.num, temp.name, &temp.course[0], &temp.course[1], &temp.course[2], &temp.course[3],&temp.course[4], &temp.course[5], &temp.course[6], &temp.course[7],&temp.course[8], &temp.course[9]);
	    if((fp=fopen("d:\\student.txt", "a+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
		fprintf(fp, "%d %s %d %d %d %d %d %d %d %d %d %d\n", temp.num, temp.name, temp.course[0], temp.course[1], temp.course[2], temp.course[3], temp.course[4], temp.course[5], temp.course[6], temp.course[7], temp.course[8], temp.course[9]);
		fclose(fp);break;


	case 2: 
		color(10);
		printf("��������Ҫ�޸ĵ�ѧ��ѧ��\n");
		color(14);
		scanf("%d", &temp.num);
		if((fp1=fopen("d:\\student.txt", "r+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
        while(!feof(fp1)){
		fscanf(fp1, "%d%s%d%d%d%d%d%d%d%d%d%d\n", &stu[i].num, stu[i].name, &stu[i].course[0], &stu[i].course[1], &stu[i].course[2], &stu[i].course[3],&stu[i].course[4], &stu[i].course[5], &stu[i].course[6], &stu[i].course[7],&stu[i].course[8], &stu[i].course[9]);
        i++;}
	    for(s=0;s<i;s++)
	    if(stu[s].num==temp.num) {temp=stu[s];break;}
	    if(s==i) {printf("�������ѧ�Ų�����\n");exit(0);}
        printf("��������Ҫ�޸���Ŀ����ţ�1.����2.�γ̱�ţ�ʮ����\n");
		scanf("%d", &n1);
		switch(n1){		
		case 1: printf("�������µ�����\n"); scanf("%s", temp.name);break;
		case 2: printf("�������µ�����\n");
			for(k=0; k<10; k++)
			scanf("%d", &temp.course[k]);}
		stu[s]=temp;
        color(10);
		for(s=0;s<i;s++){
	    fp2=fopen("d:\\student.txt", "w+");
	    fprintf(fp2, "%d %s %d %d %d %d %d %d %d %d %d %d\n", temp.num, temp.name, temp.course[0], temp.course[1], temp.course[2], temp.course[3], temp.course[4], temp.course[5], temp.course[6], temp.course[7], temp.course[8], temp.course[9]);}
		fclose(fp1);fclose(fp2);break;
		break;
		

	case 3: 
		color(10);
		printf("��������Ҫɾ����ѧ��ѧ��\n");
		color(14);
		scanf("%d", &temp.num);
		color(10);
	    printf("��ѡ��ɾ������\n1.����ɾ��2.�߼�ɾ��\n");
		color(14);
		scanf("%d",&n1);
        if((fp=fopen("d:\\student.txt", "r+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
		while(!feof(fp)){
				fscanf(fp, "%d%s%d%d%d%d%d%d%d%d%d%d\n", &stu[i].num, stu[i].name, &stu[i].course[0], &stu[i].course[1], &stu[i].course[2], &stu[i].course[3],&stu[i].course[4], &stu[i].course[5], &stu[i].course[6], &stu[i].course[7],&stu[i].course[8], &stu[i].course[9]);
				i++;}
		fp1=fopen("d:\\student.txt", "w+");
		switch(n1){
		case 1:
			
			for(s=0;s<i;s++)	
				if(stu[s].num!=temp.num)
					fprintf(fp1, "%d %s %d %d %d %d %d %d %d %d %d %d\n",stu[s].num, stu[s].name, stu[s].course[0], stu[s].course[1], stu[s].course[2], stu[s].course[3],stu[s].course[4], stu[s].course[5], stu[s].course[6], stu[s].course[7], stu[s].course[8], stu[s].course[9]);
                    fclose(fp1);fclose(fp);break;
		case 2:
			if((fp3=fopen("d:\\studentrecycle.txt", "a+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
			for(s=0;s<i;s++)		
				if(stu[s].num!=temp.num)
					fprintf(fp1, "%d %s %d %d %d %d %d %d %d %d %d %d\n",stu[s].num, stu[s].name, stu[s].course[0], stu[s].course[1], stu[s].course[2], stu[s].course[3],stu[s].course[4], stu[s].course[5], stu[s].course[6], stu[s].course[7], stu[s].course[8], stu[s].course[9]);
				else
					fprintf(fp3, "%d %s %d %d %d %d %d %d %d %d %d %d\n",stu[s].num, stu[s].name, stu[s].course[0], stu[s].course[1], stu[s].course[2], stu[s].course[3],stu[s].course[4], stu[s].course[5], stu[s].course[6], stu[s].course[7], stu[s].course[8], stu[s].course[9]);	
			        fclose(fp3);fclose(fp1);fclose(fp);break;}
		break;


	case 4: 
		color(10);
		printf("��������Ҫ�ָ����ݵ�ѧ��ѧ��:\n");
		color(14);
		scanf("%d",&temp.num);
		if((fp=fopen("d:\\student.txt", "a+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
	    if((fp1=fopen("d:\\studentrecycle.txt", "r+"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
		while(!feof(fp1)){
			fscanf(fp1, "%d%s%d%d%d%d%d%d%d%d%d%d\n", &stu[i].num, stu[i].name, &stu[i].course[0], &stu[i].course[1], &stu[i].course[2], &stu[i].course[3],&stu[i].course[4], &stu[i].course[5], &stu[i].course[6], &stu[i].course[7],&stu[i].course[8], &stu[i].course[9]);
			i++;
		}
		for(s=0;s<i;s++){
			if(temp.num==stu[s].num)
			fprintf(fp, "%d %s %d %d %d %d %d %d %d %d %d %d\n",stu[s].num, stu[s].name, stu[s].course[0], stu[s].course[1], stu[s].course[2], stu[s].course[3],stu[s].course[4], stu[s].course[5], stu[s].course[6], stu[s].course[7], stu[s].course[8], stu[s].course[9]);
		}fclose(fp1);fclose(fp);break;


	case 5: system("cls");welcome();break;
	case 6: exit(0);break;
		}
	color(10);
	printf("��ѡ��1.������һ�� 2.����������3.�˳�\n");
	scanf("%d",&n1);
	switch(n1){
	case 1:system("cls");studentmod();break;
	case 2:system("cls");welcome();break;
	case 3:exit(0);break;}

}
void classcheck()//ѡ����Ϣ��ѯ
{	
	int num=0,i,j=0,n;
	char nam[50]="0";
	FILE *fp;
	struct Course cla[N1];
	color(15);
	gotoxy(26,4);
	printf("*************************\n");
	gotoxy(26,5);
    printf("*****�γ���Ϣ��ѯģ��*****\n");
    gotoxy(26, 6);
    printf("  ��ѯǰ����ˢ��ϵͳ \n");
    gotoxy(26, 7);
    printf(" ********************* \n");
    gotoxy(26, 8);
    printf("  * 1.���γ̱�Ų�ѯ *\n");
    gotoxy(26, 9);
    printf(" ********************* \n"); 
    gotoxy(26, 10);
    printf("  * 2.���γ����Ʋ�ѯ *\n");
    gotoxy(26, 11);
    printf(" ********************* \n");
    gotoxy(26, 12);
    printf("  * 3.������һ�� *\n");
    gotoxy(26, 13);
    printf(" ********************* \n");
    gotoxy(26, 14);
    printf("��ѡ��[1 2 3]:[ ]\b\b");
	scanf("%d",&n);
	switch(n){
	case 1:
		color(10);
		printf("����γ̱��:\n");
		color(14);
		scanf("%d",&num);
		break;


	case 2:
		color(10);
		printf("����γ�����\n");
		color(14);
		scanf("%s",nam);
		break;


	case 3:system("cls");welcome();break;
	}
	if((fp=fopen("d:\\course.txt", "r"))==NULL)	{printf("�޷��򿪴��ļ�\n");exit(0);}
	for(i=0;!(feof(fp));i++){
		fscanf(fp,"%d%s%s%d%d%d%f%d",&cla[i].num,cla[i].name,cla[i].nature,&cla[i].toperiod,&cla[i].giperiod,&cla[i].experiod,&cla[i].credit,&cla[i].term);
		if(num==cla[i].num||strcmp(nam,cla[i].name)==0)
			printf("�γ̱��:%07d ����:%s ����:%s ��ѧʱ:%d �ڿ�ѧʱ:%d ʵ����ϻ�ѧʱ:%d ѧ��:%.2f �Ͽ�ѧ��:%d\n",cla[i].num,cla[i].name,cla[i].nature,cla[i].toperiod,cla[i].giperiod,cla[i].experiod,cla[i].credit,cla[i].term);
		else j++;
	}
	if(i==j){
		color(10);
		printf("��ѯ��������ѡ����Ϣ\n");
	}
	fclose(fp);
    color(10);
	printf("��ѡ��1.������һ�� 2.����������3.�˳�\n");
	scanf("%d",&n);
	switch(n){
	case 1:system("cls");classcheck();break;
	case 2:system("cls");welcome();break;
	case 3:exit(0);break;}

}
void stucheck()//ѧ����Ϣ��ѯ
{	
	int num=0,i,j,k,n,g, l=0, m, n1;
	char nam[20]="0";
	FILE *fp1,*fp2;
	struct Course cla[N1];
	struct Student stu[N2];
    color(15);
	gotoxy(26,4);
	printf("*************************\n");
	gotoxy(26,5);
    printf("*****ѧ����Ϣ��ѯģ��*****\n");
    gotoxy(26, 6);
    printf("  ��ѯǰ����ˢ��ϵͳ \n");
    gotoxy(26, 7);
    printf(" ********************* \n");
    gotoxy(26, 8);
    printf("  * 1.��ѧ�Ų�ѯ  *\n");
    gotoxy(26, 9);
    printf(" ********************* \n"); 
    gotoxy(26, 10);
    printf("  * 2.�����ֲ�ѯ  *\n");
    gotoxy(26, 11);
    printf(" ********************* \n");
    gotoxy(26, 12);
    printf("  * 3.������һ��  *\n");
    gotoxy(26, 13);
    printf(" ********************* \n");
    gotoxy(26, 14);
    printf("��ѡ��[1 2 3]:[ ]\b\b");
	scanf("%d",&n);
	switch(n){
	case 1:
		color(10);
		printf("����ѧ��\n");
		color(14);
		scanf("%d",&num);
		break;


	case 2:
		color(10);
		printf("��������\n");
		color(14);
		scanf("%s",nam);
		break;


	case 3:system("cls");welcome();break;
	}
	
    if((fp2=fopen("d:\\course.txt", "r"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
	for(j=0;!(feof(fp2));j++)
	fscanf(fp2,"%d%s%s%d%d%d%f%d",&cla[j].num,cla[j].name,cla[j].nature,&cla[j].toperiod,&cla[j].giperiod,&cla[j].experiod,&cla[j].credit,&cla[j].term);
	
	
	if((fp1=fopen("d:\\student.txt","r"))==NULL){printf("�޷��򿪴��ļ�\n");exit(0);}
	for(i=0;!(feof(fp1));i++)
	fscanf(fp1,"%d%s%d%d%d%d%d%d%d%d%d%d/n",&stu[i].num,stu[i].name,&stu[i].course[0],&stu[i].course[1],&stu[i].course[2],&stu[i].course[3],&stu[i].course[4],&stu[i].course[5],&stu[i].course[6],&stu[i].course[7],&stu[i].course[8],&stu[i].course[9]);
				
    for(m=0; m<i; m++)
	 if(num==stu[m].num||strcmp(nam,stu[m].name)==0){
	    printf("ѧ����Ϣ\nѧ��ѧ��:%d ѧ������:%s ѧ���γ̵ı��:%07d %07d %07d %07d %07d %07d %07d %07d %07d %07d\n",stu[m].num,stu[m].name,stu[m].course[0],stu[m].course[1],stu[m].course[2],stu[m].course[3],stu[m].course[4],stu[m].course[5],stu[m].course[6],stu[m].course[7],stu[m].course[8],stu[m].course[9]); 
		for(g=0; g<10; g++)
		   for(k=0; k<j; k++)
			   if(stu[m].course[g]==cla[k].num) printf("�γ̱��:%07d ����:%s ����:%s ��ѧʱ:%d �ڿ�ѧʱ:%d ʵ����ϻ�ѧʱ:%d ѧ��:%.2f �Ͽ�ѧ��:%d\n",cla[k].num,cla[k].name,cla[k].nature,cla[k].toperiod,cla[k].giperiod,cla[k].experiod,cla[k].credit,cla[k].term);}

	 else l++;
	if(i==l){color(10);printf("��ѯ��������ѡ����Ϣ\n");}
    fclose(fp2);fclose(fp1);
	color(10);
	printf("��ѡ��1.������һ�� 2.����������3.�˳�\n");
	scanf("%d",&n1);
	switch(n1){
	case 1:system("cls");stucheck();break;
	case 2:system("cls");welcome();break;
	case 3:exit(0);break;}

}