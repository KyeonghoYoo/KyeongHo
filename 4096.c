#include<stdio.h>

int num = 1;

void putNumtoArr(int arr[][8][8][8]); // �迭�� ���ڸ� �ִ� �Լ�
void printArr(int arr[][8][8][8]); // �迭�� ��� ����ϴ� �Լ�

int main()
{
	int arr[8][8][8][8] = { 0 }; // 4���� �迭 arr�� ����

	putNumtoArr(arr);
	printArr(arr);

	return 0;
}

void putNumtoArr(int arr[][8][8][8])
{
	int i = 0, j = 0, k = 0, l = 0;

	for (k = 0; k < 8; k++)
	{
		for (l = 0; l < 8; l++)
		{
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 8; j++, num)
				{
					arr[k][l][i][j] = num++;
				}
			}
		}
	}

	return;
}

void printArr(int arr[][8][8][8])

{
	int i = 0, j = 0, k = 0, l = 0;

	for (k = 0; k < 8; k++)
	{
		for (i = 0; i < 8; i++)
		{
			for (l = 0; l < 8; l++)
			{
				for (j = 0; j < 8; j++, num)
				{
					printf("%4d ", arr[k][l][i][j]);
				}
				printf("\t");
			}
			printf("\n");
		}
		printf("\n\n");
	}

	return;
}