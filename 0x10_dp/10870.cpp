#include <iostream>
using namespace std;

long long b[10001];
int main() {
	b[0] = 0;
	b[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		b[i] = (b[i - 1] + b[i - 2]) % 1000000;
	}
	int n;
	cin >> n;
	cout << b[n];
	return 0;
}
