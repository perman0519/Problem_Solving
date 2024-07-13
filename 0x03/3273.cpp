#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int t;
	cin >> t;
	int res[t];
	fill(res, res+t, 0);
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if((t - arr[i]) >= 0) {
			if (res[t - arr[i]] == 1)
				ret++;
			res[arr[i]] = 1;
		}
	}
	cout << ret;
}
