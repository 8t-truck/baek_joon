#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (true)
	{
		cin >> str;
		if (str == "0")
			break;
		int end = str.size() - 1;

		for (int i = 0;; i++)
		{
			if (str.at(i) != str.at(end - i))//�ϳ��� �ٸ��� Ż��
			{
				cout << "no";
				break;
			}
			else
				continue;
			if (i > end - i)//������ Ż��
			{
				cout << "yes";
				break;
			}
		}
	}
	return 0;
}