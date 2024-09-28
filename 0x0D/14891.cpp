#include <iostream>
#include <vector>
using namespace std;

vector<int> wheel[4];
int K;

void rotate_right(vector<int>& v) {
    int temp = v.back();
    v.pop_back();
    v.insert(v.begin(), temp);
}

void rotate_left(vector<int>& v) {
    int temp = v.front();
    v.erase(v.begin());
    v.push_back(temp);
}

int main() {
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            wheel[i].push_back(c - '0');
        }
    }
    cin >> K;

    for (int i = 0; i < K; i++) {
        int num, dir;
        cin >> num >> dir;
        num--;
        vector<int> dirs(4, 0);
        dirs[num] = dir;

        for (int j = num; j < 3; j++) {
            if (wheel[j][2] != wheel[j + 1][6]) {
                dirs[j + 1] = -dirs[j];
            } else {
                break;
            }
        }
        for (int j = num; j > 0; j--) {
            if (wheel[j][6] != wheel[j - 1][2]) {
                dirs[j - 1] = -dirs[j];
            } else {
                break;
            }
        }

        for (int j = 0; j < 4; j++) {
            if (dirs[j] == 1) {
                rotate_right(wheel[j]);
            } else if (dirs[j] == -1) {
                rotate_left(wheel[j]);
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (wheel[i][0] == 1) {
            ret += (1 << i);
        }
    }
    cout << ret << endl;
    return 0;
}
