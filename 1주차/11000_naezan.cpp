#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

/*
* N개의 수업이 주어진다.
* 각각의 N개의 수업에는 S(시작), T(끝)시간이 입력으로 주어진다.
* 최소의 강의실에서 모든 수업을 하는 강의실의 개수는?
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

	//오름차순 정렬
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

		//같은 강의실. 
		if (lectureroom.top() <= s)
		{
			lectureroom.pop();
			lectureroom.push(t);
		}
		//다른 강의실
		else
		{
			lectureroom.push(t);
		}
	}

	printf("%d", lectureroom.size());
}