#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count, temp;
	vector<int> arr;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}