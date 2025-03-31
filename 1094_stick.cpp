#include <iostream>
using namespace std;
int main(void)
{
	int x, stick = 64, count=0;
	cin >> x;
	while (x!=0)
	{
	
		if (x < stick)
			stick = stick / 2;
		else
		{
			x -= stick;
			count++;
			//23-16-4-2-1
		}

		
	}
	cout << count;
}
// 8	1 0 0
// 16	1 0 0 0
// 18	1 0 1 0