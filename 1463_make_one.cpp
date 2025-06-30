#include<iostream>
#include <algorithm>
using namespace std;
//dynamic programming
//Top-Down recursion method
/*
* int cc(int x)
{
	if (x == 1)
		return 0;
	int thrcnt = 100000, twocnt = 10000, min1cnt = 100000;
	//exit condition
	if (x % 3 == 0)
	{
		thrcnt = cc(x / 3) + 1;
	}
	if (x % 2 == 0)
	{
		twocnt = cc(x / 2) + 1;
	}
	if (x > 1)
	{
		min1cnt = cc(x - 1) + 1;
	}
	
	return min({ thrcnt, twocnt, min1cnt });
} //연산량이 너무 많아지는 문제
*/

/*
int cc(int x)
{
	int cnt = 0;
	while (x != 1)
	{
		
		if (x % 3 == 0)
		{
			x /= 3;
			cnt++;
			continue;
		}
		if (x % 2 == 0)
		{
			x /= 2;
			cnt++;
			continue;
		}
		else
		{
			x--;
			cnt++;
			continue;
		}
	}
	return cnt;
}
*/
//x만을 찾으려고 하지 않아도 괜찮다. 모든 경우의 수를 차근차근 저장하며 진행
int dp[1000001] = {0,0,1,1};
int DP(int x)
{
	for (int i = 3; i <= x; i++)
	{
		//2로도 3으로도 안나눠떨어지는 경우를 생각해서 미리 저장해놓음
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i / 3]+1, dp[i]);
		//top-down안에서도 bottom-up이 있을 수 있고 반대도 가능
		if (i % 2 == 0)
			dp[i] = min(dp[i / 2]+1, dp[i]);
	}
	return dp[x];
}

int main(void)
{
	int x;
	cin >> x;
	cout<<DP(x);
	return 0;
}