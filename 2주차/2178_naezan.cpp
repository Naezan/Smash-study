#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����.
�̷��� �̷ΰ� �־����� ��,
(1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.
���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�.
ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����.
���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����.
������ ������ �پ �Է����� �־�����.

ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�.
�׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.

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
