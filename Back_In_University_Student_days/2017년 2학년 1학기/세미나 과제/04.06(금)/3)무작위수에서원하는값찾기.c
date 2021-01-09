#include<Stdio.h>
#include<stdlib.h>
#include<time.h>

void InputRand(int arr[]); // �迭�� ������ ���� �ʱ�ȭ �ϴ� �Լ�
void PrintArr(int arr[]);  // �迭�� ����ϴ� �Լ�
int SearchValue(int arr[], int PutNum); // ���� ã�� ���� index + 1�� ��ȯ�ϴ� �Լ�

int main()
{
	int arr[10] = { 0 };
	int PutNum = 0;

	srand((int)time(NULL));
	InputRand(arr);

	printf("ã�� ���� ���� �Է��Ͻÿ�(1~10):");
	scanf("%d", &PutNum);

	printf("%d ���� %d ��°�� ��ġ�ϰ� �ֽ��ϴ�.\n", PutNum, SearchValue(arr, PutNum));

	printf("���� �迭�� ����� ����\n");
	PrintArr(arr);
	printf("\n");
	return 0;
}

void InputRand(int arr[])
{
	int i = 0, j = 0;
	int x = 0;

	for (i = 0; i < 10; i++)
	{
		x = rand() % (10 + 1);
		for (j = 0; j <= i; j++)
		{
			if (x == arr[j])
			{
				x = rand() % (10 + 1);
				j = -1;
			}
		}
		arr[i] = x;
	}
}

void PrintArr(int arr[])
{
	int i = 0;
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int SearchValue(int arr[], int PutNum)
{
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		if (arr[i] == PutNum)
			return i + 1;
	}
	return -1;
}