//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//int N, cnt;
//bool visited[16][16];
//int dr[9] = { 0,-1,-1,0,1,1,1,0,-1 };
//int dc[9] = { 0,0,1,1,1,0,-1,-1,-1 };
//void dfs(int r,int c) {
//	if (r == N ) {
//		cnt++;
//		return;
//	}
//	queue<pair<int, int>> q;//정연이는 이걸 접근할수 없는 곳을 저장하는 용도로 썻는데 나는 생각 못할것 같으니까 for문 반복으로 해볼게
//
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < N; j++) {
//			int nr = r + dr[i] * j;
//			int nc = c + dc[i] * j;
//			if (nr < 0 || nr >= N || nc < 0 || nc >= N)break;
//			if (visited[nr][nc])continue;
//			visited[nr][nc] = true;
//			q.push({ nr,nc });
//		}
//	}
//
//	//for (int i = r; i < N; i++) {//이건 조합이 아니라 순열임
//	//	for (int j = 0; j < N; j++) {
//	//		if (!visited[i][j]) {
//	//			dfs(i + 1, j);
//	//		}
//	//	}
//	//}
//	for (int i = 0; i < N; i++) {
//		if (!visited[i][c])
//			dfs(i + 1, c);
//	}
//
//
//	while (!q.empty()) {
//		int nr = q.front().first;
//		int nc = q.front().second;
//		q.pop();
//		visited[nr][nc] = false;
//	}
//
//}
//int main(void) {
//	cin >> N;
//	dfs(0,0);
//	cout << cnt;
//	return 0;
//}