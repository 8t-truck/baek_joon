//이 알고리즘은 블루레이의 크기를 이진탐색을 이용해서 정함.
//해당 블루레이의 크기가 너무 작아서 너무 작게 나누어진다면 키우고 ...

//내가 명심할것은 이진탐색은 탐색의 한 방법이라는 점이다.
//bfs dfs 처럼 공식이 아니라 하나의 방법!
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	int M, N, max_elem = -1, total = 0;
	cin >> N >> M;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (max_elem < arr[i])
			max_elem = arr[i];
		total += arr[i];
	}
	int high = total;
	int low = max_elem;//high low는 하나의 범위이다.
	int mid = 0;
	while (low <= high) {
		mid = (high + low) / 2;
		int sub_sum = 0;
		int cnt = 1;
		for (int e : arr) {
			if (sub_sum + e > mid) {
				cnt++;
				sub_sum = e;
			}
			else {
				sub_sum += e;
			}
		}
		if (cnt > M) {
			low = mid + 1;
		}
		else {//정답이 가능한 부분
			high = mid - 1;
		}
	}
	cout << low;
	return 0;
}