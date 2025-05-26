#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	long long test, need
		, temp, max = 0;
	vector<long long> arr;
	cin >> test >> need;
	for (long long i = 0; i < test; i++)
	{
		cin >> temp;
		arr.push_back(temp);
		if (max < temp)
			max = temp;
	}

	long long s = 0, e = max+1;
	long long remain = static_cast<long long>(s + e / 2);
	long long sum;
	
	while (s <= e)
	{
		sum = 0;
		for (long long i = 0; i < test; i++)
		{
			if (remain < arr[i])
				sum += arr[i] - remain;
		}
		if (need == sum)
		{
			cout << remain;
			return 0;
		}
		else if (need < sum)
		{
			s = remain;
			if (remain == (s + e) / 2)
			{
				cout << remain;
				return 0;
			}
			remain = static_cast<long long>((s + e) / 2);
		}
		else
		{
			e = remain;
			if (remain == (s + e) / 2)
			{
				cout << remain;
				return 0;
			}
			remain = static_cast<long long>((s + e) / 2);
		}
	}
	
	return 0;
}