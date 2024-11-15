#include <iostream>
#include <deque>
#include <queue>
using namespace std;
// 3190 뱀
// sneak 게임
// 뱀의 머리와 꼬리 위치 추적
// 구현
// 자료 구조
// 시뮬레이션
// 덱
// 큐

int b[101][101] = {0};
int bx[4] = {0, 1, 0, -1};
int by[4] = {1,0,-1, 0};

int main() {
	deque<pair<int, int> > sneak;
	sneak.push_front({1, 1});
	pair<int, int> hd = sneak.front();
	b[hd.first][hd.second] = 9;
	int n;
	cin >> n;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		b[x][y] = 1;
	}
	int l;
	cin >> l;
	queue<pair<int, char> >q;
	for (int i = 0; i < l; i++) {
		int t;
		char dir;
		cin >> t >> dir;
		q.push({t, dir});
	}
	int d = 0;
	int time = 1;
	while(1) {
		int nx = bx[d];
		int ny = by[d];
		if (q.front().first == time) {
			if (q.front().second == 'D') {
				d = (d + 1) % 4;
			}
			else {
				d--;
				if (d == -1)
					d = 3;
			}
			q.pop();
		}
		pair<int, int> hd = sneak.front();
		pair<int, int> ta = sneak.back();
		pair<int, int> tmp({hd.first + nx, hd.second + ny});
		if (tmp.first < 1 || tmp.second < 1 || tmp.first > n || tmp.second > n) {
			cout << time;
			return 0;
		}
		if (b[tmp.first][tmp.second] == 9) {
			cout << time;
			return 0;
		}
		if (b[tmp.first][tmp.second] != 1) {
			b[ta.first][ta.second] = 0;
			sneak.pop_back();
		}
		sneak.push_front(tmp);
		b[tmp.first][tmp.second] = 9;
		time++;
	}
	return 0;
}
