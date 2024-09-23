#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int nx[4] = {0, 0, 1, -1};
int ny[4] = {1, -1, 0, 0};
vector<vector<int> > vec(5, vector<int>(5, 0));
int ret = 0;
vector<int> arr(7, 0);

void dfs() {
    stack<int> s;
    s.push(arr[0]);
    vector<int> visited2(25, 0);
    visited2[arr[0]] = 1;
    int s_count = 0;
    int dfs_count = 1;  // 시작점도 카운트에 포함
    if (vec[arr[0] / 5][arr[0] % 5] == 1) {
        s_count++;
    }
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        for (int i = 0; i < 4; i++) {
            int newRow = cur / 5 + nx[i];
            int newCol = cur % 5 + ny[i];
            if (newRow < 0 || newRow >= 5 || newCol < 0 || newCol >= 5) continue;
            int num = newRow * 5 + newCol;
            if (find(arr.begin(), arr.end(), num) == arr.end()) continue;
            if (visited2[num] == 1) continue;
            visited2[num] = 1;
            s.push(num);
            dfs_count++;
            if (vec[num / 5][num % 5] == 1) {
                s_count++;
            }
        }
    }
    if (dfs_count == 7 && s_count >= 4) {
        ret++;
    }
}

int visited[25] = {0};

void recur(int cur, int start) {
	if (cur == 7) {
		dfs();
		return;
	}
	for (int i = start; i < 25; i++) {
			arr[cur] = i;
			recur(cur + 1, i + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j < 5; j++) {
			if (s[j] == 'S') {
				vec[i][j] = 1;
			}
			else {
				vec[i][j] = 0;
			}
		}
	}

	recur(0, 0);
	cout << ret;
}
