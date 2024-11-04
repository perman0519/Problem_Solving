#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if (n <= 2) {
		cout << sum;
		return 0;
	}
	vector<int> d(n, 0);
	d[0] = v[0];
	d[1] = v[1];
	d[2] = v[2];
	for (int i = 3; i < n; i++) {
		d[i] = min(d[i - 2], d[i - 3]) + v[i];
	}
	cout << sum - min(d[n - 2], d[n - 3]);
	return 0;
}
// int main() {
// 	int n;
// 	cin >> n;
// 	vector<int> v(n, 0);
// 	for (int i = 0; i < n; i++) cin >> v[i];
// 	vector<vector<int> > d(n, vector(3, 0));
// 	if (n == 1) {
// 		cout << v[0];
// 		return 0;
// 	}
// 	else if (n == 2) {
// 		cout << v[0] + v[1];
// 		return 0;
// 	}
// 	d[0][1] = v[0];
// 	d[0][2] = v[0];
// 	d[1][1] = v[1];
// 	d[1][2] = v[0] + v[1];
// 	for (int i = 2; i < n; i++) {
// 		d[i][1] = max(d[i - 2][2], d[i - 2][1]) + v[i];
// 		d[i][2] = d[i - 1][1] + v[i];
// 	}

// 	cout << max(d[n - 1][1], d[n-1][2]);
// }
