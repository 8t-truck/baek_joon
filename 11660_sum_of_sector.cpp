#include<iostream>
#include<vector>//벡터를 이차원으로 받을거 없이 일차원을 받아서 구간합을 구하면 되지않을까?
using namespace std;
int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Time, result;
	cin >> N >> Time;
	vector<vector<int>> arr(N, vector<int>(N));
	
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			int t;
			cin >> t;
			sum += t;
			arr[i][j] = sum;
		}
	}
	//vector<vector<int>> Sum(arr.begin(),arr.end());
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] += arr[i - 1][j];
		}
	}

	for (int i = 0; i < Time; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == 1 && y1 == 1) {
			result = arr[x2 - 1][y2 - 1];
		}
		else if (x1 == 1) {
			result = arr[x2 - 1][y2 - 1] - arr[x2 - 1][y1 - 2];
		}
		else if (y1 == 1) {
			result = arr[x2 - 1][y2 - 1] - arr[x1 - 2][y2 - 1];
		}

		else {
			result = arr[x2 - 1][y2 - 1] - arr[x2 - 1][y1 - 2] - arr[x1 - 2][y2 - 1] + arr[x1 - 2][y1 - 2];
		}
		cout << result<<'\n';
	}

	

	return 0;
}