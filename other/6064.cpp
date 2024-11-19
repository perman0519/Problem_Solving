#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if(b==0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	cout.tie(0);
	cin.sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int ret = -1;
		int max_i = lcm(m, n);
		for (int i = x; i <= max_i; i += m) {
			int ny = i % n;
			if (ny == 0)
				ny = n;
			if (ny == y) {
				ret = i;
				break;
			}
		}
		cout << ret << '\n';
	}
	return 0;
}
