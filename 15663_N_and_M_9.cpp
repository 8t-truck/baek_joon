#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int N, M;
vector<int>v;
vector<int> r;
vector<bool>visited;
vector<vector<int>> bs;
void dfs(int st,int cd, int depth){
	if (cd == depth) {
		bs.push_back(r);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if(!visited[i])
		{
			r.push_back(v[i]);
			visited[i] = true;
			dfs(i, cd + 1, depth);
			r.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	visited.resize(N);
	sort(v.begin(), v.end());
	dfs(0, 0, M);
	set<vector<int>> s(bs.begin(), bs.end());
	for (auto iter : s) {
		for (auto i : iter) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}