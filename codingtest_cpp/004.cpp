// https://school.programmers.co.kr/learn/courses/30/lessons/42840
#include <algorithm>
#include <vector>
using namespace std;

int s1[5] = {1,2,3,4,5};
int s2[8] = {2,1,2,3,2,4,2,5};
int s3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> solution(vector<int> answers) {
    size_t sn = answers.size();
    vector<int> scores(3, 0);
    for (int i = 0; i < sn; i++) {
        if (answers[i] == s1[i % 5])
            scores[0]++;
        if (answers[i] == s2[i % 8])
            scores[1]++;
        if (answers[i] == s3[i % 10])
            scores[2]++;
    }
    vector<int> ret;
    auto high_it = max_element(scores.begin(), scores.end());
    int high = *high_it;
    for (int i = 0; i < 3; i++) {
        if (high == scores[i])
            ret.push_back(i+1);
    }
    return ret;
}
