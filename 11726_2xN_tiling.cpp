#include<iostream>
using namespace std;
int main(void)
{
	//1  2  3  4  5  6 
	//1  2  3  5  8  13
	int x;
	cin >> x;
	int arr[1001] = { 0,1,2,3,5,8,13 };
	for (int i = 6; i <= x; i++)
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;
	cout << arr[x];
	
	return 0;
}