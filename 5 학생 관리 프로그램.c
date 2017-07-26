#include<stdio.h>
#include<stdlib.h>
// �й� �̸� ���� ��� ���

typedef struct __student
{
	int studentNumber;
	char studentName[10];
	int nativelang;
	int math;
	int science;
	int sum;
	double avr;
	int rank;
}Student;

void array(Student student[]); // ��� ����
void func1(Student student[]); // ����
void func2(Student student[]); // ����
void func3(Student student[]); // ���
void func4(Student student[]); // �˻�
void func5(Student student[]); // �ε�
void func6(Student student[]); // ����

int main()
{
	int putNum = 0;
	Student student[10];

	for (int i = 0; i < 10; i++)
	{
		student[i].studentNumber = NULL;
		student[i].avr = 0.0;
	}

	while (putNum != 7)
	{
		printf("1.���� 2.���� 3.��� 4.�˻� 5.�ε� 6.���� 7.����\n>> ");
		scanf("%d", &putNum);
		switch (putNum)
		{
		case 1:
			func1(student);
			break;
		case 2:
			func2(student);
			break;
		case 3:
			func3(student);
			break;
		case 4:
			func4(student);
			break;
		case 5:
			func5(student);
			break;
		case 6:
			func6(student);
			break;
		default:
			break;
		}
	}

	return 0;
}

// ��� ����
void array(Student student[])
{
	Student temp;

	int k = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (student[j].avr < student[j + 1].avr)
			{
				temp = student[j];
				student[j] = student[j + 1];
				student[j + 1] = temp;
			}
		}
	}
	for (int i = 0; student[i].studentNumber != NULL; i++)
		student[i].rank = i + 1;

	return;
}

// ����
void func1(Student student[])
{
	int i = 0, j = 0;

	for (i = 0; student[i].studentNumber != NULL; i++);
	printf("�й��� �Է����ּ���.\n>>");
	scanf("%d", &student[i].studentNumber);
	printf("�̸��� �Է����ּ���.\n>>");
	scanf("%s", student[i].studentName);
	printf("���� ������ �Է����ּ���.\n>>");
	scanf("%d", &student[i].nativelang);
	printf("���� ������ �Է����ּ���.\n>>");
	scanf("%d", &student[i].math);
	printf("���� ������ �Է����ּ���.\n>>");
	scanf("%d", &student[i].science);

	student[i].sum = student[i].nativelang + student[i].math + student[i].science;
	student[i].avr = (double)student[i].sum / 3.0;

	array(student);

	printf("\n");

	return;
}

// ����
void func2(Student student[])
{
	FILE* f;
	char fname[] = "student.txt";
	f = fopen(fname, "w");
	for (int i = 0;student[i].studentNumber != NULL;i++) 
		fprintf(f, "%d %s %d %d %d %d %lf %d\n", student[i].studentNumber,student[i].studentName,student[i].nativelang, student[i].math, student[i].science, student[i].sum, student[i].avr, student[i].rank);
	fclose(f);
	return;
}

// ���
void func3(Student student[])
{
	int i = 0;
	printf("  �й�    �̸�   ����  ����  ����  ����  ���  ���\n");
	for (i = 0; student[i].studentNumber != NULL; i++)
	{
		printf("%d  %s  %d    %d    %d   %d   %.1lf   %d\n", student[i].studentNumber, student[i].studentName, student[i].nativelang, student[i].math, student[i].science, student[i].sum, student[i].avr, student[i].rank);
	}
	printf("\n");

	return;
}

// �˻�
void func4(Student student[])
{
	int i = 0, putnum = 0;

	printf("�й� ���: ");
	for (i = 0;student[i].studentNumber != NULL;i++)
		printf("%d ", student[i].studentNumber);
	printf("\n");

	printf("�й��� �Է����ּ���.\n>>");
	scanf("%d", &putnum);

	for (i = 0;student[i].studentNumber != putnum;i++);

	printf("  �й�    �̸�   ����  ����  ����  ����  ���  ���\n");
	printf("%d  %s  %d    %d    %d   %d   %.1lf   %d\n", student[i].studentNumber, student[i].studentName, student[i].nativelang, student[i].math, student[i].science, student[i].sum, student[i].avr, student[i].rank);
	printf("\n");

	return;
}

// �ε�
void func5(Student student[])
{
	FILE* f;
	char fname[] = "student.txt";
	f = fopen(fname, "r");
	for (int i = 0;!feof(f);i++)
		fscanf(f, "%d %s %d %d %d %d %lf %d\n", &student[i].studentNumber, student[i].studentName, &student[i].nativelang, &student[i].math, &student[i].science, &student[i].sum, &student[i].avr, &student[i].rank);
	fclose(f);
	return;
}

// ����
void func6(Student student[])
{
	int i = 0, putnum = 0;

	printf("�й� ���: ");
	for (i = 0;student[i].studentNumber != NULL;i++)
		printf("%d ", student[i].studentNumber);
	printf("\n");

	printf("�й��� �Է����ּ���.\n>>");
	scanf("%d", &putnum);

	for (i = 0;student[i].studentNumber != putnum;i++);

	student[i].studentNumber = NULL;
	student[i].avr = 0.0;

	array(student);

	return;
}