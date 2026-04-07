#include <bits/stdc++.h>
using namespace std;

int t = 250001;
int main(void) {
	int n;
	vector<bool> ch(t, true);
	ch[0] = false;
	ch[1] = false;
	cin >> n;
	int n2 = 2 * n;
	for (int i = 2; i * i <= t; i++) {
		if (!ch[i])
			continue;
		for (int j = i + i; j <= t; j += i) {
			ch[j] = false;
		}
	}
	while (n != 0) {
		int count = 0;
		n2 = 2 * n;
		for (int i = n + 1; i <= n2; i++) {
			if (ch[i])
			count++;
		}
		cout << count << '\n';
		cin >> n;
	}
	return 0;
}
