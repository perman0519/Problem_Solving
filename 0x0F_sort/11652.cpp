#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	long long now = 0;
	int max_t = 0;
	for (int i = 0; i < n; i++) {
		long long tmp = v[i];
		int j = i;
		int cnt = 0;
		while (tmp == v[j] && j < n) {
			cnt++;
			j++;
		}
		i = j - 1;
		if (cnt > max_t) {
			max_t = cnt;
			now = tmp;
		}
	}
	cout << now;
}
