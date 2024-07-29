#include <bits/stdc++.h>
using namespace std;
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	int vis[100001] = {0};
	cin >> N >> K;
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == K) {
			cout << vis[cur];
			return 0;
		}
		for (int i = 0; i < 3; i++)
		{
			int nx = cur;
			for (int nxt : {nx + 1, nx - 1, 2 * nx}) {
				if (nxt < 0 || nxt > 100000) continue;
				if (vis[nxt] > 0) continue;
				vis[nxt] = vis[cur] + 1;
				q.push(nxt);
			}
		}

	}
	return 0;
}
