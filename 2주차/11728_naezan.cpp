#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)
둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.
2 2
3 5
2 9

우선순위큐를 구현할 수 있는가?
*/

int N, M;

class PQ
{
public:
	void push(const int& value)
	{
		vec.push_back(value);

		int now = (int)vec.size() - 1;

		while (now > 0)
		{
			int parent = (now - 1) / 2;
			if (pred(vec[now], vec[parent]))//현재값이 큰값이면
			{
				break;
			}

			vec[now] = vec[now] ^ vec[parent];
			vec[parent] = vec[now] ^ vec[parent];
			vec[now] = vec[now] ^ vec[parent];

			now = parent;
		}
	}

	void pop()
	{
		vec[0] = vec.back();
		vec.pop_back();

		int now = 0;
		while (true)
		{
			int left = now * 2 + 1;
			int right = now * 2 + 2;

			if (left >= (int)vec.size())
			{
				break;
			}

			int next = now;
			if (pred(vec[next], vec[left]))//현재값이 더 크다면
				next = left;

			if (right < (int)vec.size() && pred(vec[next], vec[right]))
			{
				next = right;
			}

			if (next == now)
				break;

			vec[now] = vec[now] ^ vec[next];
			vec[next] = vec[now] ^ vec[next];
			vec[now] = vec[now] ^ vec[next];

			now = next;
		}
	}

	const int& top()
	{
		return vec[0];
	}

	bool empty()
	{
		return vec.empty();
	}

private:
	vector<int> vec = {};
	greater<int> pred = {};
};

int main()
{
	scanf("%d %d", &N, &M);

	PQ pq;

	for (int i = 0; i < N; ++i)
	{
		int a;
		scanf("%d", &a);
		pq.push(a);
	}

	for (int i = 0; i < M; ++i)
	{
		int b;
		scanf("%d", &b);
		pq.push(b);
	}

	while (!pq.empty())
	{
		printf("%d ", pq.top());
		pq.pop();
	}
}