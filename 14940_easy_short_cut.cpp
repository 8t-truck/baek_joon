#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<vector<int>> depth;//출력, -1로 초기화
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
void bfs(int x,int y){
	queue<pair<int, int>> q;
	int nodeX = x;
	int nodeY = y;
	q.push({ x,y });
	visited[x][y] = true;
	depth[x][y] = 0;
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nextX = node.first + dx[dir];
			int nextY = node.second + dy[dir];

			if (nextX<0 || nextX>n - 1 || nextY<0 || nextY>m - 1)
				continue;
			if (map[nextX][nextY] == 0) {
				continue;
			}
			if (visited[nextX][nextY] == true)
				continue;
			q.push({ nextX, nextY });
			visited[nextX][nextY] = true;
			depth[nextX][nextY] = depth[node.first][node.second] + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << depth[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main(void) {
	int sn, sm;
	cin >> n >> m;
	map.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m, false));
	depth.resize(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			if (temp == 2) {
				sn = i; sm = j;
			}
			if (temp == 0) {
				depth[i][j] = 0;
			}
			map[i][j] = temp;
		}
	}
	bfs(sn, sm);
	return 0;
}