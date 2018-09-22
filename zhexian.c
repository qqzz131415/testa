#include<stdio.h>
#include<stdlib.h>
typedef struct point
{
int x;
int y;
int delete;
}point;
//sort();
int changePoint(char *inString,char *outString)
{
	char *inStringPtr=inString;
	char *outStringPtr=outString;
	point a[1000]={0};//shishi
	int index =0;
	while(*inStringPtr!='\0')
	{
		a[index].x=atoi(inStringPtr);
		while(*inStringPtr!=',')
		{
			inStringPtr++;
		}
		inStringPtr++;
		a[index++].y=atoi(inStringPtr);
		while(*inStringPtr!='\0' && *inStringPtr!=';')
		{
			inStringPtr++;
		}
		if(*inStringPtr!='\0')
		{
		inStringPtr++;
		}
	}
	int len=index;
	int second=1;
	int i=0;
	while(second<len&&a[second].x==a[i].x&&a[second].y==a[second].y)
		{	
			a[second].delete=1;	
			second++;
		}
	int third;
	if(second<len)
	{
		for(;i<len-2;)
		{
			third=second+1;
			while(third<len&&a[third].x==a[second].x&&a[third].y==a[second].y)
			{	
				a[second].delete=1;	
				third++;
			}
			if(third<len&&(double)(a[third].y-a[second].y)/(a[third].x-a[second].x)==(double)(a[second].y-a[i].y)/(a[second].x-a[i].x))
			{
				if(a[second].x>a[i].x&&a[third].x>=a[second].x)
				{
					a[second].delete=1;
				}
				else if(a[second].x<a[i].x&&a[third].x<=a[second].x)
				{
					a[second].delete=1;
				}
			}
			if(third<len&&a[second].delete==1)
			{
				second=third;
			}
			else if(third<len&&a[second].delete==0)
			{
				i=second;
				second=third;
			}
			else
			{
				break;	
			}
		}
	}
	char* temp=(char*)malloc(4);
	char* tempptr=temp;
	for(int i=0;i<len;i++)
	{
		if(a[i].delete==0)
		{
			sprintf(temp,"%d",a[i].x);
			tempptr=temp;
			while(*tempptr!='\0')
			{
			*outStringPtr++=*tempptr++;
			}
			*outStringPtr++=',';
			sprintf(temp,"%d",a[i].y);
			tempptr=temp;
			while(*tempptr!='\0')
			{
			*outStringPtr++=*tempptr++;
			}
			*outStringPtr++=';';
		}
	}	
	*(--outStringPtr)='\0';





}



int main()
{
	char in[]="1,1;2,2;2,2;2,3;3,4;4,5;1,1";
	char ou[100];
	changePoint(in,ou);
	printf("%s\n",ou);





}
