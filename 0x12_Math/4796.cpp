#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int l, p, v;
	cin >> l >> p >> v;
	int count = 1;
	long long ret = 0;
	while (l != 0 && p != 0 && v != 0) {
		ret = v / p * l;
		ret += min(v % p, l);
		cout << "Case " << count << ": " << ret << '\n';
		count++;
		cin >> l >> p >> v;
	}

	return 0;
}
