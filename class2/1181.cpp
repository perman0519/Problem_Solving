#include <iostream>
#include <set>
using namespace std;

struct Compare {
	bool operator() (const string &a, const string &b) const {
		if (a.size() == b.size()) {
			return a < b;
		}
		else
			return a.size() < b.size();
	}
};

int main() {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	// vector<string> v;
	set<string, Compare> sc;
	while (n--) {
		string str;
		cin >> str;
		sc.insert(str);
	}
	// sort(s.begin(), s.end(), cmp);
	for (auto str : sc) {
		cout << str << '\n';
	}
	return 0;
}
