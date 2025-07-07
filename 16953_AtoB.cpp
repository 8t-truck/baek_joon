#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//bfs를 사용하여 풀기
void bfs(long long x, long long t)
{
	//queue<int> q;
	vector<vector<long long>> v(31);
	v[0].push_back(x);
	long long s = x;
	//cout << s;
	for (int i = 0; i <= 29; i++)
	{
		//cout << "현재 v[i]의 사이즈: " << v[i].size();//2 162 일때 1이야
		while (v[i].size()!=0)
		{
			//cout << "반복문 도입";
			s = v[i].back();
			//cout << "현재:" << s;
			v[i].pop_back();
			if (s * 10 + 1 <= t)
			{
				v[i + 1].push_back(s * 10 + 1);
				//cout <<i<<'는' << s * 10 + 1 << ' '<<endl;
			}
			if (s * 2 <= t)
			{
				v[i + 1].push_back(s * 2);
				//cout <<i<<'는'<< s * 2 << ' ';
			}
			if (s == t)
			{
				cout << i + 1;
				return;
			}
		}
		if (v[i + 1].empty())
		{
			cout << -1;
			return;
		}
	}
}
int main(void)
{
	long long x, t;
	cin >> x >> t;
	bfs(x, t);
	return 0;
}