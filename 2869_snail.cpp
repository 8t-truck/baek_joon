#include <iostream>
#include <cmath>  

using namespace std;

int main() {
    int up, down, height;
    cin >> up >> down >> height;

    int lenPerDay = up - down; // 하루 이동 거리
    int day;

    if (up >= height) {  // 첫날 바로 도착하는 경우
        day = 1;
    }
    else {
        day = ceil((double)(height - up) / lenPerDay) + 1;
    }

    cout << day;
    return 0;
}
