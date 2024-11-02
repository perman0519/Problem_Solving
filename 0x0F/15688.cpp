#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v(2000001, 0);
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		v[d + 1000000]++;
	}
	for (int i = 0; i <= 2000000; i++) {
		while (v[i]--)
			cout << i - 1000000 << '\n';
	}
}
