#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		int std_cnt;
		cin >> std_cnt;
		vector<int> board(std_cnt + 1, 0);
		vector<int> vis(std_cnt + 1, 0);
		for (int i = 1; i <= std_cnt; i++)
		{
			cin >> board[i];
			board[i];
		}
		for (int i = 1; i <= std_cnt; i++)
		{
			if (vis[i] == 0) {
				int cur = i;
				while (1) {
					vis[cur] = i;
					cur = board[cur];
					if (vis[cur] == i) {
						while (vis[cur] != -1) {
							vis[cur] = -1;
							cur = board[cur];
						}
						break;
					}
					else if(vis[cur] != 0)
						break;;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= std_cnt; i++)
		{
			if(vis[i] != -1)
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
