#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

첫째 줄에 1보다 크거나 같고, 1,000,000보다 작거나 같은 정수 N이 주어진다.

첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

*/

int N;
int minindexes[1000001];//각각의 숫자까지 도달하는 횟수들의 최솟값들(인덱스는 도달할숫자, 값은 최소횟수)

int main()
{
	scanf("%d", &N);

	//1은 연산없이할수 있다
	minindexes[1] = 0;

	//O(N)
	for (int i = 2; i <= N; ++i)
	{
		minindexes[i] = minindexes[i - 1] + 1;//전숫자보다 1번더 시도하기때문에 1번더 카운트

		//2의 배수가 될 수 있는 조건 이전값에서 2를 곱해서 될 수 있다.
		if (i % 2 == 0)
		{
			minindexes[i] = min(minindexes[i], minindexes[i / 2] + 1);
			//ex 6 -> ([3 * 2]) 6은 3을 만들 수 있는 최솟값에 2를 1번 곱해서 도달할 수 있다.
		}
		//3의 배수라면 이전값에 2를 곱해서 될 수 있고
		//현재값에서 3을나눈값이 가지고있는 인덱스의 최솟값에서 1을더해준값이 최소 인덱스가 될 수 잇다.
		if (i % 3 == 0)
		{
			minindexes[i] = min(minindexes[i], minindexes[i / 3] + 1);
		}
	}

	printf("%d", minindexes[N]);
}
