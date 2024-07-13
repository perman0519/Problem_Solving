#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	int arr[10];
	fill(arr, arr + 10, 0);
	int max = 0;
	for (char a : str) {
		if (a - '0' == 6 || a - '0' == 9) {
			arr[6]++;
			int t;
			if(arr[6] % 2 == 0)
				t = arr[6] / 2;
			else
				t = arr[6] / 2 + 1;
			if (t > max)
				max = t;
		}
		else {
			arr[a - '0']++;
			if(arr[a - '0'] > max)
				max = arr[a - '0'];
		}
	}
	cout << max;
}
