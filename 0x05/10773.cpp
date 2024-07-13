#include <bits/stdc++.h>
using namespace std;
int main() {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	int n;
	list<int> li;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		if (n == 0 && li.size() != 0)
			li.pop_front();
		else
			li.push_front(n);
	}
	int result = 0;
	for (int c : li) {
		result += c;
	}
	cout << result;
}
