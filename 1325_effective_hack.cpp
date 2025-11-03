#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<vector<int>>graph;
int result[10001] = { 0, };

int cnt = 0;
void wonder(int s,vector<int>visited) {
	int next = s;
	visited[next] = true;
	cnt++;
	for (int nodes : graph[next]){
		if (!visited[nodes]) {
			wonder(nodes,visited);
		}
	}
}
int main(void) {
	cin >> N >> M;
	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int h, l;
		cin >> h >> l;
		graph[l].push_back(h);
	}
	int max = 0;
	for (int i = 1; i < N+1; i++) {
		vector<int> visited;
		visited.resize(N + 1);
		wonder(i,visited);
		result[i] = cnt;
		if (max < cnt) {
			max = cnt;
		}
		cnt = 0;
	}
	for (int i = 1; i < N + 1; i++) {
		if (result[i] == max) {
			cout << i <<' ';
		}
	}
	return 0;
}