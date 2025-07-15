#include<iostream>
#include<vector>
using namespace std;
void frontdfs(vector<vector<int>>v, int sNode)
{
	if (sNode + 'A' == '.')
		return;

	if (sNode + 'A' != '.')
		cout << char(sNode + 'A');
	frontdfs(v, v[sNode][0]);
	frontdfs(v, v[sNode][1]);
}
void indfs(vector<vector<int>>v, int sNode)
{
	if (sNode + 'A' == '.')
		return;

	indfs(v, v[sNode][0]);
	if (sNode + 'A' != '.')
		cout << char(sNode + 'A');
	indfs(v, v[sNode][1]);
}
void backdfs(vector<vector<int>>v, int sNode)
{
	if (sNode + 'A' == '.')
		return;

	backdfs(v, v[sNode][0]);
	backdfs(v, v[sNode][1]);
	if (sNode + 'A' != '.')
		cout << char(sNode + 'A');
}
int main(void)
{
	int node;
	cin >> node;
	vector<vector<int>> arr(node);
	char tree, left, right;
	for (int i = 0; i < node; i++)
	{
		cin >> tree >> left >> right;
		arr[tree - 'A'].push_back(left - 'A');
		arr[tree - 'A'].push_back(right - 'A');
	}
	frontdfs(arr, 0);
	cout << '\n';
	indfs(arr, 0);
	cout << '\n';
	backdfs(arr, 0);
	return 0;
}