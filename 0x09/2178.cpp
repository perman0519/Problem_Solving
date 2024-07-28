#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[101][101];
int dist[101][101] = {0};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	cin.ignore();
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str, '\n');
		for (int j = 0; j < m; j++)
			board[i][j] = str[j] - '0';
	}
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	queue<pair<int, int> > q;
	q.push({0, 0});
	dist[0][0] = 1;
	while(!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] > 0 || board[nx][ny] != 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout << dist[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	cout << dist[n - 1][m - 1];
}
