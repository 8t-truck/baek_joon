#include<iostream>
using namespace std;
int main(void) {
	int n;
	int peo[11] = { 0 };
	int arr[11] = { 0 };
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		int t;
		cin >> t;
		peo[i] = t;
	}
	for (int i = 1; i < n + 1; i++) {
		int num = 0;
		for (int j = 1; j < n + 1; j++) {
			if (arr[j] == 0) {
				num++;
			}
			if (arr[j] != 0)
				continue;
			if (num == peo[i] + 1) {
				arr[j] = i;
			}
		}
	}
	for (int i = 1; i < n + 1;i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}