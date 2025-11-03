#include<iostream>
#include<vector>
using namespace std;
int N, K, cnt;
vector<int> arr;
vector<bool>visited;
int result[8] = { 500,0, };
void p(int k) {
	if (result[k]<500) {
		return;
	}
	if (N == k) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			/*result[k] += arr[i] - K;	*///result에는 증가 값과 증감 값이 합쳐져서 저장됨
			result[k + 1] = result[k] + arr[i] - K;
			p(k + 1);
			visited[i] = false;
		}
	}
}
int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	visited.resize(N);
	p(0);
	cout << cnt;
	return 0;
}