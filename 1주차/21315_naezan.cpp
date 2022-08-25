#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, MaxK;

deque<int> card;

void setupMaxK();
bool calc(deque<int>& vec, int k);
bool conc(deque<int>& vec);

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		int n;
		scanf("%d", &n);
		card.push_back(n);
	}

	setupMaxK();

	for (int i = 1; i <= MaxK; ++i)
	{
		deque<int> cardk1 (card.size());
		copy(card.begin(), card.end(), cardk1.begin());
		calc(cardk1, i);
		for (int j = 1; j <= MaxK; ++j)
		{
			deque<int> cardk2(card.size());
			copy(cardk1.begin(), cardk1.end(), cardk2.begin());
			if (calc(cardk2, j))
			{
				printf("%d %d", j, i);
				return 0;
			}
		}
	}

	return 0;
}

void setupMaxK()
{
	int tempN = N;
	while (tempN / 2 != 0)
	{
		tempN /= 2;
		++MaxK;
	}
}

bool calc(deque<int>& vec, int k)
{
	//k¼öÇà
	vector<int> first;
	vector<int> second;
	int ksize = 0;
	for (int i = 1; i <= k; ++i)
	{
		first.clear();
		second.clear();
		ksize = (int)pow(2, i - 1);

		for (std::deque<int>::iterator it = vec.begin(); it <= vec.begin() + ksize - 1; ++it)
		{
			first.push_back(*it);
		}
		for (std::deque<int>::iterator it = vec.begin() + ksize; it <= vec.begin() + ksize + ksize - 1; ++it)
		{
			second.push_back(*it);
		}

		vec.erase(vec.begin(), vec.begin() + ksize + ksize);
		vec.insert(vec.begin(), first.begin(), first.end());
		vec.insert(vec.begin(), second.begin(), second.end());
	}

	vec.insert(vec.end(), second.begin(), second.end());
	vec.insert(vec.end(), first.begin(), first.end());
	vec.erase(vec.begin(), vec.begin() + ksize + ksize);

	return conc(vec);
}

bool conc(deque<int>& vec)
{
	int j = 1;
	for (; j <= N; ++j)
	{
		if (vec[j - 1] != j)
		{
			break;
		}
	}

	if (j > N)
	{
		return true;
	}
	else
	{
		return false;
	}
}
