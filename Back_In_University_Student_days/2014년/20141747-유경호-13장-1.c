#include<stdio.h>
#include<math.h>

struct point // ����ü point ����
{
	double x, y;
};

void main()
{
	struct point pos1, pos2; // ����ü ���� pos1, pos2 ����
	printf("1��° ��ǥ�� �Է��ϼ���. (x,y) : ");
	scanf("%lf %lf", &pos1.x, &pos1.y);
	printf("2��° ��ǥ�� �Է��ϼ���. (x,y) : ");
	scanf("%lf %lf", &pos2.x, &pos2.y);
	printf("���� ������ �Ÿ��� %0.2lf�Դϴ�.\n", sqrt((pos1.x - pos2.x)*(pos1.x - pos2.x) + (pos1.y - pos2.y)*(pos1.y - pos2.y)));
}