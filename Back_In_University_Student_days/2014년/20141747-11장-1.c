#include<stdio.h>

void Swap(int*x,int*y)
{
	int temp=0;
	temp = *x;
	*x = *y;
	*y=temp;
}

int main()
{
	int x=10,y=20;
	printf("���� �ٲ����\n");
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	Swap(&x,&y);
	printf("���� �ٲ���\n");
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	return;
}