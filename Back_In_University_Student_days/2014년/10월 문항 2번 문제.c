#include<stdio.h>

int main()
{
	char str[25];
	int i;
	printf("���ڿ��� �Է��ϼ���: ");
	scanf("%s", str);
	printf("�ٲ� ���ڿ�:");
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] -= 32;
		}
		printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}