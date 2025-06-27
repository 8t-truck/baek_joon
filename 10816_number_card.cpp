#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(void)
{
	int sCard = 0,card = 0,temp;
	unordered_map<int, int> sang;
	vector<int> arr;
	cin >> sCard;
	for (int i = 0; i < sCard; i++)
	{
		cin >> temp;
		if (sang.find(temp) == sang.end())
			sang[temp] = 1;
		else
			sang[temp]++;
	}
	cin >> card;
	for (int i = 0; i < card; i++)
	{
		cin >> temp;
		arr.push_back(sang[temp]);

	}
	for (int i = 0; i < card; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}
