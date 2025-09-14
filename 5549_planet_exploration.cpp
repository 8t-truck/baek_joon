#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M, N, K;
	cin >> M >> N;
	cin >> K;
	vector<vector<int>>jungle(M + 1,vector<int>(N + 1));
	vector<vector<int>>sea(M + 1, vector<int>(N + 1));
	vector<vector<int>>ice(M + 1, vector<int>(N + 1));
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			char temp;
			cin >> temp;
			if (temp == 'J')
				jungle[i][j] = 1;
			else if (temp == 'I')
				ice[i][j] = 1;
			else
				sea[i][j] = 1;
		}
	}
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			jungle[i][j] = jungle[i - 1][j] + jungle[i][j - 1] - jungle[i - 1][j - 1] + jungle[i][j];
			sea[i][j] = sea[i - 1][j] + sea[i][j - 1] - sea[i - 1][j - 1] + sea[i][j];
			ice[i][j] = ice[i - 1][j] + ice[i][j - 1] - ice[i - 1][j - 1] + ice[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << jungle[x2][y2] - jungle[x1 - 1][y2] - jungle[x2][y1 - 1] + jungle[x1 - 1][y1 - 1]
			<<' '
			<< sea[x2][y2] - sea[x1 - 1][y2] - sea[x2][y1 - 1] + sea[x1 - 1][y1 - 1]
			<<' '
			<<ice[x2][y2] - ice[x1 - 1][y2] - ice[x2][y1 - 1] + ice[x1 - 1][y1 - 1]
			<<'\n';
	}

	return 0;
}