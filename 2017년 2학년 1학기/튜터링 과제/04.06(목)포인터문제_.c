#include<stdio.h>

void AddValue(int *ptr1, int *ptr2);
void ChangeValue(int **ptr1, int **ptr2);
void PrintValueAndAddress(int *ptr1, int *ptr2);

int main()
{
	int *ptr1 = 0, *ptr2 = 0;  // ������ ������ ���� ����
	int num1 = 0, num2 = 0;    // ������ ���� ����
	ptr1 = &num1;
	ptr2 = &num2;

	AddValue(ptr1, ptr2);      // �����͸� �̿��� �� num1�� num2�� 10, 20�� �����ִ� �Լ�

	PrintValueAndAddress(ptr1, ptr2); // ���� �ּҰ��� ����ϴ� �Լ�

	ChangeValue(&ptr1, &ptr2); // ���� ����Ű�� �ּҰ��� ��ȯ���ִ� �Լ�

	PrintValueAndAddress(ptr1, ptr2);

	return;
}

void AddValue(int *ptr1, int *ptr2)    // ^_^
{
	*ptr1 += 10;
	*ptr2 += 20;

	return;
}

void ChangeValue(int **ptr1, int **ptr2) // main �Լ��� �ִ� ������ ����*ptr1�� *ptr2�� �ּҰ��� �޴� 
{										 // ���� �����͸� �Ű������� �����Ѵ�.
	int *ptr_temp = 0;

	ptr_temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = ptr_temp;

	return;
}

void PrintValueAndAddress(int *ptr1, int *ptr2)
{
	printf("ptr1 : %d  ptr 2 : %d\n", *ptr1, *ptr2);
	printf("ptr1 : %p  ptr 2 : %p\n\n", ptr1, ptr2);

	return;
}