#include<stdio.h>
#include<string.h>
// ���ڿ����� �ش��ϴ� ���ڸ� ����� �Լ��� �����ϰ� ���ڿ��� ���ڸ� ǥ�� �Է� ���� �� 
// delchar �� �׽�Ʈ�غ��ƶ�

void mystrcat(char s1[], const char s2[])
{
	int i = 0, j = 0;
	for (i = 0;i < sizeof(s1) / sizeof(char);i++)
	{
		if (s1[i] == NULL)
		{
			s1[i] = ' ';
			i++;
			break;
		}
	}

	for (j = 0; s2[j] != NULL;j++)
	{
		s1[i] = s2[j];
		i++;
	}

	return;
}

void delchar(char str[], const char ch)
{
	int i = 0;

	for (i = 0;str[i] != NULL;i++)
	{
		if (str[i] == ch)
		{
			while (str[i] != NULL)
			{
					str[i] = str[i + 1];
				i++;
			}
			i = -1;
		}
	}

	return;
} // ���� ���ڿ����� �� ���ڸ� �����ϴ� �Լ�

int main(void)
{
	char str[30];
	char ch;
	printf("���ڿ��� ���ڸ� ���� �Է��Ͻÿ�.:");
	gets(str); // ǥ�� �Է� �Լ��� ���ڿ� �Է¹���
	scanf("%c", &ch);; // ���� �Է¹���
	delchar(str, ch); // delchar �� str ���ڿ����� ch �� ���� ���ڵ� ����
	puts(str); // str ���
	return 0;
}