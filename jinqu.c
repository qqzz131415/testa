#include<stdio.h>
#include<stdlib.h>
void getscore(char *instring,char *outstring)
{	
	char *instringptr=instring;
	int index=7;
	int temp=0;
	int a[7]={0};
	int i=0;
	int max=0;
	int min=10;
	int sum=0;
	while(index--)
	{
		temp=atoi(instring);
		a[i++]=temp;
	
		while(*instring!=' ')
		{
			instring++;
		}
		instring++;
	}
	while(*instring!='\0')
	{
		*outstring++=*instring++;
	}
	for(int j=0;j<7;j++)
	{
		if(max<a[j])
		{
			max=a[j];
		}
		if(min>a[j])
		{
			min=a[j];
		}
		sum+=a[j];
	}
	double ave=(sum-max-min)/5.0;
	*outstring++=' ';
	char *score=(char *)malloc(4);
	sprintf(score,"%.2lf",ave);
	while(*score!='\0')
	{
	*outstring++=*score++;
	}	
	*outstring='\0';
return;

}




int main()
{

	char * num="0 0 0 0 0 0 0 zhoujianqiang";
	char ss[20]={0};
	getscore(num,ss);
	printf("%s\n",ss);
return 0;
}
