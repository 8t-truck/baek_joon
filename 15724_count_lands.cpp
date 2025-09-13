#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N, M, K;
	cin >> N >> M;
	vector<vector<int>>arr(N + 1, vector<int>(M + 1));
	vector<vector<int>>dp(N + 1, vector<int>(M + 1));
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			dp[i][j] = 
				dp[i][j - 1] 
				+ dp[i - 1][j] 
				- dp[i - 1][j - 1] 
				+ arr[i][j];
		}
	}
	
	/*for (int i = 0; i < N+1;i++) {
		for (auto iter : dp[i]) {
			cout << iter << ' ';
		}
		cout << endl;
	}*/
	cin >> K;
	for (int i = 0; i < K; i++) {
		int n1, m1, n2, m2;
		cin >> n1 >> m1 >> n2 >> m2;
		cout << dp[n2][m2]
			- dp[n1-1][m2]
			- dp[n2][m1-1]
			+ dp[n1-1][m1-1];
	}
	return 0;
}