#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> p;
vector<string>arr;
vector<vector<bool>> visited;
vector<vector<int>> depth;
int N, M,cnt=0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void bfs() {
	int x = 0, y = 0;
	queue<p> q;
	q.push({ x,y });
	visited[0][0] = true;
	while (!q.empty()) {
		p node = q.front();
		q.pop();
		//cout << node.first << node.second;
		for (int i = 0; i < 4; i++) {	//4방향 순회
			int nextX = node.first;
			int nextY = node.second;
			nextX += dx[i];
			nextY += dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
				continue;
			}
			if (arr[nextX][nextY] == '0') {
				continue;
			}
			if (visited[nextX][nextY] == 1) {
				continue;
			}

			//방문할수있다면 여기로 옴
			q.push({ nextX,nextY });
			visited[nextX][nextY] = true;
			depth[nextX][nextY] = depth[node.first][node.second] + 1;
		}
	}
	cout << depth[N - 1][M - 1] + 1;

}
int main(void) {
	cin >> N >> M;
	arr.resize(N);
	visited.resize(N, vector<bool>(M));
	depth.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	bfs();
	return 0;
}