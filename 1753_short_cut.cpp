#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1e9;
typedef pair<int, int> pp;
vector<pp>graph[20001];
//int d[20001];
vector<int> d(20001, INF);
priority_queue<pp,vector<pp>,greater<pp>> pq;
int V, E;//V<20001,E<300001
int start;

void dijkstra(int start);
int main(void) {
	cin >> V >> E;
	cin >> start;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}
	dijkstra(start);
	for (int i = 1; i < V+1; i++) {
		cout << d[i] << endl;
	}
}
void dijkstra(int start) {
	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		//cout << cost <<endl;
		if (d[now]<dist) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;//현재까지 비용 + 추가적인 비용
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ cost ,graph[now][i].first });
			}
		}
	}
}