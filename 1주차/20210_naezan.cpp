#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

/*
* N����ŭ�� ���ڿ��� �־����� ���ڿ��� natural sort������� �����ؾ��Ѵ�.
* ��ҹ��� ���ڷθ� �̷���� �ִ�.
* ���ڰ� �������� ���ĺ� ������ �ϵ� ���ĺ��� ������ �빮�ڰ� �����´�.(�ƽ�Ű�ڵ忡�� ���� < �빮�� < �ҹ���)
* ���ӵ� �����ΰ�� �ϳ��� ��� �����ش�.
* ���ڿ��������� ���������� �������� �տ����� 2^63���� �ʰ��� ���� �ִ�. -> ���������� �����ϸ� �ȵȴ�.
* ���� ���� ������ ���ڿ��� ��� �տ� 0�� �ִ��� Ȯ���ϰ� 0�� �������ڿ��� ���� �´�.
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
				//ó��0�� ������ ���ڸ� �־���
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
					snum[i].push_back(make_pair(zerocount, temp));//i��°�ִ� ���ڿ��� 0�� ������ ���ڿ���
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

	//���Լ����� ���μ��ΰ� ���ڶ�� ������ ó�������� ���ϰ� ���Ŀ� �������ϴ� ��ġ�� ���ڳ����� ����
	//���ں񱳴� ������
	//���ں񱳴� �⺻���ں񱳷�

	//-1�� ���������� ��
	sort(s.begin(), s.end(), compare);

	for (int i = 0; i < N; ++i)
	{
		cout << s[i] << endl;
	}

	return 0;
}

//a�� ���������� ���̸� -1, a�� ���������� �ڸ� 1
int Integercmp(const char* a, const char* b, size_t asize, size_t bsize)
{
	if (asize == bsize)
	{
		while (asize--)
		{
			//ù��°���ڰ� �ٸ� ���
			if (!(*a == *b))
			{
				//p�� ���������� �� ���̸� -1 q�� ���������� �� ���̸� 1
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
		//���� ���� �ϳ��� �������ڳ����� ��
		if (
			(*(p) >= '0' && *(p) <= '9') &&
			(*(q) >= '0' && *(q) <= '9')
			)
		{

			int _ans = Integercmp(
				snum[pindex][index].second.c_str(), snum[qindex][index].second.c_str(),
				snum[pindex][index].second.size(), snum[qindex][index].second.size());

			// ���ڰ� ���� �ʴٸ�
			if (_ans != 0)
			{
				//���������� �з�
				return _ans;
			}
			else
			{
				//���ڿ��� �ʹݿ� 0�� �ִٸ�
				if (snum[pindex][index].first != 0 || snum[qindex][index].first != 0)
				{
					p += snum[pindex][index].first;
					q += snum[qindex][index].first;
					return snum[pindex][index].first < snum[qindex][index].first ? -1 : 1;
				}

				//���ڰ� ���ٸ�
				p += snum[pindex][index].second.size();
				q += snum[qindex][index].second.size();
				++index;
			}
		}
		//���ڳ����� ��
		else
		{
			//ù��°���ڰ� �ٸ� ���
			if (!(*p == *q))
			{
				//p�� ���������� �� ���̸� -1 q�� ���������� �� ���̸� 1
				return strcmp(p, q);
			}
			++p;
			++q;
		}
	}

	//�������ڵ鸸 �ִ°�� -> �̶��� ������ ������ �� �� �������� ���������� ���̴�
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

	//ũ�Ⱑ ū���� ������
	if (p->size() < q->size())
	{
		return true;//-1
	}
	if (p->size() > q->size())
	{
		return false;//1
	}

	//�ƹ��͵����� ����
	return false;
}
