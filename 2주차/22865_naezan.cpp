﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cmath>

using namespace std;

/*
 $N$개의 땅 중에서 한 곳에 자취를 하려고 집을 알아보고 있다.
세 명의 친구 $A$, $B$, $C$가 있는데 이 친구들의 살고 있는 집으로부터 가장 먼 곳에 집을 구하려고 한다.
이때, 가장 먼 곳은 선택할 집에서 거리가 가장 가까운 친구의 집까지의 거리를 기준으로 거리가 가장 먼 곳을 의미한다.
예를 들어, $X$ 위치에 있는 집에서 친구 $A$, $B$, $C$의 집까지의 거리가 각각 3, 5, 4이라 가정하고
$Y$ 위치에 있는 집에서 친구 $A$, $B$, $C$의 집까지의 거리가 각각 5, 7, 2라고 하자.
이때, 친구들의 집으로부터 땅 $X$와 땅 $Y$ 중 더 먼 곳은 $X$ 위치에 있는 집이 된다.
왜냐하면 $X$에서 가장 가까운 친구의 집까지의 거리는 3이고, $Y$에서는 $2$이기 때문이다.
친구들이 살고 있는 집으로부터 가장 먼 곳을 구해보자.

첫번째 줄에 자취할 땅 후보의 개수 $N$이 주어진다.
2번째 줄에는 친구 $A$, $B$, $C$가 사는 위치가 공백으로 구분되어 주어진다.
이때 친구들은 $N$개의 땅 중 하나에 사는 것을 보장한다. (같은 위치에서 살 수 있다.)
3번째 줄에는 땅과 땅 사이를 잇는 도로의 개수 $M$이 주어진다.
그 다음줄부터 $M + 3$번째 줄까지 땅 $D$, 땅 $E$, 땅 $D$와 땅 $E$와 사이를 연결하는 도로의 길이 $L$이 공백으로 구분되어 주어진다.
이 도로는 양뱡항 통행이 가능하다.

친구들이 살고 있는 집으로부터 가장 먼 곳의 땅 번호를 출력한다.
만약 가장 먼 곳이 여러 곳이라면 번호가 가장 작은 땅의 번호를 출력한다.
*/

int N, A, B, C, M;

vector<pair<int, int>> vec[100001];
deque<pair<int, int>> ans;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)//가장 먼 곳이 여러 곳이라면
	{
		return a.second < b.second;//번호가 가장 작은 땅의 번호
	}

	return a.first > b.first;//가장 먼 곳
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

//친구들이사는 start도시에서 모든 나머지 도시들과의 최소 거리를 순서대로 저장
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
