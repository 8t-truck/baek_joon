#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int totalSite, totalPswrd;
	cin >> totalSite >> totalPswrd;
	unordered_map<string, string>list;
	for (int i = 0; i < totalSite; i++)
	{
		string ts, tps;
		cin >> ts >> tps;
		list.insert({ ts,tps });
	}
	for (int i = 0; i < totalPswrd; i++)
	{
		string st;
		cin >> st;
		cout << list[st]<<'\n';
	}
	return 0;
}