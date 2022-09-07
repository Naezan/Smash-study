#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>
#include <memory.h>

using namespace std;

/*
N×M크기의 배열로 표현되는 미로가 있다.

가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다.
둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다.
i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다.
i번째 줄의 i번째 숫자는 항상 0이다.

총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다.
정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.


*/

int N;
deque<int> board[101];
bool checked[101];
int printboard[101][101];

void calc(int index, int standard);

int main()
{
	scanf("%d", &N);

	//10000
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int v;
			scanf("%d", &v);
			if (v == 1)
				board[i].push_back(j);
		}
	}

	//100 * (약)100 * 100
	for (int i = 0; i < N; ++i)
	{
		memset(checked, false, sizeof(checked));
		//(약)100 * 100
		calc(i, i);
	}
	
	//10000
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", printboard[i][j]);
		}
		printf("\n");
	}
}

void calc(int index, int standard)
{
	deque<int> boardcopy = { board[index].begin(), board[index].end() };
	while (!boardcopy.empty())
	{
		int curvalue = boardcopy.front();
		boardcopy.pop_front();

		if (checked[curvalue])
		{
			continue;
		}

		checked[curvalue] = true;
		printboard[standard][curvalue] = 1;

		calc(curvalue, standard);
	}
}