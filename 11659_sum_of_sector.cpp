#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	int count, test, start, end, sum = 0;
	vector<int> v;
	cin >> count>>test;//count는 입력받는 횟수,test는 test케이스 횟수
	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		v.push_back(sum);
	}//숫자열 입력
	

	//미리 합을 구하고 sum - sum

	for (int i = 0; i < test; i++)
	{
		cin >> start >> end;
		//while (start <= end)
		//{
		//	sum += v[(start++)-1];
		//}//직접 구하기
		if (start - 2 < 0)
			cout << v[end - 1] << "\n";
		else
			cout << v[end - 1] - v[start - 2] << "\n";
	}

	return 0;
}