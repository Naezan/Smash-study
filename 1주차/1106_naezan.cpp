#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

/*
* C만큼의 고객을 유치해야하고 N만큼의 도시가 주어진다.
* N만큼의 도시에는 각각 m만큼의 돈으로 c만큼의 고객을 늘릴 수 있다.
* 최소한의 C만큼의 고객을 유치하는데 드는 최소비용은 얼마인가?
*
* 12 2
* 3 5(2)
* 1 1(2)
* 답 : 8
*/

int C, N;

int calc(int index, int curClientNum);

vector<pair<int, int>> cities;
vector<int> MinStore(1001, -1);

int main()
{
	scanf("%d %d", &C, &N);

	for (int i = 0; i < N; ++i)
	{
		int m, c;
		scanf("%d %d", &m, &c);

		cities.push_back(make_pair(m, c));
	}

	printf("%d", calc(0, 0));
}

int calc(int index, int curClientNum)
{
	if (curClientNum >= C)//고객수가 값을 넘어서면 이전값으로 돌아갑니다.
	{
		return 0;
	}
	if (MinStore[curClientNum] != -1)
	{
		return MinStore[curClientNum];
	}

	int EndToMoneyMin = 1000001;
	for (int i = index; i < N; ++i)
	{
		int EndToMoney = calc(0, curClientNum + cities[i].second) + cities[i].first;
		if (EndToMoney < EndToMoneyMin)
			EndToMoneyMin = EndToMoney;
	}

	//CurClientNum부터 C에 도달하기전 고객을 유치하는데 드는 최소 비용을 저장
	MinStore[curClientNum] = EndToMoneyMin;

	return EndToMoneyMin;
}

//반례
/*
* (최소한의 고객수, 도시수)
12 2
(비용, 고객수)
3 5
1 1

100 3
30 60
7 12
20 30
ans = 57

100 2
7 12
20 30
ans = 62

40 4
10 70
8 50
5 30
2 10

75 4
10 100
8 70
5 40
1 5
O

105 4
10 100
8 70
5 40
1 5
O

180 4
11 100
8 70
5 40
2 5
O

150 2
10 100
8 50

245 3
11 100
8 70
1 5
X

180 3
11 100
8 70
1 5
O
*/
