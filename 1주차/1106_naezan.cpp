#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

/*
* C��ŭ�� ���� ��ġ�ؾ��ϰ� N��ŭ�� ���ð� �־�����.
* N��ŭ�� ���ÿ��� ���� m��ŭ�� ������ c��ŭ�� ���� �ø� �� �ִ�.
* �ּ����� C��ŭ�� ���� ��ġ�ϴµ� ��� �ּҺ���� ���ΰ�?
*
* 12 2
* 3 5(2)
* 1 1(2)
* �� : 8
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
	if (curClientNum >= C)//������ ���� �Ѿ�� ���������� ���ư��ϴ�.
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

	//CurClientNum���� C�� �����ϱ��� ���� ��ġ�ϴµ� ��� �ּ� ����� ����
	MinStore[curClientNum] = EndToMoneyMin;

	return EndToMoneyMin;
}

//�ݷ�
/*
* (�ּ����� ����, ���ü�)
12 2
(���, ����)
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
