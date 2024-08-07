#include <bits/stdc++.h>
using namespace std;

bool iscycle(int idx, int n, vector<int> &board) {
	int cur = idx;
	for (int i = 1; i <=n; i++)
	{
		cur = board[cur];
		if(cur == idx)
			return true;
	}
	return false;
}

int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> board(n + 1, 0);
		for (int i = 1; i <= n; i++)
			cin >> board[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!iscycle(i, n, board))
				ans++;
		}
		cout << ans << '\n';
	}
}
