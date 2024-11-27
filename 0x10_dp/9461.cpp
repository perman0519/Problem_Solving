#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	long long b[101];
	b[1] = 1;
	b[2] = 1;
	b[3] = 1;
	b[4] = 2;
	b[5] = 2;
	b[6] = 3;
	b[7] = 4;
	b[8] = 5;
	b[9] = 7;
	b[10] = 9;
	b[11] = 12;
	b[12] = 16;
	b[13] = 21;
	for (int i = 14; i <= 100; i++) {
		b[i] = b[i-2] + b[i-3];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << b[n] << '\n';
	}
	return 0;
}
