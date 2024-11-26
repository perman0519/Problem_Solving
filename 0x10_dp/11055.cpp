#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> dp(n, 0);
	for(int i = 0; i < n; i++) {
		dp[i] = v[i];
		for(int j = 0; j < i; j++) {
			if(v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + v[i]);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
	return 0;
}
