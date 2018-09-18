

typedef struct node
{
	int nfactor;//xishu
	int nindex;//zhishu
}Node;

Node a[100]={0};
memset(a,0,sizeof(Node)*100);
int arrayIndex=0;
int i;



for( i = arrayIndex-1;i>=0;i--)
{
	if(a[i].nindex==index)
	{
	   a[i].nfactor+=factor;
	}

}
if(i==-1)
{
a[arrayIndex].nfactor=factor;
a[arrayIndex].nindex =nindex ;
arrayIndex++;
}

Node *swap=(Node *)malloc(sizeof(Node));

for(int i=0;i<arrayIndex-1;i++)
{
for(int j=0;j<arrayIndex-1-i;j++)
{
	if(a[j].nindex <a[j+1].nindex)
	{
		memcpy(swap,a+j,sizeof(Node));

		memcpy(a+j,a+j+1,sizeof(Node));

		memcpy(a+j+1,swap,sizeof(Node));
	}

}

}
//facotr xishu
for(int i =0;i<arrayIndex;i++)
{
	int positive = 1;
	if(a[i].nfactor==0)
	{
		continue;
	}
	if(a[i].nfactor<0)
	{
		positive=0;
		a[i].nfactor=-a[i].nfactor;
	}
	







}








