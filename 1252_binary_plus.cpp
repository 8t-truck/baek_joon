#include<iostream>
#include<string>
using namespace std;
int main(void) {
	int arr1[81] = { 0 };
	int arr2[81] = { 0 };
	int result[82] = { 0 };
	int c = 0;
	string str1,str2;
	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++) {
		arr1[80 - i] = str1[str1.size() - 1 - i] - '0';
	}
	for (int i = 0; i < str2.size(); i++) {
		arr2[80 - i] = str2[str2.size() - 1 - i] - '0';
	}
	for (int i = 80; i >= 0; i--) {
		int temp = arr1[i] + arr2[i] + c;
		if (temp == 0) {
			result[i + 1] = 0;
			c = 0;
		}
		else if (temp == 1) {
			result[i + 1] = 1;
			c = 0;
		}
		else if (temp == 2) {
			result[i + 1] = 0;
			c = 1;
		}
		else if (temp == 3) {
			result[i + 1] = 1;
			c = 1;
		}
	}
	result[0] = c;
	bool afterOne = false;
	for (int i = 0; i < 82; i++) {
		if (result[i] == 1)
			afterOne = true;
		if (afterOne) {
			cout << result[i];
		}
	}
	if (!afterOne)
		cout << 0;
	return 0;
}