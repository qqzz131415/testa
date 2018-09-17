#include<stdio.h>
#include<string.h>

#define max 10
typedef int elem;
typedef struct qu
{
	elem *base;
	int front;
	int rear;
}qu,*pqu;
pqu init()
{
	pqu myqu=(pqu) malloc(sizeof(qu));
	elem *mybase=(elem *) malloc(max*sizeof(elem));
	memset(mybase,0,max*sizeof(elem));
	myqu->base = mybase;
	myqu->front = 0;
	myqu->rear = 0;
	return myqu;
}

int enqu(pqu quu, elem e)
{
	if((quu->rear+1)%max==quu->rear)
	{
		return 0;
	}
	quu->base[quu->rear]=e;
	quu->rear=(quu->rear+1)%max;
	return 1;
}
int dequ(pqu quu, elem *e)
{
	if(quu->front==quu->rear)
	{
		return 0;
	}
	*e=quu->base[quu->front];
	quu->front=(quu->front+1)%max;
	return 1;
}
int qulen(pqu quu)
{
	return((quu->rear-quu->front+max)%max);
}

int main()
{
	pqu thequ=init();
	enqu(thequ,1);	
	enqu(thequ,2);
	enqu(thequ,3);
	enqu(thequ,4);
int b=	qulen(thequ);
	printf("%d\n",b);
	int a;
	dequ(thequ,&a);
	printf("%d\n",a);
	dequ(thequ,&a);
	printf("%d\n",a);
   b=	qulen(thequ);
	printf("%d\n",b);
}








