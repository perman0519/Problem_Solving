#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	multimap<int, string>s;
	for (int i = 0; i < n; i++) {
		int num;
		string str;
		cin >> num >> str;
		s.insert(make_pair(num, str));
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << it->first << ' ' << it->second << '\n';
	}
}
