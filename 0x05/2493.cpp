#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	cout.sync_with_stdio(0);
	int n;
	cin >> n;
	pair<int, int> node;
	stack<pair<int, int>> st1;
	vector<int> vec(n);
	int k = 0;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		st1.push(pair<int, int>(i, k));
	}
	stack<pair<int, int>> st2;
	int max = st1.top().second;
	int index = st1.top().first;
	while (!st1.empty())
	{
		if (st2.empty() || st1.top().second <= st2.top().second) {
			pair<int, int> pa = st1.top();
			st1.pop();
			st2.push(pa);
		} else {
			while (st2.empty() == false && st1.top().second > st2.top().second) {
				vec[st2.top().first - 1] = st1.top().first;
				st2.pop();
			}
			pair<int, int> pa = st1.top();
			st1.pop();
			st2.push(pa);
		}
	}
	for(int c : vec) {
		cout << c << " ";
	}
}
