#include <iostream>
#include <vector>
using namespace std;

// vector<int> solution(vector<int> lst)
// {
	// 	set<int, greater<int>> s(lst.begin(), lst.end());
	// 	lst = vector<int>(s.begin(), s.end());

	// 	return lst;
	// }

vector<int> solution(vector<int> lst) {
	sort(lst.rbegin(), lst.rend());
	lst.erase(unique(lst.begin(), lst.end()), lst.end());
	return lst;
}

int main() {
	int n;
	cin >> n;
	vector<int> lst(n, 0);
	for (int i = 0; i < n; i++) cin >> lst[i];
	lst = solution(lst);
	for (auto n : lst)
		cout << n << ' ';
	cout << '\n';
	return 0;
}
