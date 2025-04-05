#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
//void quickSort_normal(vector<int>& v, int s, int e) {
//	if (s >= e) return;
//
//	int pivot = v[(s + e) / 2];
//	int i = s, j = e;
//	while (i <= j) {
//		while (v[i] < pivot) ++i;
//		while (v[j] > pivot) --j;
//		if (i <= j) {
//			swap(v[i], v[j]);
//			++i; --j;
//		}
//	};
//	quickSort_normal(v, s, j);  quickSort_normal(v, i, e);
//}
void quickSort_simple_random(vector<int>& v, int s, int e) {
	if (s >= e) return;

	int p = s + rand() % (e - s + 1); //[s,e] 사이 난수          
	swap(v[p], v[e]);
	p = s;
	for (int i = s; i < e; ++i) if (v[i] <= v[e]) swap(v[p++], v[i]);

	swap(v[p], v[e]);
	quickSort_simple_random(v, s, p - 1); quickSort_simple_random(v, p + 1, e);
}
int main(void)
{
	int count;
	int temp;
	vector<int> arr;
	srand(time(NULL));
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	quickSort_simple_random(arr, 0, arr.size() - 1);
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}