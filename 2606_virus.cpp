#include <iostream>
#include <vector>
using namespace std;
vector<bool> infected;
void dfs(vector<vector<int>>& v, int virus)//����Ž�� �˰���
{
	infected[virus] = true;

	for ( int a : v[virus])
	{
		if (!infected[a])
		{
			dfs(v, a);
		}
	}
}
int main(void)
{
	int computerCount;
	int connectedCount;
	int s, e;

	cin >> computerCount;
	cin >> connectedCount;

	vector<vector<int>> adj(computerCount + 1);
	infected.resize(computerCount + 1, false);
	for (int i = 0; i < connectedCount; i++)//�Է¹޴� �κ�
	{
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);//one-way streets���� two-way streets���� �� Ȯ���ϵ���
	}
	dfs(adj, 1);
	int infectedComputers = 0;
	for (int i = 1; i < infected.size(); i++)
	{
		infectedComputers += infected[i];
		//cout << infected[i] << ' ';
	}
	cout << infectedComputers - 1;
	return 0;
}