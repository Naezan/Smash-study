#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

/*
* N���� ������ �־�����.
* ������ N���� �������� S(����), T(��)�ð��� �Է����� �־�����.
* �ּ��� ���ǽǿ��� ��� ������ �ϴ� ���ǽ��� ������?
*/

bool compare(pair<int, int>& i, pair<int, int>& j)
{
	if (i.first == j.first)
	{
		return i.second < j.second;
	}
	else
	{
		return i.first < j.first;
	}
}

int N, S, T;

priority_queue<int, vector<int>, greater<int>> lectureroom;

deque<pair<int, int>> classtimes;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &S, &T);
		classtimes.push_back(make_pair(S, T));
	}

	//�������� ����
	sort(classtimes.begin(), classtimes.end(), compare);

	while (!classtimes.empty())
	{
		int s = classtimes.front().first;
		int t = classtimes.front().second;
		classtimes.pop_front();

		if (lectureroom.empty())
		{
			lectureroom.push(t);
			continue;
		}

		//���� ���ǽ�. 
		if (lectureroom.top() <= s)
		{
			lectureroom.pop();
			lectureroom.push(t);
		}
		//�ٸ� ���ǽ�
		else
		{
			lectureroom.push(t);
		}
	}

	printf("%d", lectureroom.size());
}