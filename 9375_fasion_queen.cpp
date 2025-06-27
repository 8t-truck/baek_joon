#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;

	for(int i =0;i<test;i++)
	{
		int allcases = 1;//출력되는 모든 경우의 수
		int clothes;	//옷의 개수
		cin >> clothes;	//옷의 종류에 index를 부여하기 위함
		map<string, int> match;
		vector<string> ctype;
		for(int ii=0; ii<clothes;ii++)
		{
			string type, name;
			cin >> name >> type;
			if (match.find(type) != match.end())
				match[type]++;
			else
			{
				match[type] = 1;
				ctype.push_back(type);
			}
		}
		//2^n-1방식
		for (int ii = 0; ii < match.size(); ii++)
			allcases *= match[ctype[ii]] + 1;
		cout << allcases - 1;

		//next_permutation
		//for (int iii = 1; iii <= match.size(); iii++)	//옷 종류의 개수
		//	//한개부터 다 뽑는 경우의 수
		//{
		//	vector<bool> v(match.size() - iii, 0); //vector를 0으로 얼마만큼 선언을 한다				에러발생***********
		//	v.insert(v.end(), iii, 1);	//vector를 end부터 iii까지 1로 채운다
		//	//cout << iii << "개를 뽑는 경우";
		//	do
		//	{
		//		vector<int>temp;
		//		int multemp = 1;
		//		for (int iv = 0; iv < match.size(); iv++)
		//		{
		//			if (v[iv])
		//				temp.push_back(match[ctype[iv]]);//선택된 종류, temp에 옷의 개수가 들어간다
		//			else
		//				temp.push_back(1);//선택되지 못한 종류에는 1이 들어간다
		//			multemp *= temp[iv];
		//		}
		//		//cout << multemp;
		//		/*for (int v = 0; v < temp.size(); v++)
		//			cout << temp[v] << ' ';*/
		//		//cout << '\n';
		//		allcases += multemp;
		//	} while (next_permutation(v.begin(), v.end()));
		//}
		//cout << allcases << '\n';
	}
	return 0;
}
