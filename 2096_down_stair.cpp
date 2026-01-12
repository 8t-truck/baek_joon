#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	int l;
	vector<int> arr1(3);
	vector<int> arr2(3);

	vector<int> max_result(3);
	vector<int> min_result(3);
	cin >> l;
	cin >> arr1[0] >> arr1[1] >> arr1[2];
	max_result[0] = arr1[0]; max_result[1] = arr1[1]; max_result[2] = arr1[2];
	min_result[0] = arr1[0]; min_result[1] = arr1[1]; min_result[2] = arr1[2];
	for (int i = 1; i < l; i++) {
		cin >> arr1[0] >> arr1[1] >> arr1[2];
		arr2[0] = max(arr1[0] + max_result[0], arr1[0] + max_result[1]);
		arr2[1] = max(max(arr1[1] + max_result[0], arr1[1] + max_result[1]), arr1[1]+max_result[2]);
		arr2[2] = max(arr1[2] + max_result[1], arr1[2] + max_result[2]);
		//arr1[0] = arr2[0]; arr1[1] = arr2[1]; arr1[2] = arr2[2];
		max_result[0] = arr2[0]; max_result[1] = arr2[1]; max_result[2] = arr2[2];

		arr2[0] = min(arr1[0] + min_result[0], arr1[0] + min_result[1]);
		arr2[1] = min(min(arr1[1] + min_result[0], arr1[1] + min_result[1]), arr1[1] + min_result[2]);
		arr2[2] = min(arr1[2] + min_result[1], arr1[2] + min_result[2]);
		min_result[0] = arr2[0]; min_result[1] = arr2[1]; min_result[2] = arr2[2];
	}
	cout << max(max(max_result[0], max_result[1]), max_result[2]);
	cout << ' ';
	cout << min(min(min_result[0], min_result[1]), min_result[2]);
	return 0;
}