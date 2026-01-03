#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
string str; string pre; string suf;
vector<int> PrePi, SufPi;

set<string> ss;
vector<int> KMP_Init(string s) {
	vector<int> Pi(s.size(),0);
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j])	j = Pi[j - 1];
		if (s[i] == s[j])	Pi[i] = ++j;
	}
	return Pi;
}
vector<int> PreKMP(string s, vector<int> Pi) {
	vector<int> v;
	int j = 0;
	for (int i = 0; i < str.size(); i++) {
		while (j > 0 && str[i] != s[j])j = Pi[j - 1];
		if (str[i] != s[j]) continue;
		if (j == s.size() - 1) {
			v.push_back(i - s.size() + 1);
			j = Pi[j];
			continue;
		}
		j++;
	}
	return v;
}
vector<int> SufKMP(string s, vector<int> Pi) {
	vector<int> v;
	int j = 0;
	for (int i = 0; i < str.size(); i++) {
		while (j > 0 && str[i] != s[j])j = Pi[j - 1];
		if (str[i] != s[j]) continue;
		if (j == s.size() - 1) {
			v.push_back(i);
				j = Pi[j];
			continue;
		}
		j++;
	}
	return v;
}
int main(void) {
	cin >> str >> pre >> suf;
	PrePi = KMP_Init(pre);
	SufPi = KMP_Init(suf);
	vector<int> stIndex = PreKMP(pre, PrePi);
	vector<int> laIndex = SufKMP(suf, SufPi);
	
	for (auto st : stIndex) {
		for (auto la : laIndex) {
			if (la - st + 1 >= (int)pre.size() && la - st + 1 >= (int)suf.size()) {
				ss.insert(str.substr(st, la - st + 1));
			}
		}
	}
	cout << ss.size();
	return 0;
}