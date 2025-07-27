#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	vector<int> dp(n+1,50000);//�ּڰ��� �ʱ�ȭ �ϴ� ��� ū ���� �ʱ�ȭ!
	for (int i = 0; i * i <= n; i++) {
		dp[i * i] = 1;
	}
	for (int c = 1; c <= n; c++) {
		if (dp[c] == 1)
			continue;
		for (int i = 0; i * i < c; i++) {
			dp[c] = min(dp[c], dp[i * i] + dp[c - i * i]);
		}
		//cout << dp[c] << ' ';
	}
	cout << dp[n];
	return 0;
}