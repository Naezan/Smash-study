#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>
#include <memory.h>

using namespace std;

/*
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

����ġ ���� ���� �׷��� G�� �־����� ��, ��� ���� (i, j)�� ���ؼ�, i���� j�� ���� ��ΰ� �ִ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����.
��° �ٺ��� N�� �ٿ��� �׷����� ���� ����� �־�����.
i��° ���� j��° ���ڰ� 1�� ��쿡�� i���� j�� ���� ������ �����Ѵٴ� ���̰�, 0�� ���� ���ٴ� ���̴�.
i��° ���� i��° ���ڴ� �׻� 0�̴�.

�� N���� �ٿ� ���ļ� ������ ������ ������� �������� ����Ѵ�.
���� i���� j�� ���� ��ΰ� ������ i��° ���� j��° ���ڸ� 1��, ������ 0���� ����ؾ� �Ѵ�.


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

	//100 * (��)100 * 100
	for (int i = 0; i < N; ++i)
	{
		memset(checked, false, sizeof(checked));
		//(��)100 * 100
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