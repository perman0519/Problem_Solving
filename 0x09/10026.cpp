#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	cin.ignore();
	vector<string> board(N);
	string str;
	for (int i = 0; i < N; i++)
	{
		// getline(str, cin, '\n');
		getline(cin, str, '\n');
		board[i] = str;
		// cout << str;
	}
	int ret = 0;
	vector<vector<int> >vis(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j] == 0) {
				ret++;
				queue<pair<int, int> > q;
				char rgb = board[i][j];
				q.push({i, j});
				vis[i][j] = 1;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (vis[nx][ny]) continue;
						if (rgb == 'B' && board[nx][ny] != 'B') continue;
						else if (rgb != 'B' && board[nx][ny] == 'B') continue;
						vis[nx][ny] = 1;
						q.push({nx, ny});
					}
				}
			}
		}
	}
	int ret1 = 0;
	vis = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j] == 0) {
				ret1++;
				queue<pair<int, int> > q;
				char rgb = board[i][j];
				q.push({i, j});
				vis[i][j] = 1;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (vis[nx][ny]) continue;
						if (rgb != board[nx][ny]) continue;
						// else if (rgb != 'R' && board[nx][ny] == 'R') continue;
						vis[nx][ny] = 1;
						q.push({nx, ny});
					}
				}
			}
		}
	}
	cout << ret1 << ' ' << ret;

}
