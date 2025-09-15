#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int N, M, cnt = 0;
	cin >> N >> M;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			//14999+14998+...+1연산횟수->15000*14999/2<2억회
			if (arr[i] + arr[j] == M) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}