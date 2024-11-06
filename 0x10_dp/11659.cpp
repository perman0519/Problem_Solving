#include <iostream>
using namespace std;

int b[100005];
int sum[100005];
int main() {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		sum[i] = sum[i - 1] + b[i];
	}
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << '\n';
	}
	return 0;
}


// 시간초과
// int main() {
// 	int n, m;
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		cin >> bn[i];
// 	}
// 	for (int i = 0; i < m; i++) {
// 		int s, e;
// 		cin >> s >> e;
// 		int sum = 0;
// 		for (int j = s - 1; j <= e - 1; j++) {
// 			sum += bn[j];
// 		}
// 		cout << sum << endl;
// 	}

// 	return 0;
// }
