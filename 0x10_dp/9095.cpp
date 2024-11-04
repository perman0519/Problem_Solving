#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> nv(n, 0);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vector<int> v(a + 1, 0);
		v[1] = 1;
		v[2] = 2;
		v[3] = 4;
		for (int i = 4; i <= a; i++) {
			v[i] = v[i - 3] + v[i - 2] + v[i - 1];
		}
		cout << v[a] << endl;
	}
}
