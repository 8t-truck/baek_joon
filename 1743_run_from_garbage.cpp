#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};
bool board[101][101];
bool visited[101][101];
queue<pair<int, int>> q;
int r, c, k;
int result = 1;
void bfs(int row, int col) {
	if (visited[row][col]) return;
	int temCnt = 1;
	queue<pair<int, int>> bfsQ;
	bfsQ.push({ row,col });
	visited[row][col] = true;
	while (!bfsQ.empty()) {
		pair<int, int> pp = bfsQ.front(); bfsQ.pop();
		for (int i = 0; i < 4; i++) {
			int nextR = pp.first + dr[i];
			int nextC = pp.second + dc[i];
			if (nextR < 0 || nextR >= r || nextC < 0 || nextC >= c) continue;
			if (!visited[nextR][nextC]&&board[nextR][nextC]) {
				visited[nextR][nextC] = true;
				bfsQ.push({ nextR,nextC });
				temCnt++;
			}
		}
	}
	if (result <= temCnt) {
		result = temCnt;
	}
}
int main(void) {
	cin >> r >> c >> k;
	for (int i = 0; i < k; i++) {
		int tr, tc;
		cin >> tr >> tc;
		board[tr][tc] = true;
		q.push({ tr - 1,tc - 1 });
	}
	while (!q.empty()) {
		pair<int, int> pair = q.front();
		bfs(pair.first, pair.second);
		q.pop();
	}
	cout << result;
	return 0;
}