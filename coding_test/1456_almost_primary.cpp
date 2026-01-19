#include<iostream>

#include<vector>

#include<cmath>

using namespace std;

int primeSearchSquare(long long b, long long a) {

	long long num = (long long)sqrt(b);

	int count = 0;

	vector<bool> v(num + 1, true);



	for (long long i = 2; i <= num; i++) {

		if (v[i]) {

			if (i > b / i) continue;

			for (long long k = i * i; k <= num; k += i) {

				v[k] = false;

			}

		}

	}

	//primesearch

	for (long long i = 2; i <= num; i++) {

		if (v[i]) {

			//i is prime

			if (i > b / i) break;//이건 i^2만 체크 
			
			long long temp = i;	//10^14 * 10^14인 경우를 체크했어야했음...

			while (temp <= b) {//여기서 i^3...도 체크 필요
				//i를 제곱 count
				temp *= i;

				if (temp >= a) {

					cout << temp << endl;

					count++;

				}


			}

		}

	}

	//cout << count<<' ';

	return count;

}



int main(void) {

	long long A, B;

	cin >> A >> B;

	cout << primeSearchSquare(B, A);

}