typedef int elem
typedef max 10
typedef struct qu
{
	elem *base;
	int front;
	int rear;
}qu,*pqu;
pqu init()
{
	pqu myqu=(pqu)malloc(sizeof(qu));
	elem *mybase=(elem*)malloc(max*sizeof(elem));
	memset(mybase,0,max*sizeof(elem));
	myqu->base = mybase;
	myqu->front = 0;
	myqu->rear = 0;
	return myqu;
}


