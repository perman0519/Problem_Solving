// https://school.programmers.co.kr/learn/courses/30/lessons/42584

#include <stack>
#include <vector>

using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.assign(prices.size(), 0);
    stack<pair<int, int>> st;
    for (int i = 0; i < prices.size(); i++) {
        int n = prices[i];
        if (st.empty() || st.top().second < n)
                st.push({i, n});
        else {
            while (!st.empty() && st.top().second > n) {
                auto p = st.top(); st.pop();
                answer[p.first] = i - p.first;
            }
            st.push({i, n});
        }
    }
    while (!st.empty()) {
        auto p = st.top(); st.pop();
        answer[p.first] = prices.size() - p.first - 1;
    }
    return answer;
}
