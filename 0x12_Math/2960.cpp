#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int count = 0;
	int p = 2;
	vector<bool> ch(1001, false);
	for (int i = 2; i <= n; i++) {
		if (ch[i])
			continue;
		for (int j = i; j <= n; j += i) {
			if (!ch[j]) {
				ch[j] = true;
				count++;
				if (count == k) {
					cout << j << '\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
