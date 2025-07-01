#include <iostream>
using namespace std;

int DP(int x)
{
	int arr[12] = { 0, 1, 2, 4, 7, 13 };
	for (int i = 6; i <= x; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	int result = arr[x];
	return result;
}
int main(void)
{
	int test, temp;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> temp;
		cout << DP(temp)<<'\n';
	}
	return 0;
}