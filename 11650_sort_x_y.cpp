#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count, x, y;
	vector<pair<int, int>> arr;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}
	sort(arr.begin(), arr.end(), [](pair<int,int>a,pair<int, int>b)
		{
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first < b.first;
		}
	);//람다함수를 공부 할 수 있도록

	for (int i = 0; i < count; i++)
	{
		cout << arr[i].first << ' ' << arr[i].second<<'\n';

	}
	return 0;
}