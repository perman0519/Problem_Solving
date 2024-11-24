#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v[501];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			int t;
			cin >> t;
			v[i].push_back(t);
		}
	}
	if (n == 1) {
		cout << v[1][0];
		return 0;
	}
	v[2][0] += v[1][0];
	v[2][1] += v[1][0];
	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (j == 0)
				v[i][j] += v[i - 1][j];
			else if (j == i - 1)
				v[i][j] += v[i - 1][j - 1];
			else
				v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(ret, v[n][i]);
	}
	cout << ret;
	return 0;
}
