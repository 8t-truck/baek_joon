#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str[3];
	int next = 0;

	cin >> str[0];
	cin >> str[1];
	cin >> str[2];
	for (int i = 2; i >= 0; i--)
	{
		if (atoi(str[i].c_str()) != 0)
		{
			next = atoi(str[i].c_str()) + (3 - i);
			break;
		}

	}
	if (next % 3 == 0 && next % 5 != 0) { cout << "Fizz"; }
	else if (next % 5 == 0 && next % 3 != 0) { cout << "Buzz"; }
	else if (next % 5 == 0 && next % 3 == 0) { cout << "FizzBuzz"; }
	else { cout << next; }
	return 0;
}