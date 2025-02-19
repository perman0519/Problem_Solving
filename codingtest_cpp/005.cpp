// https://school.programmers.co.kr/learn/courses/30/lessons/12949
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int a1 = arr1.size();
    int a2 = arr1[0].size();
    int b1 = arr2.size();
    int b2 = arr2[0].size();

    for (int i = 0; i < a1; i++) {
        vector<int> tmp;
        for (int j = 0; j < b2; j++) {
            int n = 0;
            for (int k = 0; k < a2; k++) {
                n += arr1[i][k] * arr2[k][j];
            }
            tmp.push_back(n);
        }
        answer.push_back(tmp);
    }
    return answer;
}

// vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
// 	int a1 = arr1.size();
// 	int a2 = arr1[0].size();
// 	int b1 = arr2.size();
// 	int b2 = arr2[0].size();

// 	vector<vector<int> > answer(a1,vector<int>(b2, 0));
// 	for (int i = 0; i < a1; i++) {
// 		for (int j = 0; j < b2; j++) {
// 			for (int k = 0; k < a2; k++) {
// 				answer[i][j] += arr1[i][k] * arr2[k][j];
// 			}
// 		}
// 	}
// 	return answer;
// }
