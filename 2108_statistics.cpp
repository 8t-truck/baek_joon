//������
//�߾Ӱ�
//�ֺ�(�ߺ��� �ι�°�� ������)
//����(�ִ��ּ� ��)
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int main(void) {
	int cnt, sum = 0;
	vector<int> v;
	priority_queue<pair<int, int>> pq;//����, ��
	//������ ���ؼ� ����־����ϴ°� �Ƴ�????
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
		pq.push({ it->second, -1*(it->first) });//map�� first�� ��
		//cout << pq.top().second;
		//pq.pop();
	}//������� �ۼ���... �켱���� ť���� 
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
	int ran = abs(v.front() - v.back());//����

	cout <<  avg << '\n';

	cout <<  mid << '\n';
	cout <<  many << '\n';
	cout << ran << '\n';

	return 0;
}