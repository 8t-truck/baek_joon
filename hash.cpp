#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int num;
	string sum;
	string str;
	cin >> num>>str;
	for (int i = 0; i < num; i++)//50�� ¥�� �����
	{
		sum = to_string((str[i]-'a'+1) * pow(31, i));//���⼭ sum���� ���ڸ� ���ѱ�°Ŵϱ� ���ڷ� �Ѱܾ��ҵ�
		cout << sum << endl;
	}
	cout << sum;
	return 0;
}