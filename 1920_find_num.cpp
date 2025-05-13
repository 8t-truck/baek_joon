#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool BinarySearch(vector<int> &arr, int len, int target)
{
	int low = 0, high = len - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (target == arr[mid])
			return true;
		if (target < arr[mid])
		{
			high = mid - 1;
		}
		else if (target > arr[mid])
		{
			low = mid + 1;
		}
	}
	return false;
}
int main(void)
{
	int listCount, compCount,
		listTemp,compTemp;
	vector<int> list,comp;
	//입력
	cin >> listCount;
	for (int i = 0; i < listCount; i++)
	{
		cin >> listTemp;
		list.push_back(listTemp);
	}
	cin >> compCount;
	for (int i = 0; i < compCount; i++)
	{
		cin >> compTemp;
		comp.push_back(compTemp);
	}
	//정렬
	sort(list.begin(),list.end());
	//이분탐색
	for(int i=0;i<comp.size();i++)
	{
		cout << BinarySearch(list, list.size(), comp[i])<<'\n';
	}
	return 0;
}