#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(void) {
	int N, M, cnt = 0;
	cin >> N >> M;
	map<int,int> map;//������ȣ,����
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		map[temp]++;
	}
	for (auto iter : map) {
		auto point = map.find(M - iter.first);
		if (point != map.end()) {//������ȣ�� �ڿ���
			if(M/2 != iter.first){
				cnt += min(map[M - iter.first], map[iter.first]);
				map.erase(M - iter.first);
			}
			else {
				cnt += (int)(map[iter.first] / 2);
			}
		}
	}
	cout << cnt;
	return 0;
}