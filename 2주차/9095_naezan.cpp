#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory.h>

using namespace std;

/*
���� 4�� 1, 2, 3�� ������ ��Ÿ���� ����� �� 7������ �ִ�. ���� ��Ÿ�� ���� ���� 1�� �̻� ����ؾ� �Ѵ�.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
���� n�� �־����� ��, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���� n�� �־�����. n�� ����̸� 11���� �۴�.

�� �׽�Ʈ ���̽�����, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ����Ѵ�.
*/

int T;

int num[12];

int main()
{
	scanf("%d", &T);

	//T * 3N
	for (int i = 0; i < T; ++i)
	{
		int n;
		scanf("%d", &n);

		//�������� ����� �ִ� ����Ǽ� + 1,2,3�� ���ؼ� ���� �� �ִ� ����� ��
		num[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (i - 3 >= 0)
				num[i] += num[i - 3];
			if (i - 2 >= 0)
				num[i] += num[i - 2];
			num[i] += num[i - 1];
		}

		printf("%d\n", num[n]);
		memset(num, 0, sizeof(num));
	}
}