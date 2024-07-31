#include <bits/stdc++.h>
using namespace std;
int bx[4] = {-1, 1, 0, 0};
int by[4] = {0, 0, -1, 1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		int y, x;
		cin >> y >> x;
		vector<string> board(x);
		vector<vector<int> > fire(x, vector<int>(y, 0));
		vector<vector<int> > player(x, vector<int>(y, 0));
		string str;
		cin.ignore();
		for (int i = 0; i < x; i++)
		{
			getline(cin, str, '\n');
			board[i] = str;
		}
		queue<pair<int, int> > player_q;
		queue<pair<int, int> > fire_q;
		bool player_line = false;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (board[i][j] == '@') {
					if (i == 0 || i == x - 1 || j == 0 || j == y - 1) {
						player_line = true;
						cout << "1\n";
					}
					player_q.push({i, j});
					player[i][j] = 1;
				}
				else if  (board[i][j] == '*') {
					fire_q.push({i, j});
					fire[i][j] = 1;
				}
			}
		}
		if (player_line)
			continue;
		while(!fire_q.empty()) {
			pair<int, int> cur = fire_q.front(); fire_q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + bx[i];
				int ny = cur.second + by[i];
				if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
				if (fire[nx][ny] > 0 || board[nx][ny] == '#') continue;
				fire[nx][ny] = fire[cur.first][cur.second] + 1;
				fire_q.push({nx, ny});
			}
		}
		while(!player_q.empty()) {
			auto cur = player_q.front(); player_q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + bx[i];
				int ny = cur.second + by[i];
				if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
				if (player[nx][ny] > 0 || board[nx][ny] == '#') continue;
				if (fire[nx][ny] != 0 && fire[nx][ny] <= player[cur.first][cur.second] + 1) continue;
				if (nx == 0 || nx == x - 1 || ny == 0 || ny == y - 1) {
					cout <<  player[cur.first][cur.second] + 1 << "\n";
					player_line = true;
					break;
				}
				player[nx][ny] = player[cur.first][cur.second] + 1;
				player_q.push({nx, ny});
			}
			if (player_line)
				break;
		}
		if (player_line == false)
			cout << "IMPOSSIBLE\n";
	}
}
