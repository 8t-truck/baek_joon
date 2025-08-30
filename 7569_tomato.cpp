#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int M, N, H, maxN=-9999;
vector<vector<vector<int>>> box;
vector<vector<vector<int>>> date;
vector<vector<vector<bool>>> visited;
int dx[6] = {0,1,0,-1,0,0};//»ó
int dy[6] = {0,0,1,0,-1,0};
int dz[6] = {1,0,0,0,0,-1};
queue<pair<int, pair<int, int>>> q;
void bfs(void) {
	while (!q.empty()) {
		int ch = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();
		visited[ch][cx][cy] = true;
		for (int dir = 0; dir < 6; dir++) {
			int nh = ch + dz[dir];
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];
			if (H <= nh || N <= nx || M <= ny || 0 > nh || 0 > nx || 0 > ny)
				continue;
			if (visited[nh][nx][ny])
				continue;
			if (box[nh][nx][ny] == 0) {
				q.push({ nh,{nx,ny} });
				visited[nh][nx][ny] = true;
				date[nh][nx][ny] = min(date[nh][nx][ny], date[ch][cx][cy] + 1);
			}
		}
	}
	
}
int main(void) {
	int unriped = 0;
	cin >> M >> N >> H;
	box.resize(H, vector<vector<int>>(N,vector<int>(M)));
	date.resize(H, vector<vector<int>>(N, vector<int>(M,999999)));
	visited.resize(H, vector<vector<bool>>(N, vector<bool>(M)));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int temp;
				cin >> temp;
				box[i][j][k] = temp;
				if (temp == 1) {
					date[i][j][k] = temp;
					visited[i][j][k] = true;
					q.push({i, { j,k }});
				}
				else if (temp == -1) {
					visited[i][j][k] = true;
					date[i][j][k] = 0;
				}
				if (temp == 0)
					unriped++;
			}
		}
	}
	if (unriped == 0) {
		cout << 0;
		return 0;
	}
	bfs();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (maxN <= date[i][j][k]) {
					maxN = date[i][j][k];
				}
				if (date[i][j][k] == 999999) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << maxN - 1;
	return 0;
}