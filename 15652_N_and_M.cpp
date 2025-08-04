#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>arr;
vector<int>perm;
void dfs(int st, int cd,int depth) {
	if (cd == depth) {//≈ª√‚¡∂∞«
		for (int n : perm) {
			cout << n + 1 << ' ';
		}
		cout << '\n';
		return;
	}
	int node = st;
	for (int next : arr[node]) {
		perm.push_back(next);
		dfs(next, cd+1, depth);
		perm.pop_back();
	}
}
int main(void) {
	int N, M;
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			arr[i].push_back(j);
		}
	}
	dfs(0,0,M);
	return 0;
}