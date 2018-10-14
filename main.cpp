#include <string.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#define Mx getmaxx()
#define My getmaxy()
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//  Structures for gender
	typedef struct male
	{
		double sum;
		int m_cnt;
	}Male;
	typedef struct female
	{
		double sum;
		int f_cnt;
	}Female;
	
// Structures for categories	
	typedef struct First_cat
	{
		int m_cnt;
		int f_cnt;
	}F_Cat;
	typedef struct Second_cat
	{
		int m_cnt;
		int f_cnt;
	}S_Cat;
	typedef struct Third_cat
	{
		int m_cnt;
		int f_cnt;
	}T_Cat;
	typedef struct Fourth_cat
	{
		int m_cnt;
		int f_cnt;
	}Fo_Cat;
	typedef struct Fifth_cat
	{
		int m_cnt;
		int f_cnt;
	}Fi_Cat;
int main() 
{
	// Initialising all the structure element	
	int gm;int gd = DETECT;
	int x1,y1,x2,y2;
	Male male={0.0,0};
	Female fem={0.0,0};	
	F_Cat first={0,0};
	S_Cat second={0,0};
	T_Cat third={0,0};
	Fo_Cat fourth={0,0};
	Fi_Cat fifth={0,0};
	FILE* fp;
	char s[10];
	char gen;
	double sal;
	fp=fopen("Incfile.txt","w");
	printf("Enter Salary Data:\n");
	fflush(stdin);
	while(strlen(gets(s))>0)
	{
		fputs(s,fp);
		fputs("\n",fp);
	}
	fclose(fp);
	printf("----------------------");
	printf("\nContents are: \n");
	fp=fopen("Incfile.txt","r");
	while(fgets(s,9,fp)!=NULL)
	{
		printf("%s",s);
		sscanf(s,"%c %lf",&gen,&sal);
		if(gen=='M')
		{
			male.m_cnt++;
			male.sum=male.sum+sal;
			if(sal>=0.0&&sal<=50000.0)
				first.m_cnt++;
			else if(sal>=50001.0&&sal<=100000.0)
				second.m_cnt++;
			else if(sal>=100001.0&&sal<=200000.0)
				third.m_cnt++;
			else if(sal>=200001.0&&sal<=300000.0)
				fourth.m_cnt++;
			else if(sal>=30000.0)
				fifth.m_cnt++;
		}
		if(gen=='F')
		{
			fem.f_cnt++;
			fem.sum=fem.sum+sal;
			if(sal>=0.0&&sal<=50000.0)
				first.f_cnt++;
			else if(sal>=50001.0&&sal<=100000.0)
				second.f_cnt++;
			else if(sal>=100001.0&&sal<=200000.0)
				third.f_cnt++;
			else if(sal>=200001.0&&sal<=300000.0)
				fourth.f_cnt++;
			else if(sal>=30000.0)
				fifth.f_cnt++;
		}
	}
	printf("\n");
	printf("-------------------\n");
	fclose(fp);
	double mAvg=male.sum/male.m_cnt;
	double fAvg=fem.sum/fem.f_cnt;
	printf("Sr  Gender         Total Count          Average Salary\n");
	printf("-----------------------------------------------------\n");
	printf("1. Males          %-10d %20.3lf\n",male.m_cnt,mAvg);
	printf("2. Females        %-10d %20.3lf",fem.f_cnt,fAvg);
	initgraph(&gd,&gm,"C:\\TC\\BGI");
    settextstyle(4,0,2);
    outtextxy(100,603,"A");
    outtextxy(200,603,"B");
	outtextxy(300,603,"C");
	outtextxy(400,603,"D");
	outtextxy(500,603,"E");
    settextstyle(8,0,2);
	outtextxy(250,625,"CATEGORY");
  	settextstyle(8,1,2);
	outtextxy(47,400,"Percentage ");
	line(50,0,50,768);
	line(0,600,631,600);
	
	settextstyle(2,0,6);
	outtextxy(30,550,"1");
	outtextxy(30,500,"2");
	outtextxy(30,450,"3");
	outtextxy(30,400,"4");
	outtextxy(30,350,"5");
	outtextxy(30,300,"6");
	outtextxy(30,250,"7");
	outtextxy(30,200,"8");
	outtextxy(30,150,"9");
	outtextxy(30,100,"10");
	outtextxy(30,50,"11");
	outtextxy(30,1,"12");

    x1=70,y1=600;
    settextstyle(8,0,2);
    outtextxy(600,150,"YELLOW colour is for men"); 
	outtextxy(600,175,"GREEN colour is for female");
	outtextxy(600,200,"A is for 0-50000 salary");
	outtextxy(600,225,"B is for  50001-100000  salary");	
	outtextxy(600,250,"C is for 100001-200000 salary");
	outtextxy(600,275,"D is for 200001-300000 salary");
	outtextxy(600,300,"E is for greater than 300001 salary");


      y2=y1-first.m_cnt*50;
      x2=x1+30;
      settextstyle(2,0,6);
    setfillstyle(INTERLEAVE_FILL,YELLOW);   //Prepares area to fill color
      bar(x1,y1,x2,y2);
      char m1[4];
      itoa(first.m_cnt,m1,10);
      outtextxy(x1+2,y2-20,m1);
      x1=x2;
      y2=y1-first.f_cnt*50;
      x2=x1+30;
      setfillstyle(INTERLEAVE_FILL,GREEN);    //parameters are pattern and color
      bar(x1,y1,x2,y2);
	  char f1[4];
      itoa(first.f_cnt,f1,10);
      outtextxy(x1+2,y2-20,f1);		  //bar rectangle made by set fill color and pattern
      x1+=70;
      
      y2=y1-second.m_cnt*50;
      x2=x1+30;
    setfillstyle(INTERLEAVE_FILL,YELLOW);   //Prepares area to fill color
      bar(x1,y1,x2,y2);
      char m2[4];
      itoa(second.m_cnt,m2,10);
      outtextxy(x1+2,y2-20,m2);
      x1=x2;
      y2=y1-second.f_cnt*50;
      x2=x1+30;
      setfillstyle(INTERLEAVE_FILL,GREEN);    //parameters are pattern and color
      bar(x1,y1,x2,y2);
	  char f2[4];
      itoa(second.f_cnt,f2,10);
      outtextxy(x1+2,y2-20,f2);		  //bar rectangle made by set fill color and pattern
      x1+=70;
      
      y2=y1-third.m_cnt*50;
      x2=x1+30;
    setfillstyle(INTERLEAVE_FILL,YELLOW);   //Prepares area to fill color
      bar(x1,y1,x2,y2);
      char m3[4];
      itoa(third.m_cnt,m3,10);
      outtextxy(x1+2,y2-20,m3);
      x1=x2;
      y2=y1-third.f_cnt*50;
      x2=x1+30;
      setfillstyle(INTERLEAVE_FILL,GREEN);    //parameters are pattern and color
      bar(x1,y1,x2,y2);
	  char f3[4];
      itoa(third.f_cnt,f3,10);
      outtextxy(x1+2,y2-20,f3);		  //bar rectangle made by set fill color and pattern
      x1+=70;
      
      y2=y1-fourth.m_cnt*50;
      x2=x1+30;
    setfillstyle(INTERLEAVE_FILL,YELLOW);   //Prepares area to fill color
      bar(x1,y1,x2,y2);
      char m4[4];
      itoa(fourth.m_cnt,m4,10);
      outtextxy(x1+2,y2-20,m4);
      x1=x2;
      y2=y1-fourth.f_cnt*50;
      x2=x1+30;
      setfillstyle(INTERLEAVE_FILL,GREEN);    //parameters are pattern and color
      bar(x1,y1,x2,y2);
	  char f4[4];
      itoa(fourth.f_cnt,f4,10);
      outtextxy(x1+2,y2-20,f4);		  //bar rectangle made by set fill color and pattern
      x1+=70;
      
      y2=y1-fifth.m_cnt*50;
      x2=x1+30;
    setfillstyle(INTERLEAVE_FILL,YELLOW);   //Prepares area to fill color
      bar(x1,y1,x2,y2);
      char m5[4];
      itoa(fifth.m_cnt,m5,10);
      outtextxy(x1+2,y2-20,m5);
      x1=x2;
      y2=y1-fifth.f_cnt*50;
      x2=x1+30;
      setfillstyle(INTERLEAVE_FILL,GREEN);    //parameters are pattern and color
      bar(x1,y1,x2,y2);
	  char f5[4];
      itoa(fifth.f_cnt,f5,10);
      outtextxy(x1+2,y2-20,f5);		  //bar rectangle made by set fill color and pattern
      x1+=70;
	getch();
	closegraph();
    getchar();
	
	return 0;
}
