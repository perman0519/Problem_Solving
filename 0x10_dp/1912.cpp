#include <iostream>
using namespace std;

int b[100001];

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	b[1] = v[1];
	int ret = b[1];
	for (int i = 1; i <= n; i++) {
		b[i] = max(b[i - 1] + v[i], v[i]);
		ret = max(ret, b[i]);
	}
	cout << ret;
	return 0;
}
