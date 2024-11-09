#include <iostream>
using namespace std;

long long dp[101][21];
int num[101];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	dp[0][num[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		int now = num[i];
		for (int j = 0; j <= 20; j++) {
			if (j + now <= 20) {
				dp[i][j + now] += dp[i - 1][j];
			}
			if (j - now >= 0) {
				dp[i][j - now] += dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 2][num[n - 1]];
	return 0;
}
