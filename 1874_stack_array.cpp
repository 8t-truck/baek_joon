#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int main(void) { 
	int cnt;
	cin >> cnt;
	vector<int> arr(cnt);
	for (int i = 0; i < cnt; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	stack<int> stk;
	queue<char> q;
	int num = 1;
	for (int i = 0; i < cnt; i++) {
		if (stk.empty()) { 
		stk.push(num++);
		q.push('+');
		}
		if (arr[i] != stk.top()) {
			while (arr[i] != stk.top()) {
				stk.push(num++);
				q.push('+');
				if (stk.size() == cnt) {
					cout << "NO";
					return 0;
				}
			}
			i--;
		}
		else {
			q.push('-');
			stk.pop();
		}
	}
	for (int i = 0; i < cnt * 2; i++) {
		if (!q.empty()) {
			cout << q.front() << '\n';
			q.pop();
		}
		else {
			cout << '-' << '\n';
		}
	}
	return 0;
}