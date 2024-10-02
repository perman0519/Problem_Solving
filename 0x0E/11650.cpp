#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > vec;
	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec.push_back({n1, n2});
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	}
}
