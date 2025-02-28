#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> que1;
    queue<string> que2;
    queue<string> que_goal;
    for (int i = 0; i < cards1.size(); i++)
        que1.push(cards1[i]);
    for (int i = 0; i < cards2.size(); i++)
        que2.push(cards2[i]);
    for (int i = 0; i < goal.size(); i++)
        que_goal.push(goal[i]);

    while(!que_goal.empty()) {
        if (que_goal.front() == que1.front()) {
            que1.pop();
            que_goal.pop();
        }
        else if (que_goal.front() == que2.front()) {
            que2.pop();
            que_goal.pop();
        }
        else {
            answer += "No";
            return answer;
        }
    }
    answer += "Yes";
    return answer;
}
