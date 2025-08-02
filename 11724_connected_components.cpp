#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
void bfs(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int node = q.front();
		visited[node] = true;
		q.pop();
		for (int num : graph[node]) {
			if(!visited[num]){
				visited[num] = true;
				q.push(num);
			}
		}
	}
}
int main(void) {
	int node, edge, Comp = 0;
	cin >> node >> edge;
	graph.resize(node + 1, vector<int>(node + 1));
	visited.resize(node + 1, false);
	for (int i = 0; i < edge; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= node; i++) {//0 안지난다
		if (!visited[i]) {
			bfs(i);
			Comp++;
		}
	}
	cout << Comp;
	return 0;
}
//bfs를 사용하여 그래프를 순회한다.
//순회를 마치고 방문하지 않은 노드가 있다면 해당 노드를 시작으로 다시 순회한다
//이를 반복하고 총 순회를 한 횟수를 출력한다.