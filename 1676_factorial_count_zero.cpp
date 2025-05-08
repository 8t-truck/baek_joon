#include<iostream>
#include<string>
using namespace std;
static int twoCount = 0, fiveCount = 0;

void countZero(int n)
{
	if (n == 0)
		return;
	for (int i = n; i > 0; i--)
	{
		if (i % 2 == 0)
		{
			int t = i;
			while (t % 2== 0)
			{
				twoCount++;
				t = t / 2;
			}
		}
		if (i % 5 == 0)
		{
			int t = i;
			while(t % 5 == 0)
			{
				fiveCount++;
				t = t / 5;
			}
		}
	
	}
}

int main(void)
{
	int input, num = 0, last = 0, zeroCount = 0;
	cin >> input;
	countZero(input);
	if (twoCount <= fiveCount)
		cout << twoCount;
	else
		cout << fiveCount;
	return 0;
}