#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
���ĵǾ��ִ� �� �迭 A�� B�� �־�����. �� �迭�� ��ģ ���� �����ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� �迭 A�� ũ�� N, �迭 B�� ũ�� M�� �־�����. (1 �� N, M �� 1,000,000)
��° �ٿ��� �迭 A�� ������, ��° �ٿ��� �迭 B�� ������ �־�����. �迭�� ����ִ� ���� ������ 109���� �۰ų� ���� �����̴�.

ù° �ٿ� �� �迭�� ��ģ �� ������ ����� ����Ѵ�.
2 2
3 5
2 9

�켱����ť�� ������ �� �ִ°�?
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
			if (pred(vec[now], vec[parent]))//���簪�� ū���̸�
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
			if (pred(vec[next], vec[left]))//���簪�� �� ũ�ٸ�
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