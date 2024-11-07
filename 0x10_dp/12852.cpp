#include <iostream>
#include <string>
using namespace std;

int b[1000001];

int main() {
	int n;
	cin >> n;
	b[1] = 0;
	for (int i = 2; i <= n; i++) {
		b[i] = b[i - 1] + 1;
		if (i % 2 == 0)
			b[i] = min(b[i / 2] + 1, b[i]);
		if (i % 3 == 0)
			b[i] = min(b[i / 3] + 1, b[i]);
	}
	cout << b[n] << '\n';
	cout << n << ' ';
	while (n > 1) {
		int next = n - 1;
		if (n % 2 == 0 && b[next] > b[n / 2])
				next = n / 2;
		if (n % 3 == 0 && b[next] > b[n / 3])
				next = n / 3;
		n = next;
		cout << n << ' ';
	}
	return 0;
}
