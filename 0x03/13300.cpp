#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, k;
	cin >> n >> k;
	int s, y;
	int arr[12];
	fill(arr, arr+12, 0);
	int room = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;
		--y;
		arr[y * 2 + s]++;
		if (arr[y * 2 + s] > k)
			arr[y * 2 + s] = arr[y * 2 + s] - k;
		if (arr[y * 2 + s] == 1)
			room++;
	}
	cout << room;
}
