#include <iostream>
#include <vector>
using namespace std;

vector<int> dp[1001];
int main() {
	int n;
	cin >> n;
	vector<int> v(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i].push_back(v[i]);
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				if (dp[i].size() > dp[j].size() + 1) {
					dp[i] = dp[i];
				}
				else {
					dp[i] = dp[j];
					dp[i].push_back(v[i]);
				}
			}
		}
	}
	vector<int> maxv;
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i].size() > max) {
			max = dp[i].size();
			maxv = dp[i];
		}
	}

	cout<< maxv.size() << '\n';
	for (auto i: maxv)
		cout << i << ' ';
	return 0;
}
