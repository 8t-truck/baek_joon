#include<iostream>
#include<cmath>
using namespace std;
int ans = 0;
void f(int N, int r, int c) {
	if (N == 0) {
		return;
	}
	int half = pow(2, N - 1) - 1;
	if (r <= half && c <= half) {
		//0
		f(N - 1, r, c);
	}
	else if (r <= half && c > half) {
		//1
		ans += pow(2, 2 * N - 2);
		f(N - 1, r, c - half - 1);
	}
	else if (r > half && c <= half) {
		//2
		ans += pow(2, 2 * N - 2) * 2;
		f(N - 1, r - half - 1, c);
	}
	else {
		//3
		ans += pow(2, 2 * N - 2) * 3;
		f(N - 1, r - half - 1, c - half - 1);
	}
}
int main(void) {
	int N, r, c;
	cin >> N >> r >> c;
	f(N, r, c);
	cout << ans;
	return 0;
}