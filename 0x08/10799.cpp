#include <bits/stdc++.h>
using namespace std;
int main(void) {
	cout.sync_with_stdio(0);
	// cin.tie(0);
	string str;
	cin >> str;
	stack<int> st;
	int ret = 0;
	int stick = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') {
			if (str[i + 1] == ')')
				st.push(str[i]);
			else
				stick++;
		}
		else {
			if (st.empty() == false) {
				st.pop();
				ret += stick;
			}
			else {
				ret++;
				stick--;
			}
		}
	}
	cout << ret << '\n';
}
