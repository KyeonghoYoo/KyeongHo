#include<Stdio.h>

int ArrSum(int(*arr)[4]); // �迭�� ������ ���ؼ� ��ȯ�ϴ� �Լ�

int main()
{
	int arr[5][4] = { 0 };
	int i = 0, j = 0;

	for (i = 0; i < 5; i++) // ������ �� �Է�
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%d\n", ArrSum(arr)); // �� �� ���

	return 0;
}

int ArrSum(int(*arr)[4])
{
	int i = 0, j = 0;
	int sum = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}
