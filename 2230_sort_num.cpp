#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	long long  N, M, sub = 0,mNum = 1e11;
	long long s = 0, e = 0;
	vector<long long>arr;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	while (s <= e && e < N) {
		if (e == s) {
			e++;
		}
		if (arr[e] - arr[s] < M) {
			e++;
		}
		else if (arr[e] - arr[s] == M) {
			cout << M;
			return 0;
		}
		else {
			sub = arr[e] - arr[s];
			if (sub <= mNum) {
				mNum = sub;
			}
			s++;
		}
	}
	cout << mNum;
	return 0;
}