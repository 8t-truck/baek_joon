#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//bfs�� ����Ͽ� Ǯ��
void bfs(long long x, long long t)
{
	//queue<int> q;
	vector<vector<long long>> v(31);
	v[0].push_back(x);
	long long s = x;
	//cout << s;
	for (int i = 0; i <= 29; i++)
	{
		//cout << "���� v[i]�� ������: " << v[i].size();//2 162 �϶� 1�̾�
		while (v[i].size()!=0)
		{
			//cout << "�ݺ��� ����";
			s = v[i].back();
			//cout << "����:" << s;
			v[i].pop_back();
			if (s * 10 + 1 <= t)
			{
				v[i + 1].push_back(s * 10 + 1);
				//cout <<i<<'��' << s * 10 + 1 << ' '<<endl;
			}
			if (s * 2 <= t)
			{
				v[i + 1].push_back(s * 2);
				//cout <<i<<'��'<< s * 2 << ' ';
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