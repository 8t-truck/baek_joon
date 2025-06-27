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
		int allcases = 1;//��µǴ� ��� ����� ��
		int clothes;	//���� ����
		cin >> clothes;	//���� ������ index�� �ο��ϱ� ����
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
		//2^n-1���
		for (int ii = 0; ii < match.size(); ii++)
			allcases *= match[ctype[ii]] + 1;
		cout << allcases - 1;

		//next_permutation
		//for (int iii = 1; iii <= match.size(); iii++)	//�� ������ ����
		//	//�Ѱ����� �� �̴� ����� ��
		//{
		//	vector<bool> v(match.size() - iii, 0); //vector�� 0���� �󸶸�ŭ ������ �Ѵ�				�����߻�***********
		//	v.insert(v.end(), iii, 1);	//vector�� end���� iii���� 1�� ä���
		//	//cout << iii << "���� �̴� ���";
		//	do
		//	{
		//		vector<int>temp;
		//		int multemp = 1;
		//		for (int iv = 0; iv < match.size(); iv++)
		//		{
		//			if (v[iv])
		//				temp.push_back(match[ctype[iv]]);//���õ� ����, temp�� ���� ������ ����
		//			else
		//				temp.push_back(1);//���õ��� ���� �������� 1�� ����
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
