#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	vector<pair<int, int> > v(41, {0, 0});
	v[0].first = 1;
	v[1].second = 1;
	for (int i = 2; i <= 40; i++) {
		v[i].first = v[i - 1].first + v[i - 2].first;
		v[i].second = v[i - 1].second + v[i - 2].second;
	}
	while (t--) {
		int n;
		cin >> n;
		cout << v[n].first << ' ' << v[n].second << '\n';
	}
	return 0;
}
