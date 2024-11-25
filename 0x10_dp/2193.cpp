#include <iostream>
using namespace std;

long long b[91];
int main() {
	cout.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	b[0] = 0;
	b[1] = 1;
	b[2] = 1;
	b[3] = 2;
	b[4] = 3; // 1000 1001 1010
	b[5] = 5; // 10000 10001 10010 10100 10101
	// b[6] = 5; // 100000 100001 100010 100100 100101 101000 101001 101010
	if (n > 5) {
		for (int i = 6; i <= n; i++)
			b[i] = b[i - 1] + b[i - 2];
	}
	cout << b[n];
}
