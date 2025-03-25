#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int num;
	long long sum;
	string str;
	cin >> num>>str;
	for (int i = 0; i < num; i++)//50점 짜리 답안지,i가 8만 넘어도 long long에 저장이 안됨
	{
		sum += (str[i]-'a'+1) * pow(31, i);//여기서 sum으로 숫자를 못넘기는거니까 문자로 넘겨야할듯
	}
	cout << sum;
	return 0;
}
