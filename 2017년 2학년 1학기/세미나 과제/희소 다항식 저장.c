#include<stdio.h>

/*희소다항식 2차원 배열에 저장하기
  (9x^1000 + x^2 + 1)*/

int main()
{
	int i = 0, i2 = 0;
	int arr1[1000] = { 0 };
	arr1[0] = 9;
	arr1[997] = 1;
	arr1[999] = 1; /* 9x^1000+x^2+1 을 1차원 배열 arr1에 담게되면 arr[1]~arr[996],arr[998]에는 0이 담긴다.
				      메모리 낭비가 심하기 때문에 2차원 배열을 이용하여 저장한다.*/

	int arr2[3][2] = { 0 }; /*지수를 담을 배열은 x^1000, x^2, x^0 3개 이므로 3개까지 선언
							  지수, 계수 각각 세개씩 담아야하니 [3][2]인 2차원 배열을 선언한다.*/

	while (i < 1000) // 배열 arr1 중 0이 아닌 값의 지수, 계수를 arr2에 담는 반복문
	{
		if (arr1[i] != 0)
		{
			arr2[i2][0] = 1000 - i;
			arr2[i2][1] = arr1[i];
			i2++;
		}
		i++;
	}
	printf("%dx^%d + %dx^%d + %d\n", arr2[0][1], arr2[0][0], arr2[1][1], arr2[1][0], arr2[2][1]);
	// 2차원 배열에 저장되있는 각 지수와 계수를 출력

	// 2차원 배열을 이용하면 희소 다항식을 효율적으로 메모리에 저장할 수 있다.
	return 0;
}