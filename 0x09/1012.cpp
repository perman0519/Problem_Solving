#include <bits/stdc++.h>
using namespace std;

// int board[51][51] = {0};
// int vis[51][51] = {0};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	int M = 0, N = 0, K = 0;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		std::vector<std::vector<int>> board(M, std::vector<int>(N, 0));
		std::vector<std::vector<int>> vis(M, std::vector<int>(N, 0));
		for (int j = 0; j < K; j++)
		{
			int x,y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		int cnt = 0;
		for (int k = 0; k < M; k++)
		{
			for (int l = 0; l < N; l++)
			{
				if (board[k][l] && vis[k][l] != 1) {
					cnt++;
					queue<pair<int, int> >q;
					q.push({k, l});
					vis[k][l] = 1;
					while (!q.empty()) {
						pair<int, int> cur = q.front(); q.pop();
						for (int i = 0; i < 4; i++)
						{
							int nx = cur.first + dx[i];
							int ny = cur.second + dy[i];
							if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
							if (vis[nx][ny] || board[nx][ny] != 1) continue;
							vis[nx][ny] = 1;
							q.push({nx, ny});
						}
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}
