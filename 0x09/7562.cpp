#include <bits/stdc++.h>
using namespace std;
int bx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int by[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--)
	{
		int I;
		cin >> I;
		vector<vector<int> > board(I, vector<int>(I, 0));
		vector<vector<int> > vis(I, vector<int>(I, 0));
		int x, y;
		cin >> x >> y;
		pair<int, int> start_positon = {x, y};
		cin >> x >> y;
		pair<int, int> end_positon = {x, y};
		queue<pair<int, int> > q;
		q.push(start_positon);
		vis[start_positon.first][start_positon.second] = 1;
		if (start_positon == end_positon) {
			cout << "0\n";
			continue;
		}
		// int ret = 0;
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int i = 0; i < 8; i++)
			{
				int nx = cur.first + bx[i];
				int ny = cur.second + by[i];
				if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
				if (vis[nx][ny] > 0) continue;
				if (nx == end_positon.first && ny == end_positon.second) {
					cout << vis[cur.first][cur.second] << '\n';
					while(!q.empty())
						q.pop();
					break;
				}
				// ret++;
				vis[nx][ny] = 1 + vis[cur.first][cur.second];
				q.push({nx, ny});
			}
		}
	}
}
