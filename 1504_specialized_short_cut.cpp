#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pp;
int N, E, v1, v2;
long long result1, result2, result;
vector<pp> graph[802];//노드출발노드,연결노드,가중치
int dstra(int start, int end) {
	vector<int> d(802, 1e9);
	priority_queue<pp> pq;
	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first * -1;//현재까지 사용된 비용
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ cost*-1, graph[now][i].first });
			}
		}
	}
	return d[end];
}
int main(void) {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {//node는 1부터
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	cin >> v1 >> v2;
	result1 += dstra(1, v1);
	result1 += dstra(v1, v2);
	result1 += dstra(v2, N);
	result2 += dstra(1, v2);
	result2 += dstra(v2, v1);
	result2 += dstra(v1, N);
	if (result1 >= 1e9|| result2 >=1e9) {
		cout << -1;
		return 0;
	}
	result = result1 > result2 ? result2 : result1;
	cout <<result;
	return 0;
}