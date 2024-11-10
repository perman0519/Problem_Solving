#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int b[101][101];
int nx[8] = {0, -1,-1, -1, 0, 1, 1, 1};
int ny[8] = {-1, -1,0, 1, 1, 1, 0, -1};
int ndx[4] = {1, -1, 1, -1};
int ndy[4] = {1, -1, -1, 1};

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
		}
	}
	vector<pair<int, int> > v;
	v.push_back({n, 1});
	v.push_back({n, 2});
	v.push_back({n-1, 1});
	v.push_back({n-1, 2});
	while (m--) {
		int d, s;
		cin >> d >> s;
		int dx = nx[d - 1];
		int dy = ny[d - 1];
		for (auto it = v.begin(); it != v.end(); it++) {
			for (int i = 0; i < s; i++) {
				it->first += dx;
				if (it->first == 0) it->first = n;
				else if (it->first == n + 1) it->first = 1;
				it->second += dy;
				if (it->second == 0) it->second = n;
				else if (it->second == n + 1) it->second = 1;
			}
			b[it->first][it->second] += 1;
		}
		int tmp[51 * 51] = {0};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < v.size(); j++) {
				int dx = v[j].first + ndx[i];
				int dy = v[j].second + ndy[i];
				if (dx < 1 || dy < 1 || dx > n || dy > n) continue;
				if (b[dx][dy] > 0) tmp[j]++;
			}
		}
		for (int j = 0; j < v.size(); j++) {
			b[v[j].first][v[j].second] += tmp[j];
		}
		vector<pair<int, int> > newV;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (b[i][j] >= 2 && find(v.begin(), v.end(), pair<int, int>(i, j)) == v.end()) {
					newV.push_back({i, j});
					b[i][j] -= 2;
				}
			}
		}
		v.clear();
		v = newV;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += b[i][j];
		}
	}
	cout << sum;
	return 0;
}
