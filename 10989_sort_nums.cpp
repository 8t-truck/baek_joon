#include<iostream>
#include<vector>
using namespace std;
void QuickSort(vector<int> &arr, int s, int e)
{
	if (s >= e)
		return;
	int p = s;
	int i = s + 1, j = e, temp;
	
	while (i <= j)//index value�� �����Ǳ� ������
	{
		while (i <= e && (arr[i] <= arr[p]))//�ǹ����� ���� ������ ������ ����
			i++;
		while (j > s && (arr[j] >= arr[p]))//�ǹ����� ū ������ �������� ����
			j--;
		if (i > j)//���� �ߴٸ�...
		{
			temp = arr[j];
			arr[j] = arr[p];
			arr[p] = temp;//�ǹ����� j���� �ٲ��ش�
		}
		else//�������� �ʾҴٸ�..>�ǹ����� �����ʿ��� ũ�ų� ���ʿ��� ���� ���� �ִ� 
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;//i�� j�� �������ش�
		}
	}
	QuickSort(arr, s, j - 1);
	QuickSort(arr, j + 1, e);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <int> arr;
	int total,temp;
	cin >> total;
	for (int i = 0; i < total; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	QuickSort(arr,0,total-1);

	for (int i = 0; i < total; i++)
	{
		cout << arr[i] << '\n';
	}
	return 0;
}