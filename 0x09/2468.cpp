#include <bits/stdc++.h>
using namespace std;
int bx[4] = {-1, 1, 0, 0};
int by[4] = {0, 0, 1, -1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<vector<int> > board(N, vector<int>(N, 0));
	int mins = 100, maxs = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			mins = min(mins, board[i][j]);
			maxs = max(maxs, board[i][j]);
		}
	}
	int ret = 1;
	for (int dep = mins; dep <= maxs; dep++)
	{
		int cnt = 0;
		vector<vector<int> > vis(N, vector<int>(N, 0));
		queue<pair<int, int> > q;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] > dep && vis[i][j] == 0) {
					cnt++;
					q.push({i, j});
					vis[i][j] = 1;
					while(!q.empty()) {
						auto cur = q.front();
						q.pop();
						for (int k = 0; k < 4; k++)
						{
							int nx = cur.first + bx[k];
							int ny = cur.second + by[k];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
							if (vis[nx][ny] || board[nx][ny] <= dep) continue;
							q.push({nx, ny});
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
		ret = max(ret, cnt);
	}
	cout << ret;
}
