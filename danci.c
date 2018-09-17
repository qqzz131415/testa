#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct word
{
	char * ptr;
	int num;
}word;

int  doSort(char *in,char *ou)	
{
	
	word myword[100];
	int i =0;
	memset(myword,0,sizeof(word)*100);
	char *inS = (char *)malloc(strlen(in)+1);
	memcpy(inS,in,strlen(in)+1);
	char *inspb=inS;
	char *inspe=inS;
	while(1)
	{
		while(*inspe!=' '&&*inspe!='\0')
		{
			inspe++;
		}
		int len=inspe-inspb;
		char p=*inspe;
		*inspe='\0';
		int f=0;
		for(int j =0;j<i;j++)
		{
			if(memcmp(myword[j].ptr,inspb,len+1)==0)
				{
				myword[j].num++;
				f=1;
				break;
				}
		}
		if(f==0)
		{
			char *	wordstr=(char *)malloc(len+1);
			memcpy(wordstr,inspb,len+1);
			
			myword[i].ptr=wordstr;
			myword[i].num=1;
			i++;
		}
		if(p=='\0')
			{
			break;	
			}
		else
			{
			inspe++;
			}
		inspb=inspe;
		
	}
	for(int j=0;j<i-1;j++)
	{	
		for(int k=0;k<i-1-j;k++)
		{
			if(myword[k].num<myword[k+1].num)
			{
				char *swap=myword[k].ptr;
				int nums=myword[k].num;
				myword[k].ptr=myword[k+1].ptr;
				myword[k].num=myword[k+1].num;
				myword[k+1].ptr=swap;
				myword[k+1].num=nums;
			}
			
		}
	}
	int j =0;
	for(j =0;j<i-1;j++)
	{
		int m=strlen(myword[j].ptr);
			memcpy(ou,myword[j].ptr,m);
			*(ou+m)=' ';
			ou=ou+m+1;
	}
		int m=strlen(myword[j].ptr);
			memcpy(ou,myword[j].ptr,m);
			*(ou+m)='\0';

}

int main()
{
	char *str="there is where there is a a a";
	char out[50]={0};
	doSort(str,out);	
	printf("%s\n",out);
}


