#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(void) {
	long long N, K, sum = 0;
	int cnt = 0;
	vector<long long>sumV;
	map<long long, int>map;//<°ª,°¹¼ö>
	cin >> N >> K;
	map.insert({ 0,1 });
	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		sum += temp;
		if (map.find(sum - K) != map.end()) {
			cnt += map[sum - K];
			cout << map[sum - K]<<endl;
		}
		map[sum]++;
	}

	cout << cnt;

	return 0;
}