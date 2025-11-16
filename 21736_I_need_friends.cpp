#include<iostream>
#include<queue>
using namespace std;
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };
char board[601][601] = { NULL, };
bool visited[601][601] = { false, };
int N, M, meet_people;
void bfs(int sr,int sc) {
	queue< pair<int, int>> q;
	q.push({ sr,sc });
	visited[sr][sc] = true;
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nr = q.front().first + dr[i];
			int nc = q.front().second + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
			if (board[nr][nc] == 'O' && !visited[nr][nc]) {

				board[nr][nc] == 'L';

				visited[nr][nc] = true;
				q.push({ nr,nc });
			}
			else if (board[nr][nc] == 'P' && !visited[nr][nc]) {

				board[nr][nc] == 'S';

				visited[nr][nc] = true;
				meet_people++;
				q.push({ nr,nc });
			}
		}
		q.pop();
	}
}
int main(void) {
	int sr = 0; int sc = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'I') {
				sr = i; sc = j;
			}
		}
	}
	bfs(sr, sc);
	if (meet_people == 0)
		cout << "TT";
	else
		cout << meet_people;
	return 0;
}
