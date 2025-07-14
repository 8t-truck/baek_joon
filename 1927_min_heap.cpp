#include<iostream>
#include<queue>
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
	priority_queue<int, vector<int>, greater<int>>q;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 0 && q.size() == 0)
			cout << 0 << '\n';
		else if (x == 0)
		{
			cout << q.top() << '\n';
			q.pop();
		}
		else
		{
			q.push(x);
		}

	}
	return 0;
}