// https://school.programmers.co.kr/learn/courses/30/lessons/64061

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<stack<int>> sts;
    for (int i = 0; i < board[0].size(); i++) {
        stack<int> st;
        for (int j = board.size() - 1; j >= 0; j--) {
            if (board[j][i] == 0)
                break;
            st.push(board[j][i]);
        }
        sts.push_back(st);
    }
    cout << sts.size() << endl;
    stack<int> bowl;
    for (int i = 0; i < moves.size(); i++) {
        if (sts[moves[i] - 1].empty()) continue;
        if (!bowl.empty() && bowl.top() == sts[moves[i] - 1].top()) {
            sts[moves[i] - 1].pop();
            answer += 2;
            bowl.pop();
        }
        else {
            bowl.push(sts[moves[i] - 1].top());
            sts[moves[i] - 1].pop();
        }
    }
    return answer;
}
