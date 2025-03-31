#include <iostream>

using namespace std;

int main(void)
{
	/*
	1	8
	1	7	28	84	
	1	6	21	56	126	252
	1	5	15	35	70	126	210
	1	4	10	20	35	56	84
	1	3	6	10	15	21	28	
	1	2	3	4	5	6	7	8
	arr[i][j] += arr[i-1][1~j];
	*/
	int count, row, col, arr[15][15] = { {1} };
	for (int i = 0; i < 14; i++)
	{
		arr[0][i] = i + 1;
	}
	for (int j = 1; j < 15; j++)//행
	{
		for (int k = 0; k < 15; k++)//열
		{
			for (int u = 0; u <= k; u++)//반복합
			{
				arr[j][k] += arr[j - 1][u];
			}
			
		}
		
	}
	/*for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	
	//input
	cin >> count;
	for (int h = 0; h < count; h++)
	{
		cin >> row >> col;
		cout << arr[row][col-1]<<endl;
	}
	return 0;
}//잠시 대기