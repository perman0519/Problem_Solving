#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int board[52][52] = {0};
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;
int arr[13];
int visited[13] = {0};
int res = INT_MAX;
//0 empty, 1 house, 2 chicken

int check_min_dis() {
	int tmp = INT_MAX;
	int full_dis = 0;
	for (int i = 0; i < house.size(); i++) {
		pair<int, int> h = house[i];
		int tmp = 200;
		for (int j = 0; j < m; j++) {
			pair<int, int> c = chicken[arr[j]];
			int dis = abs(c.first - h.first) + abs(c.second - h.second);
			tmp = min(dis, tmp);
		}
		full_dis += tmp;
	}
	return full_dis;
}

void recur(int cur, int start = 0) {
	if (cur == m) {
		int tmp = check_min_dis();
		res = min(res, tmp);
		return ;
	}
	for (int i = start; i < chicken.size(); i++) {
		arr[cur] = i;
		visited[i] = 1;
		recur(cur + 1, i + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (board[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	recur(0);
	cout << res;
}
