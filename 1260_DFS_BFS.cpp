#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
void dfs(vector<vector<int>> v, int start, int N)
{
	static vector<bool> visited(N + 1);//static으로 선언하면 문제가 사라지네
	cout << start << ' ';
	visited[start] = true;
	for (int next : v[start])
	{
		if (!visited[next])		//무한루프가 작동하는데 매번 visited를 새로 선언해서 그런가?
		{
			dfs(v, next, N);
		}
	}
}
void bfs(vector<vector<int>> v, int start, int N)//양방향을 적용하지 못함
{
	static vector<bool> visited(N + 1);
	queue<int> q;
	q.push(start);	//큐에는 내가 참조할 숫자를 집어 넣는다
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		/*for (int i = 0; i < v[node].size(); i++)
		{
			q.push(v[node][i]);
			//오는 방향을 지워야겠네
			//int toNode = v[node][i];
			//v[toNode].erase(remove(v[toNode].begin(), v[toNode].end(), node), v[toNode].end());
			//양방향 화살표 지우기
			
			//양방향을 지울 게 아니라 갔던 곳을 안가는게 포인트네
		}*/
		cout << node << ' ';
		visited[node] = true;
		for (int next : v[node])
		{
			if (visited[next] == false)
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
	cout << endl;
}
int main()
{
	int N, M, V;
	cin >> N >> M >> V;
	vector<vector<int>>graph(N + 1);	//graph[0] = { 0 }
	for (int i = 0; i < M; i++)
	{
		int l, r;
		cin >> l >> r;
		graph[l].push_back(r);
		graph[r].push_back(l);
	}
	for (int i = 0; i < N + 1; i++)		//정점의 개수 만큼 정렬 아니야?
		sort(graph[i].begin(), graph[i].end());
	
	dfs(graph, V, N);
	cout << '\n';
	bfs(graph, V, N);

	return 0;
}