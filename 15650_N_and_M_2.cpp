#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
vector<int>r;
int N, M;
void dfs(int depth,int cd,int st) {
	if (cd == depth) {
		for (int i = 0; i < M; i++) {
			cout << r[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = st; i < N; i++) {
		r.push_back(arr[i]);
		dfs(depth,cd + 1, i + 1);
		r.pop_back();
	}
}
int main(void) {
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	
	dfs(M,0,0);
	return 0;
}