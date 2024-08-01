#include <bits/stdc++.h>
using namespace std;
int bx[4] = {1, -1, 0, 0};
int by[4] = {0, 0, 1, -1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int m, n, k;
	cin >> m >> n >> k;
	vector<vector<int> > board(m, vector<int>(n, 0));
	vector<vector<int> > vis(m, vector<int>(n, 0));
	while(k--) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for (int i = ly; i < ry; i++)
		{
			for (int j = lx; j < rx; j++)
			{
				board[i][j] = 1;
			}
		}
	}
	queue<pair<int, int>> q;
	vector<int> rets;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int ret = 1;
			if(board[i][j] == 0 && vis[i][j] == 0) {
				q.push({i, j});
				vis[i][j] = 1;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = cur.first + bx[k];
						int ny = cur.second + by[k];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || board[nx][ny] == 1) continue;
						q.push({nx, ny});
						ret++;
						vis[nx][ny] = 1;
					}
				}
				rets.push_back(ret);
			}
		}
	}
	sort(rets.begin(), rets.end());
	cout << rets.size() << '\n';
	for (auto i : rets)
		cout << i << ' ';
}
