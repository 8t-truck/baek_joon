#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
void dfs(vector<vector<int>> v, int start, int N)
{
	static vector<bool> visited(N + 1);//static���� �����ϸ� ������ �������
	cout << start << ' ';
	visited[start] = true;
	for (int next : v[start])
	{
		if (!visited[next])		//���ѷ����� �۵��ϴµ� �Ź� visited�� ���� �����ؼ� �׷���?
		{
			dfs(v, next, N);
		}
	}
}
void bfs(vector<vector<int>> v, int start, int N)//������� �������� ����
{
	static vector<bool> visited(N + 1);
	queue<int> q;
	q.push(start);	//ť���� ���� ������ ���ڸ� ���� �ִ´�
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		/*for (int i = 0; i < v[node].size(); i++)
		{
			q.push(v[node][i]);
			//���� ������ �����߰ڳ�
			//int toNode = v[node][i];
			//v[toNode].erase(remove(v[toNode].begin(), v[toNode].end(), node), v[toNode].end());
			//����� ȭ��ǥ �����
			
			//������� ���� �� �ƴ϶� ���� ���� �Ȱ��°� ����Ʈ��
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
	for (int i = 0; i < N + 1; i++)		//������ ���� ��ŭ ���� �ƴϾ�?
		sort(graph[i].begin(), graph[i].end());
	
	dfs(graph, V, N);
	cout << '\n';
	bfs(graph, V, N);

	return 0;
}