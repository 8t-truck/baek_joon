#include <iostream>
using namespace std;
int factorial(int num)
{
	if (num <= 1)
		return 1;
	return num * factorial(num - 1);
}
int combination(int n, int r)//n!/r!*(n-r)!
{
	return factorial(n) / (factorial(r) * factorial(n - r));
}
int main(void)
{
	int n, r;
	cin >> n >> r;
	cout<<combination(n, r);
}