#include <iostream>
using namespace std;

string b[51];
int main() {
	cin.tie(0);
	cout.sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		b[i] = str;
	}
	int ret = 0;
	int before = b[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (before == b[i][j]) {
				ret++;
			}
			before = b[i][j];
		}
	}
	cout << ret;
}
