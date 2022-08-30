#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cmath>

using namespace std;

/*
* ù��°�� N���� ���� �־�����.
* �ι�°�δ� ģ�� A, B, C�� �ִ� ���� ��ġ�� �־�����.
* ����°�� ���� �������� ���ΰ���M�� �־�����
* �� �������� M���� ������ ������ ��1, ��2, ��1��2���̸� �����ϴ� ������ ���̷� �־�����.
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

		vec[D].push_back(make_pair(E, L));//D������ E������ ���� ������ ����L
		vec[E].push_back(make_pair(D, L));//E������ D������ ���� ������ ����L
	}

	vector<int> dists[3];

	dists[0] = dijkstra(A);
	dists[1] = dijkstra(B);
	dists[2] = dijkstra(C);

	//i���� A,B,C������ �ּڰ� ����
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
	vector<int> distmin(N + 1, 10000000); //start���� ���������� �Ÿ��� �ּڰ�
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	distmin[start] = 0;
	pq.push(make_pair(0, start));//�Ÿ�, ���

	while (!pq.empty())
	{
		//���� ���� �Ÿ��� ���������� �˻�
		int curdist = pq.top().first;
		int curnode = pq.top().second;
		pq.pop();

		//�����忡�� ����� ��� ���θ� Ž���ؼ� �ִܰ�η� ����
		for (int i = 0; i < vec[curnode].size(); i++)
		{
			int nextdist = curdist + vec[curnode][i].second;//L
			int nextnode = vec[curnode][i].first;//E

			//��带 ó���˻��߰ų� �ּҰŸ����� ������쿡�� �������ش�
			if (nextdist < distmin[nextnode])
			{
				distmin[nextnode] = nextdist;
				pq.push(make_pair(nextdist, nextnode));//nextnode���� ���� �Ÿ��� ���� �ּڰ�
			}
		}
	}

	return distmin;
}
