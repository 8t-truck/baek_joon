//최소 한개의 모음(aeiou), 두개의 자음()
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
모든 조합의 경우를 구하고 자음과 모음의 조건 그리고 길이 조건을 성립한다면 출력...
*/
int L, C;
vector<char>arr;
vector<bool>visited;
string result;
void choice(int index, int dep,int cnsnt,int vwel) {
	if (dep == L&&cnsnt>=1&&vwel>=2) {
		cout << result << '\n';
		return;
	}
	else if(dep==L) {
		return;
	}
	//종료조건
	for (int i = 0; i < C; i++) {
		if(!visited[i] && i>=index)	{
			visited[i] = true;
			result.push_back(arr[i]);
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				choice(i+1, dep + 1, cnsnt + 1, vwel);
			}
			else {
				choice(i+1, dep + 1, cnsnt, vwel + 1);
			}
			result.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {
	cin >> L >> C;
	visited.resize(C);
	for (int i = 0; i < C; i++) {
		char temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	choice(0, 0, 0, 0);
	return 0;
}