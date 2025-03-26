#include <iostream>
using namespace std;
int main(void)
{
	int count;
	float arr[100],max=0,sum=0;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> arr[i];//float로 입력을 받을 거야
		if (arr[i] > max) max = arr[i];
	}
	for (int j = 0; j < count; j++)
	{
		sum += arr[j] / max * 100;
	}
	cout << sum / count;

}