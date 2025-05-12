#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	int th;
	string str;
	cin >> th;

	int num = 666, result = 0;
	while (th != result)
	{
		str = to_string(num++);
		if (str.find("666") != -1)
			result++;
	}
	cout << num - 1;
	return 0;
}