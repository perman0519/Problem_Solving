#include <bits/stdc++.h>
using namespace std;
int bx[4] = {-1, 1, 0, 0};
int by[4] = {0, 0, 1, -1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	cin.ignore();
	string str;
	vector<string> board(N);
	for(int i = 0; i < N; i++) {
		getline(cin, str, '\n');
		board[i] = str;
	}
	vector<vector<int> > vis(N, vector<int>(N, 0));
	queue<pair<int, int> > q;
	vector<int> rets;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int ret = 1;
			if (board[i][j] == '1' && vis[i][j] != 1) {
				q.push({i, j});
				vis[i][j] = 1;
				while(!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = cur.first + bx[k];
						int ny = cur.second + by[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (vis[nx][ny] || board[nx][ny] == '0') continue;
						ret++;
						q.push({nx, ny});
						vis[nx][ny] = 1;
					}
				}
				rets.push_back(ret);
			}
		}
	}
	cout << rets.size() << '\n';
	sort(rets.begin(), rets.end());
	for (auto ret : rets)
	{
		cout << ret << '\n';
	}
}
