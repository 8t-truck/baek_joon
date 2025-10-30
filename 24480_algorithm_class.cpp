#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>graph[100001];
vector<bool>visited;
vector<int>result;
int countT = 0;
void dfs(int s) {
	visited[s] = true;
	result[s] = ++countT;
	for (int next : graph[s]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main(void) {
	int N, M, R;
	cin >> N >> M >> R;
	visited.resize(N + 1);
	result.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].end(), greater<>());
	}
	dfs(R);
	for (int i = 1; i < N + 1; i++) {
		cout << result[i] << '\n';
	}
	return 0;
}