#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// N (1 ≤ N ≤ 1,000,000)
// Ai (1 ≤ Ai ≤ 1,000,000)

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> dp;
	for (int i = 1; i <= n; i++) {
		auto it = lower_bound(dp.begin(), dp.end(), a[i]);
		if (it == dp.end()) {
			dp.push_back(a[i]);
		}
		else {
			*it = a[i];
		}
	}
	cout <<  dp.size();
	return 0;
}
