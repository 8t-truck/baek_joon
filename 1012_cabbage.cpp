#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int sx, int sy, vector<vector<bool>> &g, vector<vector<bool>> &v) {
	queue<int> row;
	queue<int> col;
	row.push(sx);
	col.push(sy);
	v[sx][sy] = true;
	while (!row.empty() && !col.empty()) {
		int cx = row.front();
		int cy = col.front();
		row.pop();
		col.pop();
		////////////for문이 필요 없겠는데?
		if (cx+1<g.size()&&g[cx + 1][cy] == true && v[cx + 1][cy] == false) {
			row.push(cx + 1);
			col.push(cy);
			v[cx + 1][cy] = true;
		}
		if (cy+1<g[0].size()&&g[cx][cy+1] == true && v[cx][cy+1] == false) {
			row.push(cx);
			col.push(cy+1);
			v[cx][cy+1] = true;
		}
		if (cy - 1 >= 0 && g[cx][cy - 1] == true && v[cx][cy - 1] == false) {
			row.push(cx);
			col.push(cy - 1);
			v[cx][cy - 1] = true;
		}//왼
		if (cx-1 >= 0 && g[cx - 1][cy] == true && v[cx - 1][cy] == false) {
			row.push(cx - 1);
			col.push(cy);
			v[cx - 1][cy] = true;
		}//위
		
	}
}
int main(void) {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int r, c, cnt;
		int comp = 0;
		cin >> r >> c >> cnt;
		vector<vector<bool>> g(r, vector<bool>(c));
		vector<vector<bool>> v(r, vector<bool>(c));
		for (int ii = 0; ii < cnt; ii++) {
			int x, y;
			cin >> x >> y;
			g[x][y] = true;
		}
		//여기서 문제
		for (int x = 0; x < r; x++) {
			for (int y = 0; y < c; y++) {
				if (g[x][y] == true && v[x][y] != true) {
					bfs(x, y, g, v);
					comp++;
				}
			}
		}
		cout << comp<<'\n';
	}

	return 0;
}
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1, 1};  // 좌우
int dy[4] = {-1, 1, 0, 0};  // 상하

void bfs(int startX, int startY, vector<vector<int>>& field, vector<vector<bool>>& visited, int M, int N) {
	queue<pair<int, int>> q;
	q.push({startX, startY});
	visited[startY][startX] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (field[ny][nx] == 1 && !visited[ny][nx]) {
					visited[ny][nx] = true;
					q.push({nx, ny});
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int M, N, K;
		cin >> M >> N >> K;

		vector<vector<int>> field(N, vector<int>(M, 0));
		vector<vector<bool>> visited(N, vector<bool>(M, false));

		for (int i = 0; i < K; ++i) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		int count = 0;

		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				if (field[y][x] == 1 && !visited[y][x]) {
					bfs(x, y, field, visited, M, N);
					count++;
				}
			}
		}

		cout << count << '\n';
	}

	return 0;
}
*/