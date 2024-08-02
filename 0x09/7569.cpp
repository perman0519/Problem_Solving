#include <bits/stdc++.h>
using namespace std;
int bx[6] = {1, -1, 0, 0, 0, 0};
int by[6] = {0, 0, 1, -1, 0, 0};
int bz[6] = {0, 0, 0, 0, -1, 1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int y, x, z;
	cin >> y >> x >> z;
	vector<vector<vector<int> >> board(z, vector<vector<int>>(x, vector<int>(y, 0)));
	for (int k = 0; k < z; k++)
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cin >> board[k][i][j];
			}
		}
	}
	vector<vector<vector<int> >> vis(z, vector<vector<int>>(x, vector<int>(y, 0)));
	queue<tuple<int, int, int>> q;
	int maxValue = 0;
	for (int k = 0; k < z; k++)
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (board[k][i][j] == 1 && vis[k][i][j] == 0) {
					q.push(make_tuple(k, i, j));
					vis[k][i][j] = 1;
				}
			}
		}
	}
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front(); q.pop();
		for (int l = 0; l < 6; l++)
		{
			int nz = get<0>(cur) + bz[l];
			int nx = get<1>(cur) + bx[l];
			int ny = get<2>(cur) +  by[l];
			if (nz < 0 || nz >= z || nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
			if (vis[nz][nx][ny] > 0 || board[nz][nx][ny] != 0) continue;
			vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			maxValue = max(maxValue, vis[nz][nx][ny]);
			q.push(make_tuple(nz, nx, ny));
		}
	}
	for (int i = 0; i < vis.size(); ++i) {
		for (int j = 0; j < vis[i].size(); ++j) {
			for (int k = 0; k < vis[i][j].size(); ++k) {
				if (board[i][j][k] != -1 && vis[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	if (maxValue > 0)
		maxValue--;
	cout << maxValue;
}
