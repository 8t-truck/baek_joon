#include<iostream>
#include<vector>
#include<map>
using namespace std;
int N;
vector<int>arr;
//0은+,1은-,2는*,3은/
vector<int> oper;
vector<int>tempSet;
vector<bool>visited;
vector<vector<int>> set;
void makeSet(int cd) {
	if (cd == oper.size()) {
		set.push_back(tempSet);
		return;
	}
	for (int i = 0; i < oper.size(); i++) {
		if (!visited[i]) {
			tempSet.push_back(oper[i]);
			visited[i] = true;
			makeSet(cd + 1);
			tempSet.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	visited.resize(N);
	for (int i = 0; i < 4; i++) {
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			oper.push_back(i);
		}
	}//oper에 연산자의 경우의 수를 집어넣을거임
	makeSet(0);
	/*for (auto iter : set) {
		for (auto i : iter) {
			cout << i << ' ';
		}
	}*/
	vector<int> allCnt;
	int max = -1000000000, min = 1000000000;
	for (int i = 0; i < set.size(); i++) {
		int all = arr[0];
		for (int j = 0; j < set[i].size(); j++) {
			if (set[i][j] == 0) {
				all += arr[j + 1];
			}
			else if (set[i][j] == 1) {
				all -= arr[j + 1];
			}
			else if (set[i][j] == 2) {
				all *= arr[j + 1];
			}
			else if (set[i][j] == 3) {
				all /= arr[j + 1];
			}
		}
		if (max < all) {
			max = all;
		}
		if (min > all) {
			min = all;
		}
		//cout << max << '\n' << min;
	}
	cout << max << '\n' << min;
	return 0;
}