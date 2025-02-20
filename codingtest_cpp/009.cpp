// 10진수를 2진수로 변환하기

#include <iostream>
#include <stack>

using namespace std;

string solution(int decimal) {
	stack<int> st;
	while (decimal) {
		st.push(decimal % 2);
		decimal /= 2;
	}
	string ret = "";
	while (!st.empty()) {
		ret += st.top() + '0';
		st.pop();
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	cout << solution(n) << endl;
	return 0;
}
