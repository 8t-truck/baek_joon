#include <iostream>
using namespace std;
void fi(int a)
{
	int f[41], z[41], o[41];
	f[0] = 0;
	f[1] = 1;
	z[0] = 1;
	z[1] = 0;
	o[0] = 0;
	o[1] = 1;
	if (a > 1) {
		for (int i = 2; i <= a; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
			z[i] = z[i - 1] + z[i - 2];
			o[i] = o[i - 1] + o[i - 2];
		}
	}
	cout << z[a] << ' ' << o[a]<<'\n';
}
int main(void)
{
	int temp, test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> temp;
		fi(temp);
	}
    return 0;
}