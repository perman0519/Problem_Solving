#include <bits/stdc++.h>
using namespace std;
int bx[4] = {1, -1, 0, 0};
int by[4] = {0, 0, 1, -1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	cin.ignore();
	vector<string> board(N);
	string str;
	for (int i = 0; i < N; i++)
	{
		getline(cin, str, '\n');
		board[i] = str;
	}
	vector<vector<vector<int>>> vis(N, vector<vector<int>>(M, vector<int>(2, 0)));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0,0,0));
	vis[0][0][0] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (get<0>(cur) == N - 1 && get<1>(cur) == M - 1) {
			cout << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)];
			return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = get<0>(cur) + bx[i];
			int ny = get<1>(cur) + by[i];
			int nw = get<2>(cur);
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (vis[nx][ny][nw]) continue;
			if (board[nx][ny] == '0') {
				vis[nx][ny][nw] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				q.push(make_tuple(nx, ny, nw));
			}
			if (board[nx][ny] == '1' && nw == 0) {
				vis[nx][ny][1] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				nw = 1;
				q.push(make_tuple(nx, ny, nw));
			}
		}
	}
	cout << -1;
	return 0;
}
