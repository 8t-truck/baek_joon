#include<iostream>
#include<algorithm>
using namespace std;
int main (void) {
	int l;
	cin >> l;
	//int arr[10000][3] = { {0} };//2.4MB
	int arr[3] = { 0 };
	int mDp[2][3] = { {0} };
	int MDp[2][3] = { {0} };
	int temp[3] = {0};
	for (int i = 0; i < l; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		for (int j = 0; j < 3; j++) {
			if(j==0||j==2){
				mDp[1][j] = min(mDp[0][j] + arr[j], mDp[0][1] + arr[j]);
				MDp[1][j] = max(MDp[0][j] + arr[j], MDp[0][1] + arr[j]);
			}
			else {
				mDp[1][j] = min(mDp[0][2]+arr[j], min(mDp[0][0] + arr[j], mDp[0][1] + arr[j]));
				MDp[1][j] = max(MDp[0][2]+arr[j], max(MDp[0][0] + arr[j], MDp[0][1] + arr[j]));
			}
		}
		//cout <<'M' << MDp[1][0] << ' ' << MDp[1][1] << ' ' << MDp[1][2] << endl;
		//cout <<'m' << mDp[1][0] << ' ' << mDp[1][1] << ' ' << mDp[1][2] << endl;
		//슬라이딩 윈도우
		for (int j = 0; j < 3; j++) {
			mDp[0][j] = mDp[1][j];
			MDp[0][j] = MDp[1][j];
		}
	}
	cout << max(MDp[0][0], max(MDp[0][1], MDp[0][2])) <<' ' << min(mDp[0][0], min(mDp[0][1], mDp[0][2]));

	return 0;
}