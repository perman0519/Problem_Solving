#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1001];
int fire[1001][1001] = {0};
int vis[1001][1001] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int R, C;
	cin >> R >> C;
	string str;
	queue<pair<int, int> > q;
	queue<pair<int, int> > fireq;
	for (int i = 0; i < R; i++) {
		cin >> board[i];
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == 'F') {
				fireq.push({i, j});
				fire[i][j] = 1;
			}
			else if (board[i][j] == 'J') {
				if (j == 0 || j == C - 1 || i == 0 || i == R - 1) {
					cout << "1";
					return 0;
				}
				q.push({i, j});
				vis[i][j] = 1;
			}
		}
	}
	int ret = 1;
	while (!fireq.empty()) {
		pair<int, int> cur = fireq.front(); fireq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (fire[nx][ny] || board[nx][ny] == '#') continue;
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			fireq.push({nx, ny});
		}
	}
	while (!q.empty()) {
		// ret++;
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (vis[nx][ny] > 0 || board[nx][ny] != '.') continue;
			if (fire[nx][ny] != 0 && fire[nx][ny] <= vis[cur.X][cur.Y] + 1) continue;
			if (nx == 0 || nx == R - 1 || ny == 0 || ny == C - 1) {
				cout <<  vis[cur.X][cur.Y] + 1;
				return 0;
			}
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
