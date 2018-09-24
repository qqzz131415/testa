#include <stdio.h>
#include <stdlib.h>
void sort1(int *c,int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
        if(c[j]>c[j+1])
    	{
        t=c[j];
        c[j]=c[j+1];
        c[j+1]=t;
    	}
}
int main()
{
	int n=8;
    int a[8]={1,2,3,4,4,3,3};
	int	b[8]={2,2,2,3,2,4,1};
	sort1(a,n);
    sort1(b,n);
    int win=0;
    int j=0;
	int i=0;
    for(j=0;j<n;j++)//±éÀúÊý×é
    {
       	while(i<n&&a[i]<=b[j])
        {
            i++;
        }
		if(i<n)
		{
			i++;
			win++;
			if(win>n/2)
     			{
				printf("%d\n",1);
     				return 1;
        	    	break;
					
     			}
		}
    }
     if(win>n/2)
     	{
	printf("%d\n",1);
            return 1;
     	}
	 else
	 	{
			printf("%d\n",0);
	 		return 0;
	 	}
}
