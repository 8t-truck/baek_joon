#include<iostream>
#include<vector>
#include<string>
using namespace std;
//sort�Լ��� �̿��Ͽ� �����ϴ� �� ���ٴ� 
//1~200������ ����� �迭�� ����� �ش� �迭�� �̸��� ������� ���� �ִ� ���� ���� ��
int main(void)
{
	int count, age;
	string name;
	vector<vector<string>>arr(201);	//����->�̸�����
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> age >> name;
		arr[age - 1].push_back(name);
	}
	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << i + 1 <<' ' << arr[i][j] << endl;
		}
	}
	return 0;
}