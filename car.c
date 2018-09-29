#include<stdio.h>

typedef struct date
{
	int year;
	int month;
	int day;
}date;

typedef struct car
{
	int numCar1;
	int numCar2;
	int numWeek;
}car;


int isleap(int yearnum)
{
	if((yearnum%4&&yearnum%100!=0)||(yearnum%400==0))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


int main()
{
	date first;
	first.year=2012;
	first.month=4;
	first.day=9;

	date last;
	last.year=2012;
	last.month=7;
	last.day=7;

	car carry[5]={0};
	carry[0].numCar1=3;
	carry[0].numCar2=8;
	carry[0].numWeek=1;
	carry[1].numCar1=4;
	carry[1].numCar2=9;
	carry[1].numWeek=2;
	carry[2].numCar1=5;
	carry[2].numCar2=0;
	carry[2].numWeek=3;
	carry[3].numCar1=1;
	carry[3].numCar2=6;
	carry[3].numWeek=4;
	carry[4].numCar1=2;
	carry[4].numCar2=7;
	carry[4].numWeek=5;

	int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int monthdayleap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	
	date someday;
	someday.year=2015;
	someday.month=3;
	int isleapyearflag=isleap(someday.year);	

	int tian=0;
	int yeargap=someday.year-2012;
	if(yeargap>=1)
	{
		for(int i =yeargap-1;i>0;i--)
		{
			if(isleap(2012+i))
			{
				tian+=366;
			}
			else
			{
				tian+=365;
			}
		}
		tian+=266;
		int monthgap=someday.month;
		for(int i=monthgap-1;i>0;i--)
		{
			if(isleap(someday.year))
			{
			tian+=monthdayleap[i-1];
			}
			else
			{
			tian+=monthday[i-1];
			}
		}
	}
	else
	{
		int monthgap=someday.month-4;
		for(int i=monthgap-1;i>0;i--)
		{
			tian+=monthdayleap[4+i];
		}
		tian+=21;
	}

	int yutian=tian%91;//jia she yutian dayu30;
	int round=tian/91;
	for(int i=0;i<5;i++)
	{
		carry[i].numWeek = (carry[i].numWeek + round)%5;
	}
	int yutianweek=tian%7;
	int carnum=3;
	int week=1;
	for(int i=0;i<5;i++)
	{
		if(carry[i].numCar1 == carnum || carry[i].numCar2==carnum)
		{
		week=carry[i].numWeek;
		}
	}
	int day[5]={0};
	day[0]=1+(week-yutianweek+7)%7;
	day[1]=day[0]+7;
	day[2]=day[1]+7;
	day[3]=day[2]+7;
	day[4]=day[3]+7;
	for(int i =0;i<5;i++)
	{
		if(day[i]>yutian)
		{
		day[i]+=1;
		}
		if(isleapyearflag==1&&day[i]>monthdayleap[someday.month-1])
		{
		day[i]=0;
		}
	}
	for(int i =0;i<5;i++)
	{
		if(day[i]!=0)
		{
		printf("%d\n",day[i]);
		}
	}



return 0;
}



