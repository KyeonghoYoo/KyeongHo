#include<stdio.h>

void inputarr(int(*arr)[10], int a, int b);// ���� ���� ���̿� ���� ���ڸ� arr �迭�� �־��ִ� �Լ� ����
void printfarr(int(*arr)[10], int a, int b);// inputarr ���� arr�� �־��� ���ڸ� ������ִ� �Լ� ����
void printS(int count, int *arr2);// ShortestDistances �Լ��� ���� �ִ� �Ÿ��� ����ϴ� �Լ� ����
void ShortestDistance(int(*arr)[10], int aSIZE, int bSIZE, int a, int b, int count, int arr2[]);// �ִ� �Ÿ��� ���ϴ� �Լ� ����


int main(void)
{
	int arr[10][10] = { 0 }; // ���� ���ο� ���� ������� ���� ���� �迭!
	int arr2[20] = { 0 };    // �ִ� �Ÿ��� ���� �迭!
	int PutN1 = 0, PutN2 = 0;// ����, ���� ����

	printf("���� ���� ���̸� �Է��Ͻÿ�.(0 < N <= 10):");
	scanf("%d %d", &PutN1, &PutN2); // ����, ���� �Է�
	printf("\n");
	inputarr(arr, PutN1, PutN2); // �迭�� �Էµ� ���� ���� ���� ���� arr�� ���� �־��ִ� �Լ�
	printfarr(arr, PutN1, PutN2);// �迭 ������ִ� �Լ�
	printf("\n");
	printf("- ��� �ִ� �Ÿ� -\n");
	ShortestDistance(arr, PutN1, PutN2, 0, PutN2 - 1, 0, arr2); // �ִܰŸ� ������ִ� �Լ� ~.~
	printf("\n");
	return 0;
}

void inputarr(int(*arr)[10], int a, int b)
{
	int i = 0, j = -1, k = 0;
	int Num1 = 1;

	for (i = b - 1;i >= 0;i--) // ���� �� ĭ�� �̵�
	{
		if (j < 0)    // ������׷� ���ڸ� ä��� ���� ���ǹ� j�� 0���� ������ ���������� ũ�� �������� ä����
		{
			j++;
			while (j < a)
			{
				arr[i][j] = Num1;
				Num1++;
				j++;
			}
		}
		else
		{
			j--;
			while (j >= 0)
			{
				arr[i][j] = Num1;
				Num1++;
				j--;
			}
		}
	}
	return;
} // ���� ���� ���̿� ���� ���ڸ� arr �迭�� �־��ִ� �Լ� 

void printfarr(int(*arr)[10], int a, int b)
{
	int i = 0, j = 0;

	for (i = 0;i < b;i++)
	{
		for (j = 0;j < a;j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	return;
} // inputarr ���� arr�� �־��� ���ڸ� ������ִ� �Լ� 

void printS(int count, int *arr2)
{
	int i = 0;

	for (i = 0; i <= count;i++)
		printf("%d ", arr2[i]);
	printf("\n");

	return;
} // ShortestDistances �Լ��� ���� �ִ� �Ÿ��� ����ϴ� �Լ�

void ShortestDistance(int(*arr)[10], int aSIZE, int bSIZE, int a, int b, int count, int arr2[])
{

	if (b == 0 && a == aSIZE - 1)
	{
		arr2[count] = arr[b][a];
		printS(count, arr2); // ���� ������ printS �Լ��� ���

		return;
	}

	if (a < aSIZE) // ���������� �̵�
	{
		arr2[count] = arr[b][a];
		ShortestDistance(arr, aSIZE, bSIZE, a + 1, b, count + 1, arr2);
	}
	if (b > 0) // ���� �̵�
	{
		arr2[count] = arr[b][a];
		ShortestDistance(arr, aSIZE, bSIZE, a, b - 1, count + 1, arr2);
	}

} // �ִ� �Ÿ��� ���ϴ� �Լ�

