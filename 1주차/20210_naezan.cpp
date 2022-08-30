#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

/*
* N개만큼의 문자열이 주어지고 문자열을 natural sort방식으로 정렬해야한다.
* 대소문자 숫자로만 이루어져 있다.
* 숫자가 먼저오고 알파벳 순으로 하되 알파벳이 같으면 대문자가 먼저온다.(아스키코드에서 숫자 < 대문자 < 소문자)
* 연속된 숫자인경우 하나로 묶어서 비교해준다.
* 숫자열끼리에선 십진법으로 작은것이 앞에오고 2^63승을 초과할 수도 있다. -> 정수형으로 저장하면 안된다.
* 같은 값을 가지는 숫자열일 경우 앞에 0이 있는지 확인하고 0이 작은숫자열이 먼저 온다.
*/

int N;

vector<string> s;
vector<string> temps;
vector<vector<pair<int, string>>> snum;
string temp;

bool lettercmp(char a, char b);
int cmp(const char* p, const char* q, int pindex, int qindex, size_t n);
bool finalcmp(string* p, string* q, int pindex, int qindex);

bool compare(string& a, string& b)
{
	int aindex = (int)(find(temps.begin(), temps.end(), a) - temps.begin());
	int bindex = (int)(find(temps.begin(), temps.end(), b) - temps.begin());
	return finalcmp(&a, &b, aindex, bindex);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	s.resize(N);
	snum.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> s[i];

		int j = 0;
		int n = 0;
		int zerocount = 0;
		for (; j < (int)s[i].size(); ++j)
		{
			if (s[i][j] >= '0' && s[i][j] <= '9')
			{
				//처음0을 제외한 숫자만 넣어줌
				if (s[i][j] == '0' && n == zerocount)
				{
					++zerocount;
					++n;
				}
				else
				{
					temp += s[i][j];
					++n;
				}
			}
			else
			{
				if (n != 0)
				{
					snum[i].push_back(make_pair(zerocount, temp));//i번째있는 문자열의 0의 갯수와 숫자열들
					n = 0;
					temp.clear();
				}
			}
		}

		if (n != 0)
		{
			snum[i].push_back(make_pair(zerocount, temp));
			n = 0;
			temp.clear();
		}
	}

	temps.resize(N);
	copy(s.begin(), s.end(), temps.begin());

	//비교함수에서 서로서로가 숫자라면 숫자의 처음인지와 비교하고 비교후에 다음비교하는 위치를 숫자끝으로 변경
	//숫자비교는 십진법
	//문자비교는 기본문자비교로

	//-1이 사전적으로 앞
	sort(s.begin(), s.end(), compare);

	for (int i = 0; i < N; ++i)
	{
		cout << s[i] << endl;
	}

	return 0;
}

//a가 사전적으로 앞이면 -1, a가 사전적으로 뒤면 1
int Integercmp(const char* a, const char* b, size_t asize, size_t bsize)
{
	if (asize == bsize)
	{
		while (asize--)
		{
			//첫번째문자가 다른 경우
			if (!(*a == *b))
			{
				//p가 사전적으로 더 앞이면 -1 q가 사전적으로 더 앞이면 1
				return strcmp(a, b);
			}
			++a;
			++b;
		}

		return 0;
	}

	if (asize > bsize)
	{
		return 1;
	}
	if (asize < bsize)
	{
		return -1;
	}

	return 0;
}

int cmp(const char* p, const char* q, int pindex, int qindex, size_t n)
{
	int index = 0;
	while (n--)
	{
		//숫자 문자 하나당 숫자인자끼리의 비교
		if (
			(*(p) >= '0' && *(p) <= '9') &&
			(*(q) >= '0' && *(q) <= '9')
			)
		{

			int _ans = Integercmp(
				snum[pindex][index].second.c_str(), snum[qindex][index].second.c_str(),
				snum[pindex][index].second.size(), snum[qindex][index].second.size());

			// 숫자가 같지 않다면
			if (_ans != 0)
			{
				//십진법으로 분류
				return _ans;
			}
			else
			{
				//숫자열의 초반에 0이 있다면
				if (snum[pindex][index].first != 0 || snum[qindex][index].first != 0)
				{
					p += snum[pindex][index].first;
					q += snum[qindex][index].first;
					return snum[pindex][index].first < snum[qindex][index].first ? -1 : 1;
				}

				//숫자가 같다면
				p += snum[pindex][index].second.size();
				q += snum[qindex][index].second.size();
				++index;
			}
		}
		//문자끼리의 비교
		else
		{
			//첫번째문자가 다른 경우
			if (!(*p == *q))
			{
				//p가 사전적으로 더 앞이면 -1 q가 사전적으로 더 앞이면 1
				return strcmp(p, q);
			}
			++p;
			++q;
		}
	}

	//같은문자들만 있는경우 -> 이때는 문자의 갯수를 비교 후 작은수가 사전적으로 앞이다
	return 0;
}

bool finalcmp(string* p, string* q, int pindex, int qindex)
{
	size_t size = min(p->size(), q->size());
	int Ans = cmp(p->c_str(), q->c_str(), pindex, qindex, size);

	if (Ans != 0)
	{
		if (Ans == 1)
			return false;
		else if (Ans == -1)
			return true;
	}

	//크기가 큰값이 오른쪽
	if (p->size() < q->size())
	{
		return true;//-1
	}
	if (p->size() > q->size())
	{
		return false;//1
	}

	//아무것도하지 않음
	return false;
}
