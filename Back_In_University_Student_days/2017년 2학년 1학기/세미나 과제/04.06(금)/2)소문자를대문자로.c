#include<Stdio.h>

void InputLowercase(char arr[][4]);   // �ƽ�Ű�ڵ�� �ݺ��� �̿��� �ҹ��ڷ� �ʱ�ȭ
void printarr(char arr[][4]);         // �迭 ���
void ChangeToUppercase(char arr[][4]);// �ҹ��ڸ� �빮�ڷ� ��ȯ

int main()
{
	char arr[5][4] = { NULL };

	InputLowercase(arr);

	printarr(arr);

	printf("--------\n");

	ChangeToUppercase(arr);

	printarr(arr);
	return 0;

}

void InputLowercase(char arr[][4])
{	
	int i = 0, j = 0, lowercase = 97; // lowercase�� �ҹ��� ���ĺ� a�� �ƽ�Ű�ڵ� ���� �־��ش�.

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arr[i][j] = lowercase;
			lowercase++;              // lowercase�� �����������ν� ���ĺ��� ������� �־��ش�.
		}
	}
}

void printarr(char arr[][4])
{
	int i = 0, j = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n\n");
	}
}

void ChangeToUppercase(char arr[][4])
{
	int i = 0, j = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arr[i][j] -= 32;          // �ҹ��� ���ĺ� �ƽ�Ű �ڵ� ������ 32�� ���ָ� �빮�ڷ� �ٲ��.
		}
	}
}