#include <iostream>
#include <vector>
using namespace std;

int dp[1500002];
int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > v = vector<pair<int,int>>(n + 1, {0, 0});
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] < dp[i - 1])
			dp[i] = dp[i - 1];
		if (i + v[i].first <= n + 1) {
			dp [i + v[i].first] = max(dp[i + v[i].first], dp[i] + v[i].second);
			ret = max(ret, dp[i + v[i].first]);
		}
		// for (int i = 1; i <= n + 1; i++) {
		// 	cout << dp[i] << ' ';
		// }
		// cout << "\n=====================================\n";
	}
	cout << ret << '\n';
	return 0;
}
