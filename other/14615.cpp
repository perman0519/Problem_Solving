#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//정방향 역방향 bfs를 생각할 수 있어야함
//2번의 bfs만으로 T 시행횟수를 전부 구할 수 있음
//너무어렵다 bfs dfs 흑흑

vector<int> v[100001];
vector<int> v2[100001];
bool OneToAll[100001];
bool nToAll[100001];

void bfs(int start, bool b[]) {
	queue<int> q;
	q.push(start);
	b[start] = true;
	while (!q.empty()) {
		int cur = q.front();q.pop();
		for (auto n : v[cur]) {
			if (!b[n]) {
				b[n] = true;
				q.push(n);
			}
		}
	}
}

void reverse_bfs(int start, bool b[]) {
	queue<int> q;
	q.push(start);
	b[start] = true;
	while (!q.empty()) {
		int cur = q.front();q.pop();
		for (auto n : v2[cur]) {
			if (!b[n]) {
				b[n] = true;
				q.push(n);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v2[y].push_back(x);
	}
	bfs(1, OneToAll);
	reverse_bfs(n, nToAll);
	int t;
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		if (OneToAll[c] && nToAll[c]) {
			cout << "Defend the CTP\n";
		}
		else {
			cout << "Destroyed the CTP\n";
		}
	}
	return 0;
}
