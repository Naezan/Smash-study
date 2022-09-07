#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
지뢰찾기는 n × n 격자 위에서 이루어진다.
m개의 지뢰가 각각 서로 다른 격자 위에 숨겨져 있다.
플레이어는 격자판의 어느 지점을 건드리기를 계속한다.
지뢰가 있는 지점을 건드리면 플레이어가 진다. 지뢰가 없는 지점을 건드리면,
그곳의 상하좌우 혹은 대각선으로 인접한 8개의 칸에 지뢰가 몇 개 있는지 알려주는 0과 8 사이의 숫자가 나타난다.
완전히 플레이되지 않은 게임에서 일련의 동작이 아래에 나타나 있다.

여기서, n은 8이고, m은 10이며, 빈 칸은 숫자 0을 의미하고,
올라가 있는 칸은 아직 플레이되지 않은 위치이며,
별표 모양(*)과 닮은 그림은 지뢰를 의미한다.
맨 왼쪽의 그림은 일부만이 플레이된 게임을 나타낸다.
첫 번째 그림에서 두 번째 그림으로 오면서, 플레이어는 두 번의 이동을 시행해서,
두 번 다 안전한 곳을 골랐다.
세 번째 그림을 볼 때 플레이어는 운이 썩 좋지는 않았다.
지뢰가 있는 곳을 골라서 게임에서 졌다.
플레이어는 m개의 열리지 않은 칸을 남길 때까지 계속해서 안전한 곳을 고르면 이긴다.
그 m개의 칸은 반드시 지뢰이다.

첫 번째 줄에는 10보다 작거나 같은 양의 정수 n이 입력된다.
다음 n개의 줄은 지뢰의 위치를 나타낸다.
각각의 줄은 n개의 문자를 사용하여 한 행을 나타낸다.
온점(.)은 지뢰가 없는 지점이며 별표(*)는 지뢰가 있는 지점이다.
다음 n개의 줄에는 길이가 n인 문자열이 입력된다.
이미 열린 칸은 영소문자 x로, 열리지 않은 칸은 온점(.)으로 표시된다.
예제 입력은 문제 설명에서의 가운데 그림과 상응한다.

출력은 각각의 위치가 정확하게 채워진 판을 표현해야 한다.
지뢰가 없으면서 열린 칸에는 0과 8 사이의 숫자가 있어야 한다.
지뢰가 있는 칸이 열렸다면 지뢰가 있는 모든 칸이 별표(*)로 표시되어야 한다.
다른 모든 지점은 온점(.)이어야 한다.
*/

int N;

char board[11][11];
char player[11][11];

int dx[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
bool bClickMine = false;

int main()
{
	scanf("%d", &N);
	getchar();

	//최대100
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char input;
			scanf("%c", &input);
			board[i][j] = input;
		}
		getchar();
	}

	//최대100
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char input;
			scanf("%c", &input);
			player[i][j] = input;
		}
		getchar();
	}

	//최대800
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			//클릭을했다면
			if (player[i][j] == 'x')
			{
				//먼저 현재지점이 지뢰인지 확인
				if (board[i][j] == '*')
				{
					bClickMine = true;
				}
				//이후 8방향이 지뢰인지 확인
				else
				{
					int minecount = 0;
					for (int k = 0; k < 8; ++k)
					{
						int x = j + dx[k];
						int y = i + dy[k];
						if (x < 0 || x >= N || y < 0 || y >= N)
							continue;

						if (board[y][x] == '*')
							++minecount;
					}
					player[i][j] = minecount + '0';
				}
			}
		}
	}

	//최대100
	if (bClickMine)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (board[i][j] == '*')
				{
					player[i][j] = '*';
				}
			}
		}
	}

	//최대100
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%c", player[i][j]);
		}
		printf("\n");
	}
}
