#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int max, start,target;
	cin >> max >> start;
	vector<int> arr;
	vector<int> p; 
	for (int i = 1; i <= max; i++){ arr.push_back(i); }
	target = start - 1;
	
	while(max>0)
	{
		p.push_back(arr[target]);
		arr.erase(arr.begin() + target);
		max--;
		
		target += start - 1;
		if (target > max-1)
		{
			do
			{
				target = target - max;
				if (max == 0)
					break;
			} while (target > max-1);
		}//반복이 아닌 %를 이용하여 풀 수 있음!
	}
	cout << "<";
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i];
		if (i == p.size() - 1)
			continue;
		else
			cout << ", ";

	}
	cout << ">";


	return 0;
}
//B11866