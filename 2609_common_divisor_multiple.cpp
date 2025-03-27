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
			i = 1;//i = 2라고 하면 반복문 돌면서 i++때문에 i = 3 으로 시작함;;
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
