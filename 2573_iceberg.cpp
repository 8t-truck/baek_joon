#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
vector<vector<int>> board;

vector<pair<int, int>> ice;
int N, M, Tcnt;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void wonder() {
	int meltMount[301][301] = { 0, };
	set<pair<int, int>> ms;
	vector<pair<int, int>> next_ice;
	for (pair<int, int> tp : ice) {
		for (int i = 0; i < 4; i++) {
			int nr = tp.first + dr[i];
			int nc = tp.second + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
			if (board[nr][nc] == 0) {
				meltMount[tp.first][tp.second]++;
				ms.insert({ tp.first,tp.second });
			}
		}
		if ((board[tp.first][tp.second] - meltMount[tp.first][tp.second]) > 0)
			next_ice.push_back(tp);//0이하의 수들은 ice에 복사가 안됨
	}
	ice = next_ice;//교환이 일어남. 단순 복사가 아님
	for (pair<int, int> tp : ms) {
		if ((board[tp.first][tp.second] - meltMount[tp.first][tp.second]) > 0) {
			board[tp.first][tp.second] -= meltMount[tp.first][tp.second];
		}
		else {
			board[tp.first][tp.second] = 0;
		}
	}

	//
	/*cout << "ice" << endl;
	for (pair<int, int> p : ice) {
		cout << p.first <<' ' << p.second << endl;
	}
	cout << "meltMount:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << meltMount[i][j] << ' ';
		}
		cout << endl;
	}*/
}
bool is_seperated() {
	if (ice.size() == 0)return false;
	int c = 1;
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(N,vector<bool>(M));//resize 해야함
	q.push({ ice[0].first, ice[0].second });
	visited[ice[0].first][ice[0].second] = true;
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nr = q.front().first + dr[i];
			int nc = q.front().second + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
			if (board[nr][nc] != 0 && !visited[nr][nc]) {
				visited[nr][nc] = true;
				q.push({ nr,nc });
				c++;
			}
		}
		q.pop();
	}
	/*cout << "c: " << c << " size: " << ice.size() << endl;*/
	if (c != ice.size()) {
		return true;
	}
	else
		return false;
}
int main(void) {
	string line;
	cin >> N >> M;
	cin.ignore();
	board.resize(N);
	//visited.resize(N, vector<bool>(M));
	for (int i = 0; i < N; i++) {
		getline(cin,line);
		stringstream ss(line);
		int temp;
		int index = 0;
		while (ss >> temp) {
			board[i].push_back(temp);
			if (temp != 0) {
				ice.push_back({ i,index });
			}
			index++;
		}
	}
	while (ice.size() != 0) {
		Tcnt++;
		wonder();
		/*cout << "ice" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/
		if (is_seperated()){
			cout << Tcnt;
			return 0;
		}
	}
	cout << 0;
}