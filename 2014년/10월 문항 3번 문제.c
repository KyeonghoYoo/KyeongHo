#include<stdio.h>

int main()
{
	int count1 = 0, count2 = 0, condition1;
	char str[80];
	printf("�ڵ� �� ��(80�� �̳�)�� �Է����ּ���.\n");
	scanf("%s", str);
	for (condition1 = 0; str[condition1] != '\0'; condition1++)
	{
		if (count1 == count2)
		{
			if (str[condition1] == '(')
			{
				count1++;
			}
			else if (str[condition1] == ')')
			{
				count2++;
			}
		}
		else
		{
			if (count1 > count2 && str[condition1] == '(')
			{
				count1++;
			}
			else if (count1 > count2 && str[condition1] == ')')
			{
				count2++;
			}
		}
	}
	printf("%d %d\n", count1, count2);
    if (count1 == count2)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}