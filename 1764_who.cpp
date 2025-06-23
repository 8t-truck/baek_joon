#include <iostream>
#include<map>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
	map<string,int> hvnlist;
	int l, s, count=0;
	string temp;
	vector<string> result;
	cin >> l >> s;
	for (int i = 0; i < l; i++)
	{
		cin >> temp;
		hvnlist[temp] = 1;
	}
	for (int i = 0; i < s; i++)
	{
		cin >> temp;
		if (hvnlist[temp] == 1)
		{
			count++;
			result.push_back(temp);
		}
	}
	sort(result.begin(), result.end());
	cout << count<<'\n';
	for (int i = 0; i < count; i++)
	{
		cout << result[i]<<'\n';
	}
	return 0;
}