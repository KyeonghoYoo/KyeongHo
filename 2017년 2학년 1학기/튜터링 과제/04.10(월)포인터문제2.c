#include<stdio.h>

int putValue(int *idx_x, int *idx_y, int *addnum); // �� �Է� �Լ�
void addValue(int (*arr)[5], int idx_x, int idx_y, int addnum); // ���ϴ� �ε����� ������ ������Ű�� �Լ�
void printarr(int (*arr)[5]); // �迭 ����Լ�
int main()
{
	int arr[5][5] = { 0 };
	int putidx_x = 0, putidx_y = 0, addnum = 0;

	while (putValue(&putidx_x, &putidx_y, &addnum)) // �� �� ���� 0�� ������ putValue�Լ��� 0�� ��ȯ�Ѵ�. 
	{
		addValue(arr, putidx_x, putidx_y, addnum);

		printarr(arr);
	}

	return;
}

int putValue(int *idx_x, int *idx_y, int *addnum)
{
	printf("������ �ε���(arr[x][y]) �Է�(x, y < 5) :");
	scanf("%d %d", idx_x, idx_y);
	printf("arr[%d][%d]�� �� �� ���� �Է�(����'0') :", *idx_x, *idx_y);
	scanf("%d", addnum);
	if (*addnum == 0)
		return 0;
	return 1;
}

void addValue(int (*arr)[5], int idx_x, int idx_y, int addnum)
{
	arr[idx_x][idx_y] += addnum;
	return;
}

void printarr(int (*arr)[5])
{
	int i = 0, j = 0;
	for (i = 0;i < 5;i++)
	{
		for (j = 0;j < 5;j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return;
}