#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string s1; string s2; string s3;
int arr[101][101][101] = {0,};
int main(void) {
	cin >> s1 >> s2 >> s3;
	for (int i = 0; i < s1.size() + 1; i++) {
		for (int j = 0; j < s2.size() + 1; j++) {
			for (int k = 0; k < s3.size() + 1; k++) {
				cout << arr[i][j][k]<<' ';
				if (i == 0 || j == 0 || k == 0) {
					arr[i][j][k] = 0;
				}
				else if (s1[i -1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
				}
				else {
					arr[i][j][k] = max(arr[i][j][k - 1], max(arr[i - 1][j][k], arr[i][j - 1][k]));
				}
			}
			//cout << endl;
		}
		//cout<<endl;
	}
	for (int i = 0; i < s1.size() + 1; i++) {
		for (int j = 0; j < s2.size() + 1; j++) {
			for (int k = 0; k < s3.size() + 1; k++) {
				cout << arr[i][j][k] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << arr[s1.size()][s2.size()][s3.size()];
	return 0;
}