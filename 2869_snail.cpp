#include <iostream>
#include <cmath>  

using namespace std;

int main() {
    int up, down, height;
    cin >> up >> down >> height;

    int lenPerDay = up - down; // �Ϸ� �̵� �Ÿ�
    int day;

    if (up >= height) {  // ù�� �ٷ� �����ϴ� ���
        day = 1;
    }
    else {
        day = ceil((double)(height - up) / lenPerDay) + 1;
    }

    cout << day;
    return 0;
}
