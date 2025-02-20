//괄호 짝 맞추기
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
	bool ret;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			st.push('(');
		else {
			if (st.empty())
				return false;
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	string str;
	cin >> str;
	cout << solution(str) << endl;
}
