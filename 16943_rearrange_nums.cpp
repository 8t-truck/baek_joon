#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
string A;
int B;
vector<bool> visited;
string result;
priority_queue<int> q;
void p(int cur) {
	if(cur==A.length()){
		if (B <= stoi(result)) {
			return;
		}
		else{
			q.push(stoi(result));//작으면 넣기
			return;
		}
	}
	for (int i = 0; i < A.length(); i++) {
		if (!visited[i]&&!(cur==0&&A[i]=='0')) {//방문하지 않고 0번 인덱스에 0을 넣지 않는다.
			visited[i] = true;
			result.push_back(A[i]);
			p(cur+1);
			visited[i] = false;
			result.pop_back();
		}
	}
}
int main(void) {
	cin >> A >> B;
	visited.resize(A.length());
	p(0);
	q.push(-1);
	cout << q.top();
	return 0;
}