#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory.h>

using namespace std;

/*
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
*/

int T;

int num[12];

int main()
{
	scanf("%d", &T);

	//T * 3N
	for (int i = 0; i < T; ++i)
	{
		int n;
		scanf("%d", &n);

		//이전값을 만들수 있는 경우의수 + 1,2,3을 더해서 만들 수 있는 경우의 수
		num[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (i - 3 >= 0)
				num[i] += num[i - 3];
			if (i - 2 >= 0)
				num[i] += num[i - 2];
			num[i] += num[i - 1];
		}

		printf("%d\n", num[n]);
		memset(num, 0, sizeof(num));
	}
}