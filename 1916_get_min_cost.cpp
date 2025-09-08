#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int sNode, eNode;
vector<vector<pair<int, int>>> graph;//money, node
vector<bool> visited;
vector<int> cost;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dis(void) {
	cost[sNode] = 0;
	visited[sNode] = true;
	pq.push({ 0,sNode });
	while (!pq.empty()) {
		pair<int, int> n = pq.top();
		int costSector = n.first;//cost�� ���� ���� cost
		int nodeSector = n.second;//cost�� ���� ���� node
		pq.pop();
		//visited[nodeSector] = true;
		if (costSector > cost[nodeSector])
			continue;
		for (pair<int, int> iter : graph[nodeSector]) {
			int nextCost = iter.first;
			int nextNode = iter.second;
			/*if (visited[nextNode])
				continue;*/
			if (cost[nodeSector] + nextCost < cost[nextNode]){
				cost[nextNode] = cost[nodeSector] + nextCost;
				//pq�� if�� �ȿ� �־�� ���� �ۿ� �־�� ����...
				pq.push({ cost[nextNode],nextNode });
				/*visited[nextNode] = true;*/
			}
			//����� �ð��ʰ� if�� �ȿ��� Ʋ�Ƚ��ϴ�....
		}
	}
}
int main(void) {
	cin >> N >> M;
	graph.resize(N + 1);
	visited.resize(N + 1);
	cost.resize(N + 1,2000000000);
	for (int i = 0; i < M; i++) {
		int s, a, m;
		cin >> s >> a >> m;
		graph[s].push_back({ m,a });
	}
	cin >> sNode >> eNode;
	dis();
	cout << cost[eNode];
	/*for (int iter : cost) {
		cout << iter << ' ';
	}*/
	return 0;
}