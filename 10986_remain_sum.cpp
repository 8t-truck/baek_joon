#include<iostream>
#include<vector>
using namespace std;
long long rm[1000001];
vector<int> vec;//0ÀÇ °³¼ö
int main(void) {
	long long N, M, zeroCnt = 0, oneCnt = 0, twoCnt = 0,sum = 0;
	cin >> N >> M;
	vec.resize(M);
	long long temp = 0;
	for (int i = 0; i < N; i++) {
		long long t;
		cin >> t;
		temp += t;
		rm[i] = temp % M;
	}
	for (int i = 0; i < N; i++) {
		int index = rm[i];
		vec[index]++;
	}
	sum += vec[0];
	for (auto iter : vec) {
		if (iter>1)
		{
			sum += iter * (iter - 1)/2;
		}
	}
	cout << sum;
	return 0;
}
//1 3 6 7 9
//1 0 0 1 0
//