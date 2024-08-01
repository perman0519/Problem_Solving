#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	if (S == G) {
		cout << 0;
		return 0;
	}
	vector<int> board(F);
	vector<int> vis(F);
	queue<int> q;
	q.push(S - 1);
	vis[S - 1] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int i = 0; i < 2; i++)
		{
			int nxt;
			if (i == 0)
				nxt = cur + U;
			else
				nxt = cur - D;
			if (nxt < 0 || nxt >= F) continue;
			if (vis[nxt]) continue;
			if (nxt == G - 1) {
				cout << vis[cur];
				return 0;
			}
			vis[nxt] = vis[cur] + 1;
			q.push(nxt);
		}
	}
	cout << "use the stairs";
}
