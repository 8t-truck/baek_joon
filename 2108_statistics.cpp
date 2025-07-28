//산술평균
//중앙값
//최빈값(중복시 두번째로 작은값)
//범위(최대최소 차)
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int main(void) {
	int cnt, sum = 0;
	vector<int> v;
	priority_queue<pair<int, int>> pq;//갯수, 값
	//갯수를 더해서 집어넣어햐하는거 아냐????
	map<int, int> m;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int t;
		cin >> t;
		v.push_back(t);
		sum += t;

	}
	sort(v.begin(), v.end());
	for (int i = 0; i < cnt; i++) {
		m[v[i]]++;
	}

	for (map<int, int>::iterator it = m.begin(); it != m.end();it++) {
		pq.push({ it->second, -1*(it->first) });//map의 first는 값
		//cout << pq.top().second;
		//pq.pop();
	}//여기까지 작성함... 우선순위 큐에서 
	pair<int, int> f; pair<int, int> s;
	f = pq.top();
	pq.pop();
	s = pq.top();
	int many;
	if (f.first == s.first) {
		many = -1 * s.second;
	}
	else {
		many = -1 * f.second;
	}

	int avg = round((double)sum / cnt);
	int mid = v[ceil(cnt / 2)];
	int ran = abs(v.front() - v.back());//절댓값

	cout <<  avg << '\n';

	cout <<  mid << '\n';
	cout <<  many << '\n';
	cout << ran << '\n';

	return 0;
}