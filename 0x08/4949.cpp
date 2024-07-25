#include <bits/stdc++.h>
using namespace std;

int main(void) { //균형잡힌 세상
	cout.sync_with_stdio(0);
	string str = "";
	while (str != ".") {
		stack<int> st;
		bool err = false;
		getline(cin, str, '\n');
		for (auto it = str.begin(); it != str.end(); it++)
		{
			if (*it == '(' or *it == '[') {
				st.push(*it);
			} else if (*it == ')' or *it == ']') {
				if (!st.empty() && *it == ')' && st.top() == '(') {
					st.pop();
				}
				else if (!st.empty() && *it == ']' && st.top() == '[') {
					st.pop();
				}
				else {
					cout << "no\n";
					err = true;
					break;
				}
			}
		}
		if (err == false && str != ".") {
			if (!st.empty())
				cout << "no\n";
			else
				cout << "yes\n";
		}
	}
}
