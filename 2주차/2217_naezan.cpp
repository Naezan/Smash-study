#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
N(1 ≤ N ≤ 100,000)개의 로프가 있다.
각각의 로프는 들 수 있는 물체의 중량이 서로 다를 수도 있다.
여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다.
k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.
각 로프들에 대한 정보가 주어졌을 때, 이 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는 프로그램을 작성하시오.
모든 로프를 사용해야 할 필요는 없으며, 임의로 몇 개의 로프를 골라서 사용해도 된다.

첫째 줄에 정수 N이 주어진다. 다음 N개의 줄에는 각 로프가 버틸 수 있는 최대 중량이 주어진다. 이 값은 10,000을 넘지 않는 자연수이다.
2
10
15
ans : 20

10
1
2
3
4
5
6
7
8
9
10

k개를 뽑았을 때 가장 작은값 * k
그 값이 가장 클때 그 큰값을출력
k개를 어떻게 뽑지?
크기순 정렬후에 뽑으면 된다
*/

int N;
vector<int> Weight(100001);

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		int w;
		scanf("%d", &w);
		Weight[i] = w;
	}

	//내림차순정렬
	sort(Weight.begin(), Weight.end(), greater<int>());

	int TotalWeightMax = -1;
	//1개를뽑을때의 최댓값은 제일큰값(1개중제일작은값은 본인), 2개를뽑을때의 최댓값은 제일작은값에서2배 ...
	//초점은 제일작은값이 제일크면된다.
	//그래서 큰순으로정렬후 인덱스가0이면 1개뽑은경우 인덱스가 1이면 0,1로 2개를뽑은경우(제일큰수중)
	//제일 큰 수 중에 최솟값을 구할 수 있다.
	for (int i = 0; i < N; ++i)
	{
		int WeightMax = Weight[i] * (i + 1);
		if (WeightMax > TotalWeightMax)
			TotalWeightMax = WeightMax;
	}

	printf("%d", TotalWeightMax);
}