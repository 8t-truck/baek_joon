#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	
	int test,
		column;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> column;
		vector<int>stk[2];
		int dp1[100000] = { 0, };//[0][0]을 골랐을 때
		int dp2[100000] = { 0, };//[1][0]을 골랐을 때
		//배열 입력받기
		for (int r = 0; r < 2; r++)
			for (int j = 0; j < column; j++)
			{
				int temp;
				cin >> temp;
				stk[r].push_back(temp);
			}
		dp1[0] = stk[0][0];
		dp2[0] = stk[1][0];
		dp1[1] = stk[1][0] + stk[0][1];
		dp2[1] = stk[0][0] + stk[1][1];
		/*cout << "dp1[" << 0 << "]:" << dp1[0] << '\n';
		cout << "dp2[" << 0 << "]:" << dp2[0] << '\n';
		cout << "dp1[" << 1 << "]:" << dp1[1] << '\n';
		cout << "dp2[" << 1 << "]:" << dp2[1] << '\n';*/
	
		for (int j = 2; j < column; j++)
		{
			dp1[j] = max(dp2[j - 2], dp2[j - 1]) + stk[0][j];
			dp2[j] = max(dp1[j - 2], dp1[j - 1]) + stk[1][j];//dp2는 stk[1][]에 해당하는 저장공간
			/*cout << "dp1[" << j << "]:" << dp1[j]<<'\n';
			cout << "dp2[" << j << "]:" << dp2[j]<<'\n';*/
		}
		cout << max(dp1[column - 1], dp2[column - 1])<<'\n';
		stk->clear();
	}
	return 0;
}
/*
dp1[2]:130
dp2[2]:120
dp1[3]:140
dp2[3]:140
dp1[4]:180
dp2[4]:200
*/