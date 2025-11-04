#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> arr;
vector<bool> visited;
int N, M;
vector<int> result;
void par(int cur) {
	if (cur == M) {
		for (int j = 0; j < result.size(); j++) {
			cout << result[j] << ' ';
		}
		cout << '\n';
		return;
	}
	//종료조건
	for (int i = 0; i < N; i++) {
		result.push_back(arr[i + 1]);
		par(cur + 1);
		result.pop_back();
	}
}
int main(void) {
	cin >> N >> M;
	arr.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 1; i < N + 1; i++) {arr[i] = i;}
	par(0);
	return 0;
}