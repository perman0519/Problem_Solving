#include <iostream>
#include <queue>

using namespace std;

int b[51][51];
int bx[4] = {-1, 0, 1, 0};
int by[4] = {0, 1, 0, -1};

void not_clean_room(queue<pair<int, int>> &q, pair<int, int> &now, int d) {
	int back;
	if (d >= 2) back = d - 2;
	else back = d + 2;
	int back_x = now.first + bx[back];
	int back_y = now.second + by[back];
	if (b[back_x][back_y] != 1) {
		q.push({back_x, back_y});
	}
}

void clean_room(queue<pair<int, int>> &q,  pair<int, int> &now, int &d) {
	d = d - 1;
	if (d == -1)
		d = 3;
	// int turn = d;
	int turn_x = now.first + bx[d];
	int turn_y = now.second + by[d];
	if (b[turn_x][turn_y] == 0) {
		q.push({turn_x, turn_y});
	}
	else {
		q.push({now.first, now.second});
	}
}

int ret = 0;

int main() {
	int n, m;
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	queue<pair<int, int> > q;
	q.push({r, c});
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		if (b[now.first][now.second] == 0) {
			ret++;
			b[now.first][now.second] = 3;
		}
		bool clean_check = false;
		for (int i = 0; i < 4; i++) {
			int nx = now.first + bx[i];
			int ny = now.second + by[i];
			if (nx < -1 || ny < -1 || nx >= n || ny >= m) continue;
			if (b[nx][ny] == 0) {
				clean_check = true;
				break;
			}
		}
		if (clean_check == true)
			clean_room(q, now, d);
		else
			not_clean_room(q, now, d);
	}
	cout << ret;
	return 0;
}
