#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
N×M크기의 배열로 표현되는 미로가 있다.

미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
이러한 미로가 주어졌을 때,
(1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다.
칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.
다음 N개의 줄에는 M개의 정수로 미로가 주어진다.
각각의 수들은 붙어서 입력으로 주어진다.

첫째 줄에 지나야 하는 최소의 칸 수를 출력한다.
항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

DFS, BFS
*/

int N, M;
char board[101][101];
int minboard[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> path;

void calc();

int main()
{
	scanf("%d %d", &N, &M);
	getchar();

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char node;
			scanf("%c", &node);
			board[i][j] = node;
		}
		getchar();
	}

	path.push(make_pair(0, 0));//y x
	minboard[0][0] = 1;

	//40000(N * M * 4)
	calc();

	printf("%d", minboard[N - 1][M - 1]);
}

void calc()
{
	while (!path.empty())
	{
		pair<int, int> coord = path.front();
		path.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = coord.second + dx[i];
			int y = coord.first + dy[i];

			if (x < 0 || x >= M || y < 0 || y >= N)
			{
				continue;
			}

			if (minboard[y][x] != 0)
			{
				continue;
			}

			if (board[y][x] == '1')
			{
				minboard[y][x] = minboard[coord.first][coord.second] + 1;
				path.push(make_pair(y, x));
			}
		}
	}
}
