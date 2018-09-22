#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void getscore(char *instring,char *outstring)
{	
	char *instringptr=instring;
	int index=7;
	int temp=0;
	double a[7]={0};
	int i=0;
	double sum=0;
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
	double max=a[0];
	double min=a[0];
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
	char *score=(char *)malloc(strlen(instring));
	char *scoreptr=score;
	sprintf(scoreptr,"%.2lf",ave);
	while(*scoreptr!='\0')
	{
	*outstring++=*scoreptr++;
	}	
	*outstring='\0';
	free(score);
return;

}




int main()
{

	char * num="0 0 0 0 0 0 0 zzz";
	char ss[20]={0};
	getscore(num,ss);
	printf("%s\n",ss);
return 0;
}
