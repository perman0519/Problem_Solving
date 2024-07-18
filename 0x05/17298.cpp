#include <bits/stdc++.h>
using namespace std;
// 오큰수
int main() {
	cout.sync_with_stdio(0);
	stack<pair<int, int>> st;
	int N;
	cin >> N;
	vector<int> vec(N, -1);
	int q;
	for (int i = 0; i < N; i++) {
		cin >> q;
		if (!st.empty() && q > st.top().second) {
			while (!st.empty() && q > st.top().second) {
				vec[st.top().first] = q;
				st.pop();
			}
		}
		st.push(make_pair(i, q));
	}
	for (int c : vec) {
		cout << c << " ";
	}
}
