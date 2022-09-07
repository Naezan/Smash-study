#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
 N개의 전구가 있고 맨 왼쪽에 있는 전구를 첫 번째라고 하자.
전구의 상태는 두 가지가 있으며 이를 숫자로 표현한다.
 1은 전구가 켜져 있는 상태를 의미하고, 0은 전구가 꺼져 있는 상태를 의미한다.
전구를 제어하는 명령어가 1번부터 4번까지 4개가 있다. 아래 표는 각 명령어에 대한 설명이다.

1번 명령어 [$i$ $x$] $(1 \le i \le N, 0 \le x \le 1)$ 	 $i$ 번째 전구의 상태를 $x$로 변경한다.
2번 명령어 [$l$ $r$] $(1 \le l \le r \le N)$ 	 $l$번째부터 $r$번째까지의 전구의 상태를 변경한다.
(켜져있는 전구는 끄고, 꺼져있는 전구는 킨다.)
3번 명령어 [$l$ $r$] $(1 \le l \le r \le N)$ 	 $l$번째부터 $r$번째까지의 전구를 끈다.
4번 명령어 [$l$ $r$] $(1 \le l \le r \le N)$ 	 $l$번째부터 $r$번째까지의 전구를 킨다.
주어지는 명령어를 다 수행한 결과 전구는 어떤 상태인지 알아보자.


첫 번째 줄에 전구의 개수 $N$와 입력되는 명령어의 개수 $M$이 주어진다.
두 번째 줄에는 $N$개의 전구가 현재 어떤 상태 $s$인지 주어진다. ($0$은 꺼져있는 상태, $1$은 켜져있는 상태)
 $3$ 번째 줄부터 $M + 2$ 번째 줄까지 세 개의 정수 $a, b, c$가 들어온다.
 $a$는 $a$번째 명령어를 의미하고
$b, c$는 $a$가 1인 경우는 각각 $i, x$를 의미하고
$a$가 $2, 3, 4$ 중 하나면 각각 $l, r$을 의미한다.

모든 명령어를 수행한 후 전구가 어떤 상태인지 출력한다.
*/

int N, M;
bool light[4001];

void calc(int index, int first, int second);

int main()
{
	scanf("%d %d", &N, &M);

	//N
	for (int i = 0; i < N; ++i)
	{
		int a;
		scanf("%d", &a);
		light[i] = a;
	}

	//N * M
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		//N
		calc(a, b, c);
	}

	//N
	for (int i = 0; i < N; ++i)
	{
		if (light[i])
			printf("%d ", 1);
		else
			printf("%d ", 0);
	}
}

void calc(int index, int first, int second)
{
	//1
	if (index == 1)
	{
		light[first - 1] = second;
	}
	//N
	else if (index == 2)
	{
		for (int i = first - 1; i < second; ++i)
		{
			light[i] = !light[i];
		}
	}
	//N
	else if (index == 3)
	{
		for (int i = first - 1; i < second; ++i)
		{
			light[i] = false;
		}
	}
	//N
	else if (index == 4)
	{
		for (int i = first - 1; i < second; ++i)
		{
			light[i] = true;
		}
	}
}