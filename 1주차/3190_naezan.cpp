#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, K, L;

//사과 2, 플레이어1, [1][1]부터
int board[101][101];

//++할경우 D, --할경우L
int lr[4]{ 1,0,-1,0 };//오1, 왼-1
int ud[4]{ 0,1,0,-1 };//아래1, 위-1

int curDir = 0;
int totalsec = 0;

deque<pair<int, int>> playerinfo;//행, 열
queue<pair<int, char>> dirinfo;

int calc();

int main()
{
	scanf("%d", &N);//1~N까지 1보다 작거나 N보다 크면 종료
	scanf("%d", &K);

	board[1][1] = 1;
	playerinfo.push_back(make_pair(1, 1));

	for (int i = 0; i < K; ++i)
	{
		int r, c;
		scanf("%d %d", &r, &c);
		board[r][c] = 2;
	}

	scanf("%d", &L);
	for (int i = 0; i < L; ++i)
	{
		int sec; char dir;//D가 오른쪽, L이 왼쪽
		scanf("%d %c", &sec, &dir);
		dirinfo.push(make_pair(sec, dir));
	}

	printf("%d", calc());
}

int calc()
{
	while (true)
	{
		++totalsec;

		int y = playerinfo.front().first + ud[curDir];
		int x = playerinfo.front().second + lr[curDir];

		//범위밖으로 넘어가면 종료
		if (x < 1 || x > N || y < 1 || y > N)
		{
			return totalsec;
		}
		//머리와 부딪히면 종료
		if (board[y][x] == 1)
		{
			return totalsec;
		}

		//사과가 없다면 몸길이를줄여서 꼬리가 위치한 칸을비운다.
		if (board[y][x] == 0)
		{
			board[playerinfo.back().first][playerinfo.back().second] = 0;
			playerinfo.pop_back();
		}

		//사과가 있다면 그 칸의 사과가 없어지고 꼬리는 움직이지 않는다
		playerinfo.push_front(make_pair(y, x));
		board[y][x] = 1;

		//방향전환
		if (!dirinfo.empty())
		{
			int changedirtime = dirinfo.front().first;
			if (totalsec == changedirtime)
			{
				if (dirinfo.front().second == 'D')
				{
					++curDir;
					if (curDir > 3)
						curDir = 0;
				}
				else
				{
					--curDir;
					if (curDir < 0)
						curDir = 3;
				}
				dirinfo.pop();
			}
		}
	}
}