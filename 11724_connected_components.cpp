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
	for (int i = 1; i <= node; i++) {//0 ��������
		if (!visited[i]) {
			bfs(i);
			Comp++;
		}
	}
	cout << Comp;
	return 0;
}
//bfs�� ����Ͽ� �׷����� ��ȸ�Ѵ�.
//��ȸ�� ��ġ�� �湮���� ���� ��尡 �ִٸ� �ش� ��带 �������� �ٽ� ��ȸ�Ѵ�
//�̸� �ݺ��ϰ� �� ��ȸ�� �� Ƚ���� ����Ѵ�.