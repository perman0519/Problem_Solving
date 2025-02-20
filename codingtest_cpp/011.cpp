// https://school.programmers.co.kr/learn/courses/30/lessons/12973

#include <stack>
#include <string>

using namespace std;

int solution(string s)
{
    stack<char> st;

    for (auto n : s) {
        if (st.empty() || st.top() != n)
            st.push(n);
        else
            st.pop();
        // if (!st.empty()) {
        //     if (st.top() == n) {
        //         st.pop();
        //     }
        //     else {
        //         st.push(n);
        //     }
        // }
        // else
        //     st.push(n);
    }
    return st.empty();
}
