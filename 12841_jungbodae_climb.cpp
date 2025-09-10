#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	long long n, l = 0, r = 0,index = 0;
	long long min = 10000000000;
	cin >> n;
	vector<long long>left(n);
	vector<long long>right(n);
	vector<long long>bridge(n);
	vector<long long>sum(n);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		bridge[i] = temp;
	}
	for (int i = 1; i < n; i++) {
		int temp;
		cin >> temp;
		l += temp;
		left[i] = l;
	}
	for (int i = 0; i < n -1; i++) {
		int temp;
		cin >> temp;
		right[i] = temp;
	}
	long long rr = 0;
	vector<long long> t(n);
	for (int i = n - 1; i >= 0; i--) {
		r += right[i];
		t[i] = r;
	}
	for (int i = 0; i < n; i++) {
		sum[i] += left[i];
		sum[i] += t[i];
		sum[i] += bridge[i];
		if (sum[i] < min) {
			min = sum[i];
			index = i;
		}
	}
	/*for (long long iter : t) {
		cout << iter << ' ';
	}*/
	cout << index + 1 << ' ' << min;

	return 0;
}