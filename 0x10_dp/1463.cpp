#include <iostream>
using namespace std;
int v[10000005];
int main() {
	int n;
	cin >> n;
	v[1] = 0;
	for (int i = 2; i <= n; i++) {
		v[i] = v[i - 1] + 1;
		if (i % 2 == 0)
			v[i] = min(v[i / 2] + 1, v[i]);
		if (i % 3 == 0)
			v[i] = min(v[i / 3] + 1, v[i]);
	}
	cout << v[n];
	return 0;
}
