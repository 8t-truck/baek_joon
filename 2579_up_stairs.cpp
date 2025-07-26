//계단 오르기 ~7/28
#include<iostream>
using namespace std;
int main(void) 
{
	int arr[301], dp[301];
	int sCount;
	cin >> sCount;
	for (int i = 0; i < sCount; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0]; dp[1] = arr[0] + arr[1];
	if (arr[0] < arr[1]) {
		dp[2] = arr[1] + arr[2];
	}
	else {
		dp[2] = arr[0] + arr[2];
	}
	for (int i = 2; i < sCount; i++) {
		int sum1 = dp[i - 2] + arr[i];
		int sum2 = dp[i - 3] + arr[i - 1] + arr[i];
		dp[i] = max(sum1, sum2);
	}
	cout << dp[sCount-1];
	return 0;
}