#include<stdio.h>

/*���� �������� �Է��ϸ� �� �ȿ� �����θ� �̷���� ��� ���� ������ ����ϴ� �ڵ�*/

int main(void)
{
	int area = 0;      // ������ ����
	int i1 = 0, i2 = 0;// x, y �� �ش��ϴ� ����
	int count = 0;     // ī��Ʈ �� ����
	printf("���� �������� �Է��Ͻÿ�:");
	scanf("%d", &area);                 // ������ �Է�

	for (i1 = area; i1 >= -area; i1--)
	{
		for (i2 = area; i2 >= -area;i2--)
		{
			if (((i1*i1) + (i2*i2)) <= (area*area)) // (0,0)�� (x, y)�� �Ÿ��� area�� ���ų� �������� ī��Ʈ
			{
				count++;
				printf("(%d, %d) ", i1, i2);
			}
		}
	}
	printf("\n������ ������ �̷���� ����� ���� ����:%d\n", count); // ī��Ʈ ���
	return 0;
}