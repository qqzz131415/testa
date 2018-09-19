#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>



typedef struct node
{
	char cha;
	int chaNum;//continue chongfu
	int chaCount;
}Node;




int numCount(char *inputString)
{
char *ptr=inputString;
char *ptrTail=ptr;
int count=0;
Node array[100];
int index=0;
int i =0;


memset(array,0,sizeof(Node)*100);
while(*ptrTail!='\0')
{
	while(*ptrTail<'A'||(*ptrTail>'Z'&&*ptrTail<'a')||*ptrTail>'z')
		{
			continue;
		}
	ptr=ptrTail;
	while(*ptrTail==*(ptrTail+1)||abs(*ptrTail-*(ptrTail+1))==32)
	{
		ptrTail++;
	}
	count=ptrTail-ptr+1;

	
	for(i=index-1;i>=0;i--)
	{
		if((array[i].cha==*ptrTail||(abs(array[i].cha-*ptrTail)==32))&&array[i].chaNum==count)
			{
				array[i].chaCount+=1;		
			}
	}
	
	if(i==-1)
	{
		array[index].cha =*ptrTail;
		array[index].chaNum=count;
		array[index].chaCount=1;
		index++;
	}
	
	ptrTail++;
	ptr=ptrTail;

}
int max=array[0].chaCount;
for(int j=1;j<index;j++)
{
	if(max<array[j].chaCount)
		{
			max=array[j].chaCount;
		}
}

return max;
}
int main()
{
	char *ch="abbabbDAcAAdAsssa";
	int num=0;
	num=numCount(ch);
	printf("%d\n",num);
}









