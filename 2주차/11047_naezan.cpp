#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

/*
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다.
이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.


*/

int N, K;

//뒤에값부터 사용하기 위해서 스택 사용
stack<int> Value;
int ans = 0;

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; ++i)
	{
		int a;
		scanf("%d", &a);
		Value.push(a);
	}

	//돈을 다 쓸때까지 반복
	while (K != 0)
	{
		//제일큰돈부터 체크
		int v = Value.top();
		Value.pop();

		//돈을 뺄 수 있는지
		if (K / v != 0)
		{
			ans += K / v;

			//거스름돈
			K %= v;
		}
	}

	printf("%d", ans);
}