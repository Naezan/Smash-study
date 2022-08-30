#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, K, L;

//��� 2, �÷��̾�1, [1][1]����
int board[101][101];

//++�Ұ�� D, --�Ұ��L
int lr[4]{ 1,0,-1,0 };//��1, ��-1
int ud[4]{ 0,1,0,-1 };//�Ʒ�1, ��-1

int curDir = 0;
int totalsec = 0;

deque<pair<int, int>> playerinfo;//��, ��
queue<pair<int, char>> dirinfo;

int calc();

int main()
{
	scanf("%d", &N);//1~N���� 1���� �۰ų� N���� ũ�� ����
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
		int sec; char dir;//D�� ������, L�� ����
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

		//���������� �Ѿ�� ����
		if (x < 1 || x > N || y < 1 || y > N)
		{
			return totalsec;
		}
		//�Ӹ��� �ε����� ����
		if (board[y][x] == 1)
		{
			return totalsec;
		}

		//����� ���ٸ� �����̸��ٿ��� ������ ��ġ�� ĭ������.
		if (board[y][x] == 0)
		{
			board[playerinfo.back().first][playerinfo.back().second] = 0;
			playerinfo.pop_back();
		}

		//����� �ִٸ� �� ĭ�� ����� �������� ������ �������� �ʴ´�
		playerinfo.push_front(make_pair(y, x));
		board[y][x] = 1;

		//������ȯ
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