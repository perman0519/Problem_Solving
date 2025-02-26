// https://school.programmers.co.kr/learn/courses/30/lessons/81303
#include <string>
#include <vector>
#include <stack>
using namespace std;

// n 처음 표의 행의 개수를 나타내는 정수
// 처음에 선택된 행의 위치를 나타내는 정수 k
// 수행한 명령어들이 담긴 문자열 배열 cmd
stack<int> st;


void up(vector<int>& upper, vector<int>& downner, int& k, string& str) {
    int count = stoi(str.substr(2));
    for (int i = 0; i < count; i++)
        k = upper[k];
}

void down(vector<int>& upper, vector<int>& downner, int& k, string& str) {
    int count = stoi(str.substr(2));
    for (int i = 0; i < count; i++)
        k = downner[k];
}

void remove(vector<int>& upper, vector<int>& downner, int& n, int& k, string& str) {
    st.push(k);
    downner[upper[k]] = downner[k];
    upper[downner[k]] = upper[k];
    if (downner[k] == n + 1) {
        k = upper[k];
    }
    else
        k = downner[k];
}

void undo(vector<int>& upper, vector<int>& downner, int& k, string& str) {
    auto p = st.top();
    downner[upper[p]] = p;
    upper[downner[p]] = p;
    st.pop();
}

string solution(int n, int k, vector<string> cmd) {
    vector<int> upper(n + 2, 0);
    vector<int> downner(n + 2, 0);
    string answer(n, 'O');
    for (int i = 0; i < n + 2; i++) {
		upper[i] = i - 1;
		downner[i] = i + 1;
    }
    k++;
    for (auto str : cmd) {
        int command = 0;
        int count = -1;
        switch (str[0]) {
            case 'U':
                up(upper, downner, k, str);
                break;
            case 'D':
                down(upper, downner, k, str);
                break;
            case 'C':
                remove(upper, downner, n, k, str);
                break;
            case 'Z':
                undo(upper, downner, k, str);
                break;
        }
    }
    while (!st.empty()) {
        answer[st.top() - 1];
        st.pop();
    }
    return answer;
}

