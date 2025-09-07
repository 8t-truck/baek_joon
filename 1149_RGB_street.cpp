#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<vector<int>> arr(N,vector<int>(3));
	vector<vector<int>> dp(N, vector<int>(3));
	for (int i = 0; i < N; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		arr[i][0] = r; arr[i][1] = g; arr[i][2] = b;
	}
	dp[0][0] = arr[0][0]; dp[0][1] = arr[0][1]; dp[0][2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(arr[i][0] + dp[i - 1][1], arr[i][0] + dp[i - 1][2]);
		dp[i][1] = min(arr[i][1] + dp[i - 1][0], arr[i][1] + dp[i - 1][2]);
		dp[i][2] = min(arr[i][2] + dp[i - 1][0], arr[i][2] + dp[i - 1][1]);
	}
	cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
	return 0;
}