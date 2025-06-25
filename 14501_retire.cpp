#include <iostream>
using namespace std;
int total,
	t[15] = { 0 }, m[15] = { 0 };
int solve(int day)
{
	if (total <= day)
		return 0;
	int take = 0;
	if (total >= day + t[day])
		take = m[day] + solve(day + t[day]);
	int skip = solve(day + 1);
	return max(take, skip);
}
int main(void)
{
	cin >> total;
	for (int i = 0; i < total; i++)
		cin >> t[i] >> m[i];
	int result = solve(0);
	cout << result;
	return 0;
}