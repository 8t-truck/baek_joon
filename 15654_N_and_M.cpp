#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
vector<int> perm;
vector<bool> visited;
void bt(int depth, int oc) {

	if (depth == oc) {
		for (int num : perm)cout << num << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			perm.push_back(arr[i]);

			bt(depth + 1, oc);
			
			visited[i] = false;
			perm.pop_back();
		}
	}
}

int main (void) {
	int inputCnt, outputCnt;
	cin >> inputCnt >> outputCnt;
	for (int i = 0; i < inputCnt; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	visited.resize(arr.size(),false);
	sort(arr.begin(), arr.end());
	bt(0, outputCnt);
	return 0;
}