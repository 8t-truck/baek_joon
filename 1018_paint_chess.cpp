#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;

    cin >> n;
    cin >> m;

    vector<string> chess(n);

    for (int i = 0; i < n; i++) {
        cin >> chess[i];
    }

    int min = 32;

    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            int stw = 0;
            int stb = 0;
            for (int l = i; l < i + 8; l++) {
                for (int k = j; k < j + 8; k++) {
                    //시작이 검정
                    //0,2,4,6 이 b
                    //1,3,5,7이 w
                    if ((k - j + l - i) % 2 == 0) {//짝수일때
                        if (chess[l][k] == 'w') {
                            stb++;
                        }
                        if (chess[l][k] == 'b') {
                            stw++;
                        }
                    }
                    else {
                        if (chess[l][k] == 'w') {
                            stw++;
                        }
                        if (chess[l][k] == 'b') {
                            stb++;
                        }
                    }
                }
            }
            if (min > stw) {
                min = stw;
            }
            if (min > stb) {
                min = stb;
            }
        }
    }
    cout << min;

}