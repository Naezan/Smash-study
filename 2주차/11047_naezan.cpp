#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

/*
�ر԰� ������ �ִ� ������ �� N�����̰�, ������ ������ �ſ� ���� ������ �ִ�.
������ ������ ����ؼ� �� ��ġ�� ���� K�� ������� �Ѵ�.
�̶� �ʿ��� ���� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


*/

int N, K;

//�ڿ������� ����ϱ� ���ؼ� ���� ���
stack<int> Value;
int ans = 0;

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; ++i)
	{
		int a;
		scanf("%d", &a);
		Value.push(a);
	}

	//���� �� �������� �ݺ�
	while (K != 0)
	{
		//����ū������ üũ
		int v = Value.top();
		Value.pop();

		//���� �� �� �ִ���
		if (K / v != 0)
		{
			ans += K / v;

			//�Ž�����
			K %= v;
		}
	}

	printf("%d", ans);
}