#include <stdio.h>
#include <stdlib.h> // itoa �Լ��� ����ϱ� ���� ��ó��
#define LOW 5 // ���μ��� 5x5
#define COL 5

void printLCD(char*dgt, char LCD[][LOW][COL]);

int main()
{
	char LCD[10][LOW][COL] = {
								{	"|||||",
									"|   |",
									"|   |",
									"|   |",
									"|||||"		}, // 0
								{	"  |  ",
									"  |  ",
									"  |  ", 
									"  |  ", 
									"  |  "		}, // 1
								{	"|||||",
									"    |",
									"|||||",
									"|    ",
									"|||||"		}, // 2
								{   "|||||",
									"    |",
									"|||||",
									"    |",
									"|||||"		}, // 3
								{   "   | ",
									"  || ",
									" | | ",
									"|||||",
									"   | " }, // 4
								{   "|||||",
									"|    ",
									"|||||",
									"    |",
									"|||||" }, // 5
								{   "|||||",
									"|    ",
									"|||||",
									"|   |",
									"|||||" }, // 6
								{   "|||||",
									"|   |",
									"    |",
									"   | ",
									"   | " }, // 7
								{	"|||||",
									"|   |",
									"|||||",
									"|   |",
									"|||||" }, // 8
								{	"|||||",
									"|   |",
									"|||||",
									"    |",
									"|||||" }, // 9
	};
	int input = 0;
	char numdigit[10];
	while(1) // ���� �ݺ�
	{
		printf("������ �Է��Ͻÿ�:");
		scanf("%d", &input);
		if (input < 0) // �Է��� ���� �����̸� �ݺ��� ��������
			break;
		itoa(input, numdigit, 10);
		printLCD(numdigit, LCD);
	}

	return 0;
}

void printLCD(char*dgt, char LCD[][LOW][COL])
{
	int i = 0, j = 0, k = 0;
	for (j = 0;j < 5;j++) // ���� �� ���� ���
	{
		for (i = 0;dgt[i] != NULL;i++) // ���ڿ��� ���ڿ� ���� ���
		{
			for (k = 0;k < 5;k++)      // dgt[i]�� �ش��ϴ� j���� ��� index ���
			{
				printf("%c", LCD[dgt[i] - 48][j][k]); 
			}
			printf(" ");
		}
		printf("\n");
	}

	return;
}