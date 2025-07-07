#include <iostream>
using namespace std;
//bfs를 사용하여 풀기
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a, b, cnt = 1;
	cin >> a >> b;
	while (a<b)
	{
		if (b % 2 == 0)
		{
			b /= 2;
			cnt++;
		}
		else if (b % 10 == 1)
		{
			b /= 10;
			cnt++;
		}
		else
			break;
	}
	if (a == b)
		cout << cnt;
	else
		cout << -1;
	return 0;
}