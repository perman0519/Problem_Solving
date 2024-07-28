#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1001][1001] = {0};
int day[1001][1001] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	queue<pair<int, int> > q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 1) {
				q.push({i, j});
				day[i][j] = board[i][j];
			}
	while(!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = cur.X + dx[k];
			int ny = cur.Y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (day[nx][ny] > 0 || board[nx][ny] != 0) continue;
			day[nx][ny] = day[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 && day[i][j] == 0) {
				cout << -1;
				return 0;
			}
			ret = max(ret, day[i][j]);
		}
	cout << ret - 1;
}
