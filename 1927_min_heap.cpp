#include<iostream>
#include<queue>
using namespace std;
//입력 받기 전부터 2^10의 배열을 만들고 입력받은 값을 true로 나머지를 false로 하면 어떨까?
//0을 입력 받는 경우에만 sort()를 적용하는 경우
//sort()는 이미 최적화가 되어있는 함수이니까 최소를 찾는 방법에 집중하자
int main(void)
{
	//시간초과 뜸
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int>>q;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 0 && q.size() == 0)
			cout << 0 << '\n';
		else if (x == 0)
		{
			cout << q.top() << '\n';
			q.pop();
		}
		else
		{
			q.push(x);
		}

	}
	return 0;
}