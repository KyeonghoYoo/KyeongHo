#include<stdio.h>

struct student
{
	int student_Number;
	char Student_Name[20];
	double credit;
};

void main()
{
	struct student s1, s2, s3;
	printf("1�� �л��� ������ �Է��ϼ���.\n");
	printf("�й� : ");
	scanf("%d", &s1.student_Number);
	printf("�̸� : ");
	scanf("%s", s1.Student_Name);
	printf("���� : ");
	scanf("%lf", &s1.credit);
	printf("2�� �л��� ������ �Է��ϼ���.\n");
	printf("�й� : ");
	scanf("%d", &s2.student_Number);
	printf("�̸� : ");
	scanf("%s", s2.Student_Name);
	printf("���� : ");
	scanf("%lf", &s2.credit);
	printf("3�� �л��� ������ �Է��ϼ���.\n");
	printf("�й� : ");
	scanf("%d", &s3.student_Number);
	printf("�̸� : ");
	scanf("%s", s3.Student_Name);
	printf("���� : ");
	scanf("%lf", &s3.credit);
	if (s1.credit > s2.credit)
	{
		if (s1.credit > s3.credit)
			printf("���� ������ ���� �л��� %d %s �Դϴ�.", s1.student_Number, s1.Student_Name);
		else if (s1.credit < s3.credit)
			printf("���� ������ ���� �л��� %d %s �Դϴ�.", s3.student_Number, s3.Student_Name);
	}
	else if (s1.credit < s2.credit)
	{
		if (s2.credit > s3.credit)
			printf("���� ������ ���� �л��� %d %s �Դϴ�.", s2.student_Number, s2.Student_Name);
		else if (s2.credit < s3.credit)
			printf("���� ������ ���� �л��� %d %s �Դϴ�.", s3.student_Number, s3.Student_Name);
	}
}