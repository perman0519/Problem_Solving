#include <iostream>
#include <queue>
using namespace std;
// bfs문제
// 중간에서 가장 먼게 꼭지점이니까 4개만 계산해서 이길지말지 판단

//근데 애드 혹?? 이건 뭐임??

int b[401][401];
int check[401][401];
int bx[4] = {0 , 0, 1, -1};
int by[4] = {1, -1, 0, 0};
int main() {
	int n, m;
	cin >> n >> m;
	int d;
	cin >> d;
	int start_x = n / 2;
	int start_y = m / 2;
	queue<pair<int, int> > q;
	int ret = 0;
	q.push({start_x, start_y});
	// check[start_x][start_y] = 1;
	int qx[4] = {0, 0, n-1, n-1};
	int qy[4] = {m-1, 0, m-1, 0};
	while(!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = bx[i] + now.first;
			int ny = by[i] + now.second;
			if (check[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				if ((abs(nx - qx[j]) + abs(ny - qy[j])) >= d) {
					cnt ++;
				}
			}
			if (cnt == 0) {
				ret++;
			}
			check[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
	cout << ret;
	return 0;
}
