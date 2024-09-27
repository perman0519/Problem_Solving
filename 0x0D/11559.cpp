#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char board[12][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ret = 0;
bool visited[12][6];

void dfs(int x, int y, char color, vector<pair<int, int>>& connected) {
    visited[x][y] = true;
    connected.push_back({x, y});

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
        if (visited[nx][ny] || board[nx][ny] != color) continue;
        dfs(nx, ny, color, connected);
    }
}

bool remove_and_drop() {
    bool removed = false;

    // Remove connected puyo
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (board[i][j] != '.' && !visited[i][j]) {
                vector<pair<int, int>> connected;
                dfs(i, j, board[i][j], connected);
                if (connected.size() >= 4) {
                    removed = true;
                    for (auto& p : connected) {
                        board[p.first][p.second] = '.';
                    }
                }
            }
        }
    }

    // Drop puyo
    for (int j = 0; j < 6; j++) {
        int write = 11;
        for (int i = 11; i >= 0; i--) {
            if (board[i][j] != '.') {
                board[write][j] = board[i][j];
                if (write != i) board[i][j] = '.';
                write--;
            }
        }
    }

    return removed;
}

int main() {
    for (int i = 0; i < 12; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 6; j++) {
            board[i][j] = str[j];
        }
    }

    while (true) {
        for (int i = 0; i < 12; i++) {
            fill(visited[i], visited[i] + 6, false);
        }

        bool changed = remove_and_drop();
        if (!changed) break;
        ret++;
    }

    cout << ret << endl;
    return 0;
}
