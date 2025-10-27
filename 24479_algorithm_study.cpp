#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> graph[100001];
vector<bool> visited;
int result[100001] = { 0, };
int seq = 0;
void dfs(int s){
	visited[s] = true;
	result[s] = ++seq;
	for (int next : graph[s]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int startt;
	int N, M;
	cin >> N >> M >> startt;
	visited.resize(N+1);
	//graph.resize(N+1);
	//result.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int tempN1, tempN2;
		cin >> tempN1 >> tempN2;
		graph[tempN1].push_back(tempN2);
		graph[tempN2].push_back(tempN1);
	}
	for (int i = 1; i < N+1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(startt);
	for (int i = 1; i < N + 1; i++) {
		cout << result[i] << "\n";
	}
	return 0;
}