#include <iostream>
using namespace std;

long long b[91];
int main() {
	b[0] = 0;
	b[1] = 1;
	for (int i = 2; i <= 90; i++) {
		b[i] = b[i - 1] + b[i - 2];
	}
	int n;
	cin >> n;
	cout << b[n];
	return 0;
}
