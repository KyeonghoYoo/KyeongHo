#include<Stdio.h>
#include<stdlib.h>
#include<time.h>

void InputRand(int arr[]); // �迭�� ������ ���� �ʱ�ȭ �ϴ� �Լ�
void PrintArr(int arr[]);  // �迭�� ����ϴ� �Լ�
int SrcMinValue(int arr[]); // ���� ã�� ���� index + 1�� ��ȯ�ϴ� �Լ�

int main()
{
	int arr[10] = { 0 };
	int PutNum = 0;
	srand((int)time(NULL));

	InputRand(arr);
	PrintArr(arr);

	printf("\n�ּҰ��� %d�Դϴ�.\n\n", SrcMinValue(arr));

	return 0;
}

void InputRand(int arr[])
{
	int i = 0, j = 0;
	int x = 0;

	for (i = 0; i < 10; i++)
	{
		x = rand() % (100 + 1);
		for (j = 0; j <= i; j++)
		{
			if (x == arr[j])
			{
				x = rand() % (100 + 1);
				j = -1;
			}
		}
		arr[i] = x;
	}
}

void PrintArr(int arr[])
{
	int i = 0;
	printf("\n------------------------------\n");
	for (i = 0; i < 10; i++)
		printf("%2d ", i + 1);
	printf("\n------------------------------\n");
	for (i = 0; i < 10; i++)
		printf("%2d ", arr[i]);
	printf("\n");
}

int SrcMinValue(int arr[])
{
	int i = 0;
	int min = arr[0];
	for (i = 0; i < 10; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}