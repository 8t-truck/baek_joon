#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	int count, test, start, end, sum = 0;
	vector<int> v;
	cin >> count>>test;//count�� �Է¹޴� Ƚ��,test�� test���̽� Ƚ��
	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		v.push_back(sum);
	}//���ڿ� �Է�
	

	//�̸� ���� ���ϰ� sum - sum

	for (int i = 0; i < test; i++)
	{
		cin >> start >> end;
		//while (start <= end)
		//{
		//	sum += v[(start++)-1];
		//}//���� ���ϱ�
		if (start - 2 < 0)
			cout << v[end - 1] << "\n";
		else
			cout << v[end - 1] - v[start - 2] << "\n";
	}

	return 0;
}