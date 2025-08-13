#include<iostream>
#include<vector>
using namespace std;
int N, cnt = 1, maxCnt = 1;
vector<int> arr;
vector<bool>visited;
void dfs(int st) {
	if (st == N) {
		if (maxCnt <= cnt) {
			maxCnt = cnt;
		}
		return;
	}
	for (int i = st; i < N; i++) {
		if (!visited[i] && (arr[st] < arr[i])) {
			visited[i] = true;
			cnt++;
			dfs(i+1);
			cnt--;
			visited[i] = false;
		}
	}
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	visited.resize(N);
	dfs(0);
	cout << maxCnt;
}