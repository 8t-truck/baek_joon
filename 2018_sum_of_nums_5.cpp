#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int N, cnt = 0,sum = 1;
	int s = 1, e = 2;
	cin >> N;
	//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	//---------
	//      -----
	//            ---
	//     
	//                s
	//                    e

	while (s <= e&&e<=N+1) {
		if (sum == N) {
			cnt++;
			sum += e;
			e++;
		}
		else if (sum < N) {
			sum += e;
			e++;
		}
		else {
			sum -= s;
			s++;
		}
	}
	cout << cnt;
	return 0;
}