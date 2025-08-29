#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int M, N, maxN = -99999;
vector<vector<int>> box;
vector<vector<int>> date;
vector<vector<bool>> visited;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
void bfs(void) {//vector subscript error랑 visited를 초기화...
	/*vector<vector<bool>>tempVisited(visited.begin(), visited.end());*/
	//복사 시간이 오래걸릴듯
	//queue에 집어넣는 순서가 문제를 만드나?
	queue<pair<int,int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 1) {
				q.push({ j,i });
			}
		}
	}
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];
			if (nx<0 || ny<0 || nx>=M || ny>=N)
				continue;
			if (visited[ny][nx])
				continue;
			if (box[ny][nx] == 0) {
				visited[ny][nx] = true;
				q.push({ nx,ny });
				date[ny][nx] = min(date[cy][cx] + 1, date[ny][nx]);
				//최단기간
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int unripeAppleCnt = 0;
	cin >> M >> N;
	box.resize(N, vector<int>(M));
	date.resize(N, vector<int>(M,999999));
	visited.resize(N, vector<bool>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int t;
			cin >> t;
			box[i][j] = t;
			if (t == 0) {
				unripeAppleCnt++;
			}
			if (t == 1) {
				date[i][j] = t;
			}
			if (t == -1) {
				visited[i][j] = true;//토마토 없으면 미리 방문표시
				date[i][j] = -1;
			}
		}
	}
	if (unripeAppleCnt == 0) {
		cout << 0;
		return 0;
	}
	bfs();
	
	for (int i = 0; i < N; i++) {//확인용
		for (auto iter : date[i]) {
			if (iter == 999999) {
				cout << -1;
				return 0;
			}
			if (iter > maxN)
				maxN = iter;
		}
	}
	cout << maxN - 1;
	return 0;
}