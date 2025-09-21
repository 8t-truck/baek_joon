#include<iostream>
#include<string>
using namespace std;
int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string string;
		cin >> string;
		bool leftPassNoPalin = false;
		bool rightPassNoPalin = false;
		int s = 0, e = string.length() - 1, result = 0;
		while (s < e) {
			if (string[s] != string[e]) {
				result++;
				int passLeft = s + 1, tempEnd = e;
				int passRight = e - 1, tempStart = s;
				while (passLeft < tempEnd) {
					if (string[passLeft] != string[tempEnd]) {
						leftPassNoPalin = true;
						break;
					}
					passLeft++;
					tempEnd--;
				}
				while (tempStart<passRight) {
					if (string[tempStart] != string[passRight]) {
						rightPassNoPalin = true;
						break;
					}
					passRight--;
					tempStart++;
				}
				break;
			}
			s++;
			e--;
		}
		if (leftPassNoPalin && rightPassNoPalin)
			result++;
		cout << result << '\n';
	}

	return 0;
}