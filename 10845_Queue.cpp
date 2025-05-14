#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(void)
{
	int times;
	vector<int> q;
	string str;
	cin >> times;
	for (int i = 0; i < times+1; i++)
	{
		getline(cin, str);
		if (str.find("push") != -1)
		{
			int temp = 0;
			temp = stoi(str.substr(5));
			q.push_back(temp);
		}
		else if (str.find("pop") != -1)
		{
			if (q.empty() == true)
				cout << -1 << '\n';
			else
			{
				cout << q[0] << '\n';
				q.erase(q.begin());
			}

		}
		else if (str.find("size") != -1)
		{
			cout << q.size()<<'\n';
		}
		else if (str.find("empty") != -1)
		{
			if (q.empty() == true)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str.find("back") != -1)
		{
			if (q.empty() == true)
				cout << -1 << '\n';
			else
				cout << q[q.size() - 1] << '\n';
		}
		else if (str.find("front") != -1)
		{
			if (q.empty() == true)
				cout << -1 << '\n';
			else
				cout << q[0] << '\n';
		}
	}
	return 0;
}