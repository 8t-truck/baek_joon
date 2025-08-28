#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;
int main(void) {
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {//test case
		deque<int> dq;
		string p, arr;
		cin >> p >> n >> arr;
		int DCount = count(p.begin(), p.end(), 'D');
		if (DCount > n) {
			cout << "error" << '\n';
			continue;
		}
		//D�� ũ�Ⱑ arr�� ���̺��� �۴ٸ�...
		//arr���� ���ڸ� �����ؾ���
		string temp;
	/*	for (int j = 1; j < arr.length(); j++) {
			if (arr[j] == ','|| arr[j] == ']') {
				dq.push_back(stoi(temp));
				temp = "";
			}
			else {
				temp += arr[j];
			}
		}*/
		for (int j = 1; j < arr.length(); j++) {
			if (arr[j] == '0' || arr[j] == '1' || arr[j] == '2' || arr[j] == '3' || arr[j] == '4' || arr[j] == '5' || arr[j] == '6' || arr[j] == '7' || arr[j] == '8' || arr[j] == '9') {
				temp += arr[j];
			}
			else if( temp != "" ) {
				dq.push_back(stoi(temp));
				temp = "";
			}
		}
		for (auto i : dq) {
			cout << i << ' ';
		}
		//p���� ���ӵ� R�� ������ �տ��� ������ �ڿ��� ������ ���ϱ�
		int rCount = 0;
		for (int c = 0; c < p.length(); c++) {
			if (p[c] == 'R') {
				rCount++;
			}
			else if (rCount % 2 == 0 && p[c] == 'D') {
				//cout << "����� ��: " << dq.front() << endl;
				dq.pop_front();
			}
			else if (rCount % 2 != 0 && p[c] == 'D'){
				/*cout << "����� ��: " << dq.back() << endl;*/
				dq.pop_back();
			}
		}
		int dqSize = dq.size();
		cout << '[';
		if (rCount % 2 == 0 && dq.size() != 0) {
			for (int j = 0; j < dqSize - 1;j++) {
				cout << dq.front() << ',';
				dq.pop_front();
			}
			cout << dq.front();
			dq.pop_front();
		}
		else if (rCount % 2 != 0 && dq.size() != 0) {
			for (int j = 0; j < dqSize - 1; j++) {
				cout << dq.back() << ',';
				dq.pop_back();
			}
			cout << dq.back();
			dq.pop_back();
		}
		cout << ']' << '\n';
		/*cout << "���:"  << '[';*/
	}
	return 0;
}