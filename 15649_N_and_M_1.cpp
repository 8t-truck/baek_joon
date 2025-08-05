#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>arr;
vector<bool>visited;
vector<int> perm;
void dfs(int st, int cd, int depth){
	if (cd == depth) {
		for (int num : perm) {
			cout << num + 1 << ' ';
		}
		cout << '\n';
		return;
	}
	int next = st;
	/*visited[next] = true;
	perm.push_back(next);*///루트노드니까 넘어가고
	for (int node : arr[next]) {
		if (!visited[node]) {
			visited[node] = true;
			perm.push_back(node);
			dfs(node, cd + 1, depth);
			visited[node] = false;
			perm.pop_back();
		}
	}
}
int main(void) {
	int N, M;
	cin >> N >> M;
	arr.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i].push_back(j);
		}
	}
	dfs(0, 0, M);

	return 0;
}