#include <bits/stdc++.h>
using namespace std;
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	unsigned long long N, result = 0;
	cin >> N;
	stack<unsigned long long> st1;
	unsigned long long b;
	cin >> b;
	st1.push(b);
	for (size_t i = 0; i < N - 1; i++)
	{
		cin >> b;
		if (st1.top() > b) {
			st1.push(b);
		} else {
				while (!st1.empty() && st1.top() <= b)
					st1.pop();
				st1.push(b);
		}
		result += st1.size() - 1;
	}
	cout << result;
}
