// https://school.programmers.co.kr/learn/courses/30/lessons/42889
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());
    multimap<float, int, greater<float>> rates;
    for (int i = 0; i < N; i++) {
        auto fit = find(stages.begin(), stages.end(), i + 1);
        if (fit == stages.end()) {
            rates.insert({0.0, i + 1});
        }
        else {
            int numer = 0;
            size_t dis = distance(stages.begin(), fit);
            int denomi = stages.size() - dis;
            int now = i + 1;
            for (auto it = fit; it != stages.end(); it++) {
                if (*it != now) {
                    break;
                }
                else {
                    numer++;
                }
            }
            rates.insert({(float)numer / denomi, now});
        }
    }
    for (auto it = rates.begin(); it != rates.end(); it++) {
        answer.push_back(it->second);
    }
    return answer;
}
