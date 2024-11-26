#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cout.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> dp(n, 1);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
	return 0;
}
