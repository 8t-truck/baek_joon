#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pp;
int N, M;
vector<pp> graph[1001];
vector<int>d(1001, 1e9);
vector<int>result(1001);
void dstra(int start) {
	priority_queue<pp,vector<pp>,greater<pp>> pq;
	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty()) {
		int w = pq.top().first;//cost from right back
		int now = pq.top().second;
		pq.pop();

		if (w > d[now]) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = w + graph[now][i].second;//지금까지 비용 + now에서 i로 가는 비용
			if (cost < d[graph[now][i].first]) {
				//cout << now << " -> " << graph[now][i].first<<endl;
				result[graph[now][i].first] = now;
				d[graph[now][i].first] = cost;
				pq.push({ cost, graph[now][i].first });
			}
		}
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
		graph[B].push_back({ A,C });
	}
	dstra(1);
	/*for (int i = 1; i < N + 1; i++) {
		cout << d[i] << ' ';
	}
	cout << endl;*/
	/*for (int i = 1; i < N + 1; i++) {
		cout << result[i] << ' ';
	}*/
	cout << N - 1 << '\n';
	for (int i = 2; i < N + 1; i++) {
		cout << i << ' ' << result[i] << '\n';
	}
}