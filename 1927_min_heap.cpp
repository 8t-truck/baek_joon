#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�Է� �ޱ� ������ 2^10�� �迭�� ����� �Է¹��� ���� true�� �������� false�� �ϸ� ���?
//0�� �Է� �޴� ��쿡�� sort()�� �����ϴ� ���
//sort()�� �̹� ����ȭ�� �Ǿ��ִ� �Լ��̴ϱ� �ּҸ� ã�� ����� ��������
int main(void)
{
	//�ð��ʰ� ��
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, x;
	vector<int> arr;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0 && arr.size() == 0)
		{
			cout << 0 << '\n';
		}
		else if (x == 0)
		{
			sort(arr.begin(), arr.end());
			cout << arr[0] << '\n';
			arr.erase(arr.begin());
		}
		else
		{
			arr.push_back(x);
		}
	}
	return 0;
}