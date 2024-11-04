#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	v[1] = 0;
	for (int i = 2; i <= n; i++) {
		v[i] = v[i - 1] + 1;
		if (i % 2 == 0)
			v[i] = min(v[i / 2] + 1, v[i]);
		if (i % 3 == 0)
			v[i] = min(v[i / 3] + 1, v[i]);
	}
	cout << v[n];

}
