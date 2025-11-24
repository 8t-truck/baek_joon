#include<iostream>
#include<queue>
using namespace std;
int N;//N<=100000
int result;
int main(void) {
	cin >> N;
	priority_queue<int>q;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		q.push(temp * -1);
	}
	while (q.size() != 1) {
		int sum = 0;
		sum = q.top(); q.pop();
		sum += q.top();
		q.pop();
		q.push(sum);
		result += sum*-1;
	}
	cout << result;
	return 0;
}
/*
-10
-20
sum = -30
r = 30
-30
-40
sum = -70
r = 100
*/