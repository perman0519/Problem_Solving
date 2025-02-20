// https://school.programmers.co.kr/learn/courses/30/lessons/76502
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        string ns = s;
        for (int j = 0; j < i; j++) {
            char tmp = ns[0];
			ns.erase(ns.begin());
			ns += tmp;
        }
        // cout << ns << endl;
        stack<char> st;
        bool ch = true;
        for (int j = 0; j < ns.size(); j++) {
            if (ns[j] == '(' || ns[j] == '{' || ns[j] == '[') {
                st.push(ns[j]);
            }
            else {
                if (st.empty()) {
                    ch = false;
                    break;
                }
                if (ns[j] == ')') {
                    if (st.top() != '(') {
                        ch = false;
                        break;
                    }
                }
                if (ns[j] == '}') {
                    if (st.top() != '{')  {
                        ch = false;
                        break;
                    }
                }
                if (ns[j] == ']') {
                    if (st.top() != '[')  {
                        ch = false;
                        break;
                    }
                }
                st.pop();
            }
        }
        if (ch && st.empty()) {
            answer++;
            cout << ns << endl;
        }
    }
    return answer;
}

int main() {
    cout << solution("][") << endl;
}
