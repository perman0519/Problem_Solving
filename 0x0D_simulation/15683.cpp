#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[8][8];
int board2[8][8];
vector<pair<int, int> > cctv;

bool check(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}

void update(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (check(x, y) || board2[x][y] == 6)
			return;
		if (board2[x][y] != 0)
			continue;
		board2[x][y] = 7;
	}
}

int main() {
	cin >> n >> m;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6) {
				cctv.push_back(make_pair(i, j));
			}
			if (board[i][j] == 0)
				ret++;
		}
	}

	for (int tmp = 0; tmp < (1 << (2*cctv.size())); tmp++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				board2[i][j] = board[i][j];
		}
		int brute = tmp;
		for (int i = 0; i < int(cctv.size()); i++) {
			int x = cctv[i].first;
			int y = cctv[i].second;
			int kind = board[x][y];
			int dir = brute % 4;
			brute /= 4;
			if (kind == 1) {
				update(x, y, dir);
			} else if (kind == 2) {
				update(x, y, dir);
				update(x, y, dir+2);
			} else if (kind == 3) {
				update(x, y, dir);
				update(x, y, dir+1);
			} else if (kind == 4) {
				update(x, y, dir);
				update(x, y, dir+1);
				update(x, y, dir+2);
			} else {
				update(x, y, dir);
				update(x, y, dir+1);
				update(x, y, dir+2);
				update(x, y, dir+3);
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (board2[i][j] == 0)
					cnt++;
		}
		ret = min(ret, cnt);
	}
	cout << ret << endl;
}
