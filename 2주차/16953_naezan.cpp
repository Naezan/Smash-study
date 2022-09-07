#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>

using namespace std;

/*
���� A�� B�� �ٲٷ��� �Ѵ�. ������ ������ ������ ���� �� �����̴�.

2�� ���Ѵ�.
1�� ���� ���� �����ʿ� �߰��Ѵ�.(*10 + 1)
A�� B�� �ٲٴµ� �ʿ��� ������ �ּڰ��� ���غ���.

ù° �ٿ� A, B (1 �� A < B �� 109)�� �־�����.

A�� B�� �ٲٴµ� �ʿ��� ������ �ּڰ��� 1�� ���� ���� ����Ѵ�. ���� �� ���� ��쿡�� -1�� ����Ѵ�.

����Լ��� �ѹ� Ǯ���
*/

long A, B;

int calc(int index, long value);

int main()
{
	scanf("%d %d", &A, &B);

	printf("%d", calc(1, A));
}

int calc(int index, long value)
{
	//���� ���ٸ� ����õ��� Ƚ�� ��ȯ
	if (value == B)
	{
		return index;
	}
	//���� �۴ٸ� ����
	else if(value < B)
	{
		//�ΰ��� ������ ����ó���ؼ� �ּҼ���Ƚ���� ��ȯ
		int multwo = calc(index + 1, value * 2);
		int plusrightone = calc(index + 1, value * 10 + 1);

		//�ε����� �����ϸ� ��ȯ
		if (multwo != -1)
		{
			return multwo;
		}
		else if (plusrightone != -1)
		{
			return plusrightone;
		}
	}

	//�׿ܿ��� ����ó��
	return -1;
}