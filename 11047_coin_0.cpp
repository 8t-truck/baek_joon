#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int cnt, money, coinCount = 0;
	vector<int> v;
	cin >> cnt >> money;
	for (int i = 0; i < cnt; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	while (money > 0) {
		for (int i = cnt - 1; i >= 0; i--) {
			if (money >= v[i]) {
				coinCount += int(money / v[i]);
				money -= v[i] * int(money / v[i]);
				break;
			}
		}
	}
	
	cout << coinCount;
	return 0;
}