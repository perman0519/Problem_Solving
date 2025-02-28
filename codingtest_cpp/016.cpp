#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> que;
    for (int i = 0; i < progresses.size(); i++) {
        que.push({progresses[i], speeds[i]});
    }
    while (!que.empty()) {
        for (int i = 0; i < que.size(); i++) {
            auto q = que.front(); que.pop();
            que.push({q.first + q.second, q.second});
        }
        int ans = 0;
        while (!que.empty() && que.front().first >= 100) {
            que.pop();
            ans++;
        }
        if (ans > 0)
            answer.push_back(ans);
    }
    return answer;
}
