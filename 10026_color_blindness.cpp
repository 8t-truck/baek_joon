//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//vector<vector<char>> arr;
//vector<vector<bool>> rVisited;
//vector<vector<bool>> CBVisited;
//int N, realSector, colorBlindSector;
//int di[4] = { -1,0,1,0 };
//int dj[4] = { 0,1,0,-1 };
//void realBfs(int i, int j) {
//	if (rVisited[i][j])
//		return;
//	queue<pair<int, int>>q;
//	q.push({ i,j });
//	rVisited[i][j] = true;
//	while (!q.empty()) {
//		int ci = q.front().first;
//		int cj = q.front().second;
//		q.pop();
//		for (int dir = 0; dir < 4; dir++) {
//			int ni = ci + di[dir];
//			int nj = cj + dj[dir];
//			if (ni < 0 || nj < 0 || ni >= N || nj >= N)
//				continue;
//			if (rVisited[ni][nj])
//				continue;
//			if (arr[ni][nj] != arr[ci][cj])
//				continue;//정상인... 색맹을 어떻게 처리하지
//			rVisited[ni][nj] = true;
//			q.push({ ni,nj });
//		}
//	}
//	realSector++;
//	return;
//}
//void CBBfs(int i, int j) {
//	if (CBVisited[i][j])
//		return;
//	queue<pair<int, int>>CBq;
//	CBq.push({ i,j });
//	CBVisited[i][j] = true;
//	while (!CBq.empty()) {
//		int ci = CBq.front().first;
//		int cj = CBq.front().second;
//		CBq.pop();
//		for (int dir = 0; dir < 4; dir++) {
//			int ni = ci + di[dir];
//			int nj = cj + dj[dir];
//			if (ni < 0 || nj < 0 || ni >= N || nj >= N)
//				continue;
//			if (CBVisited[ni][nj])
//				continue;
//			if ((arr[ni][nj] == 'B' && arr[ci][cj] != 'B')|| arr[ni][nj] != 'B' && arr[ci][cj] == 'B')
//				continue;//정상인... 색맹을 어떻게 처리하지
//			CBVisited[ni][nj] = true;
//			CBq.push({ ni,nj });
//		}
//	}
//	colorBlindSector++;
//	return;
//}
//int main(void) {
//	cin >> N;
//	arr.resize(N, vector<char>(N));
//	rVisited.resize(N, vector<bool>(N));
//	CBVisited.resize(N, vector<bool>(N));
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			char temp;
//			cin >> temp;
//			arr[i][j] = temp;
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			//cout << i << j;
//			realBfs(i, j);
//			CBBfs(i, j);
//		}
//	}
//	cout << realSector << ' ' << colorBlindSector;
//	return 0;
//}