#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int board[501][501];
	int vis[501][501] = {0};
	int n, m;
	cin >> n >> m;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int max = 0, cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && vis[i][j] == 0) {
				cnt++;
				int tmp = 0;
				queue<pair<int, int> >q;
				vis[i][j] = 1;
				q.push({i, j}); tmp++;
				while(!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						q.push({nx, ny}); tmp++;
					}
				}
				if (tmp > max)	max = tmp;
			}
		}
	}
	cout << cnt << '\n';
	cout << max << '\n';
}
