#include <iostream>
using namespace std;

int d[2002];

int main() {
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;
	if (n > 3) {
		for (int i = 4; i <= n; i++) d[i] =
			(d[i - 1] + d[i - 2]) % 10007;
	}
	cout << d[n];
	return 0;
}
