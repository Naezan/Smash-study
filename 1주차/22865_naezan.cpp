#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cmath>

using namespace std;

/*
* 첫번째로 N개의 땅이 주어진다.
* 두번째로는 친구 A, B, C가 있는 땅의 위치가 주어진다.
* 세번째로 땅과 땅사이의 도로개수M이 주어지고
* 그 다음부턴 M개의 도로의 정보가 땅1, 땅2, 땅1과2사이를 연결하는 도로의 길이로 주어진다.
*/

int N, A, B, C, M;

vector<pair<int, int>> vec[100001];
deque<pair<int, int>> ans;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}

	return a.first > b.first;
}

vector<int> dijkstra(int start);

int main()
{
	scanf("%d", &N);
	scanf("%d %d %d", &A, &B, &C);
	scanf("%d", &M);

	for (int i = 0; i < M; ++i)
	{
		int D, E, L;
		scanf("%d %d %d", &D, &E, &L);

		vec[D].push_back(make_pair(E, L));//D땅에서 E땅까지 가는 도로의 길이L
		vec[E].push_back(make_pair(D, L));//E땅에서 D땅까지 가는 도로의 길이L
	}

	vector<int> dists[3];

	dists[0] = dijkstra(A);
	dists[1] = dijkstra(B);
	dists[2] = dijkstra(C);

	//i에서 A,B,C까지의 최솟값 저장
	for (int i = 1; i <= N; ++i)
	{
		int distmin = min(min(dists[0][i], dists[1][i]), dists[2][i]);
		if (distmin != 0)
			ans.push_back(make_pair(distmin, i));
	}

	sort(ans.begin(), ans.end(), compare);

	printf("%d", ans[0].second);
}

vector<int> dijkstra(int start)
{
	vector<int> distmin(N + 1, 10000000); //start에서 모든노드까지의 거리의 최솟값
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	distmin[start] = 0;
	pq.push(make_pair(0, start));//거리, 노드

	while (!pq.empty())
	{
		//가장 작은 거리를 가진노드부터 검사
		int curdist = pq.top().first;
		int curnode = pq.top().second;
		pq.pop();

		//현재노드에서 연결된 모든 도로를 탐색해서 최단경로로 갱신
		for (int i = 0; i < vec[curnode].size(); i++)
		{
			int nextdist = curdist + vec[curnode][i].second;//L
			int nextnode = vec[curnode][i].first;//E

			//노드를 처음검사했거나 최소거리보다 작은경우에만 갱신해준다
			if (nextdist < distmin[nextnode])
			{
				distmin[nextnode] = nextdist;
				pq.push(make_pair(nextdist, nextnode));//nextnode까지 가는 거리의 현재 최솟값
			}
		}
	}

	return distmin;
}
