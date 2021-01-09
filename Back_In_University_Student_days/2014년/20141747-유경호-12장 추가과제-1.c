#include<stdio.h>
#include<string.h>

void BigPlus(char * p, char * q, char * result)
{
	int i1 = 0, i2 = 0, i3 = 0;

	if (strlen(p) >= strlen(q))
	{
		i1 = strlen(p) - 1;
		i3 = strlen(q) - 1;
		while (i1 >= 0)
		{
			if (i3 != -1)
			{
				result[i2] += p[i1] + q[i3] - '0';
				if (result[i2] > '9')
				{
					result[i2] -= 10;
					result[i2 + 1] += 1;
				}
				if (i1 == 0)
					result[i2 + 1] += '0';
				i1--;
				i3--;
			}
			else
			{
				result[i2] += p[i1];
				if (result[i2] > '9')
				{
					result[i2] -= 10;
					result[i2 + 1] += 1;
				}
			if (i1 == 0)
				result[i2 + 1] += '0';
				i1--;
			}

			i2++;
		}
	}
	else if (strlen(p) < strlen(q))
	{
		i1 = strlen(q) - 1;
		i3 = strlen(p) - 1;
		while (i1 >= 0)
		{
			if (i3 != -1)
			{
				result[i2] += q[i1] + p[i3] - '0';
				if (result[i2] > '9')
				{
					result[i2] -= 10;
					result[i2 + 1] += 1;
				}
				if (i1 == 0)
					result[i2 + 1] += '0';
				i1--;
				i3--;
			}
			else
			{
				result[i2] += q[i1];
				if (result[i2] > '9')
				{
					result[i2] -= 10;
					result[i2 + 1] += 1;
				}
				if (i1 == 0)
					result[i2 + 1] += '0';
				i1--;
			}

			i2++;
		}
	}
}

void main()
{
	int i = 0;
	char str1[100] = { NULL }, str2[100] = { NULL }, str3[100] = { NULL };
	printf("ù��° ���� �Է��ϼ���: ");
	scanf("%s", str1);
	printf("�ι�° ���� �Է��ϼ���: ");
	scanf("%s", str2);
	BigPlus(str1, str2, str3);
	printf("�μ��� ���� ");
	for (i = strlen(str3)-2; i >= 0; i--)
		if (str3[i] != NULL)
			printf("%c", str3[i]);
	printf("\n");
}

