#include <iostream>

using namespace std;
void calculator(int n1, int n2)
{
	int grComDiv = 1;
	int leComMul;
	for(int i = 2;i<=n1&&i<=n2;i++)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			n1 = n1 / i;
			n2 = n2 / i;
			grComDiv = grComDiv * i;
			cout <<"i: " << i << endl;
			cout <<"gC: " << grComDiv << endl;
			i = 1;
		}
	}

	leComMul = grComDiv * n1 * n2;
	cout << grComDiv << endl << leComMul;
}
int main(void)
{
	int n1, n2;
	cin >> n1 >> n2;
	calculator(n1, n2);
	return 0;
}