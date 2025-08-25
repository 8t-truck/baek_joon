#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
vector<bool>visited;
vector<vector<int>> graph;
void dfs(int st) {
	int node = st;
	visited[node] = true;
	for (int next : graph[node]) {
		if (!visited[next]) {
			arr[next] = node;
			dfs(next);
		}
	}
}
int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	//vector<vector<int>> graph(N+1);
	arr.resize(N + 1);
	visited.resize(N + 1,false);
	graph.resize(N + 1);
	visited[0] = true;
	for(int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i < N + 1; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}