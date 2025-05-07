#include<iostream>
#include<vector>
using namespace std;
void QuickSort(vector<int> &arr, int s, int e)
{
	if (s >= e)
		return;
	int p = s;
	int i = s + 1, j = e, temp;
	
	while (i <= j)//index value가 교차되기 전까지
	{
		while (i <= e && (arr[i] <= arr[p]))//피벗보다 작은 값으로 왼쪽을 남김
			i++;
		while (j > s && (arr[j] >= arr[p]))//피벗보다 큰 값으로 오른쪽을 남김
			j--;
		if (i > j)//교차 했다면...
		{
			temp = arr[j];
			arr[j] = arr[p];
			arr[p] = temp;//피벗값과 j값을 바꿔준다
		}
		else//교차하지 않았다면..>피벗보다 오른쪽에서 크거나 왼쪽에서 작은 값이 있다 
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;//i와 j를 교차해준다
		}
	}
	QuickSort(arr, s, j - 1);
	QuickSort(arr, j + 1, e);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <int> arr;
	int total,temp;
	cin >> total;
	for (int i = 0; i < total; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	QuickSort(arr,0,total-1);

	for (int i = 0; i < total; i++)
	{
		cout << arr[i] << '\n';
	}
	return 0;
}