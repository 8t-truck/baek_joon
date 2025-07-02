#include <iostream>
using namespace std;
int main(void)
{
	//1  2  3  4  5  6  7  8  9  10 11 
	//1  1  1  2  2  3  4  5  7  9  12
	int test, max = 0;
	int input[100] = { 0 };
	long long arr[100] = { 0,1,1,1,2,2,3,4,5,7,9,12};//N-1
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> input[i];
		if (input[i] > max)
			max = input[i];
	}
	for (int i = 11; i <= max; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	for (int i = 0; i < test; i++)
	{
		cout << arr[input[i]]<<'\n';
	}
	return 0;
}