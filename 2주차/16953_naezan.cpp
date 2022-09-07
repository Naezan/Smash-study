#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.

2를 곱한다.
1을 수의 가장 오른쪽에 추가한다.(*10 + 1)
A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.

첫째 줄에 A, B (1 ≤ A < B ≤ 109)가 주어진다.

A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값을 출력한다. 만들 수 없는 경우에는 -1을 출력한다.

재귀함수로 한번 풀어보자
*/

long A, B;

int calc(int index, long value);

int main()
{
	scanf("%d %d", &A, &B);

	printf("%d", calc(1, A));
}

int calc(int index, long value)
{
	//값이 같다면 현재시도한 횟수 반환
	if (value == B)
	{
		return index;
	}
	//값이 작다면 수행
	else if(value < B)
	{
		//두가지 연산을 각각처리해서 최소수행횟수를 반환
		int multwo = calc(index + 1, value * 2);
		int plusrightone = calc(index + 1, value * 10 + 1);

		//인덱스가 존재하면 반환
		if (multwo != -1)
		{
			return multwo;
		}
		else if (plusrightone != -1)
		{
			return plusrightone;
		}
	}

	//그외에는 실패처리
	return -1;
}