#include<iostream>
#include<vector>
#include<string>
using namespace std;
//sort함수를 이용하여 정렬하는 것 보다는 
//1~200까지의 수들로 배열을 만들고 해당 배열에 이름을 순서대로 집어 넣는 것이 빠를 듯
int main(void)
{
	int count, age;
	string name;
	vector<vector<string>>arr(201);	//나이->이름벡터
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