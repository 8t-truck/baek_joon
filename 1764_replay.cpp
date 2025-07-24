#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(void) {
	int N, M;
	cin >> N >> M;
	set <string> nl;
	set <string> ns;
	set <string> result;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		nl.insert(temp);
	}
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if (nl.find(temp) != nl.end()) {
			result.insert(temp);
		}
	}
	cout << result.size() << '\n';
	for (set<string>::iterator iter = result.begin(); iter != result.end();iter++) {
		cout << *iter << '\n';
	}


	return 0;
}