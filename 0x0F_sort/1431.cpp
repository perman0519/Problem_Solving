#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const string &a, const string &b) {
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() > b.length()) {
		return false;
	}
	else {
		int ai = 0, bi = 0;
		for (int i = 0; i < a.size(); i++) {
			if (isdigit(a[i]))
				ai +=  a[i] - '0';
		}
		for (int i = 0; i < b.size(); i++) {
			if (isdigit(b[i]))
				bi +=  b[i] - '0';
		}
		if (ai < bi) {
			return true;
		}
		else if (ai > bi) return false;
		else {
			return a < b;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	for (auto &c : v) cout << c << endl;
}
