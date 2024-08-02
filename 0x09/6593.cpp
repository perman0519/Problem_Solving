#include <bits/stdc++.h>
using namespace std;
int bx[6] = {-1, 1, 0, 0, 0, 0};
int by[6] = {0, 0, 1, -1, 0, 0};
int bz[6] = {0, 0, 0, 0, 1, -1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int L, R, C;
	cin >> L >> R >> C;
	cin.ignore();
	while (L != 0 && R != 0 && C != 0) {
		vector<vector<string>> board(L, vector<string>(R));
		for (int i = 0; i < L; i++)
		{
			string str;
			for (int j = 0; j < R; j++)
			{
				getline(cin, str, '\n');
				board[i][j] = str;
			}
			getline(cin, str, '\n');
		}
		vector<vector<vector<int>>> vis(L, vector<vector<int>>(R, vector<int>(C, -1)));
		queue<tuple<int, int, int>> q;
		bool ret = false;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					if (board[i][j][k] == 'S') {
						q.push(make_tuple(i,j,k));
						vis[i][j][k] = 0;
						while (!q.empty()) {
							auto cur = q.front(); q.pop();
							for (int l = 0; l < 6; l++)
							{
								int nz = get<0>(cur) + bz[l];
								int nx = get<1>(cur) + bx[l];
								int ny = get<2>(cur) + by[l];
								if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
								if (vis[nz][nx][ny] > -1 || board[nz][nx][ny] == '#') continue;
								vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
								if (board[nz][nx][ny] == 'E') {
									cout << "Escaped in " << vis[nz][nx][ny] << " minute(s).\n";
									ret = true;
									break;
								}
								q.push(make_tuple(nz, nx, ny));
							}
						}
					}
				}
			}
		}
		if (ret == false)
			cout << "Trapped!\n";
		cin >> L >> R >> C;
		cin.ignore();
	}
}
