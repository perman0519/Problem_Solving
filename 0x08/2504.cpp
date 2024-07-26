#include <bits/stdc++.h>
using namespace std;
int main(void) {
	cout.sync_with_stdio(0);
	// cin.tie(0);
	stack<pair<char, int> > st;
	string str;
	cin >> str;
	int ret = 0;
	bool err = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '[') {
			st.push(make_pair(str[i], 0));
		}
		else {
			if (st.empty()) {
				err = true;
				break;
			}
			if (str[i] == ')') {
				if (st.top().first == '(') {
					int y = 2;
					if (st.top().second != 0)
						y *= st.top().second;
					st.pop();
					if (!st.empty())
						st.top().second += y;
					else
						ret += y;
				}
				else {
					err = true;
					break;
				}
			}
			else  { // ']'
				if (st.top().first == '[') {
					int y = 3;
					if (st.top().second != 0)
						y *= st.top().second;
					st.pop();
					if (!st.empty())
						st.top().second += y;
					else
						ret += y;
				}
				else {
					err = true;
					break;
				}
			}
		}
	}
	if (st.empty() == true && err == false)
		cout << ret << "\n";
	else
		cout << 0 << "\n";
}
