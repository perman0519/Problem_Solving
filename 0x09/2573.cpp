#include <bits/stdc++.h>
using namespace std;
int bx[4] = {1, -1, 0, 0};
int by[4] = {0, 0, 1, -1};
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M, 0));
	vector<vector<int>> next_board(N, vector<int>(M, 0));
	vector<vector<int>> vis(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}
	next_board = board;
	queue<pair<int, int>> q;
	// int ret = 0;
	// while (ret > 2)
	// for (int i = 1; i < N - 1; i++)
	// {
	// 	for (int j = 1; j < M - 1; j++)
	// 	{
	// 		if (board[i][j] > 0) {
	// 			int meet_zero = 0;
	// 			for (int k = 0; k < 4; k++)
	// 			{
	// 				int nx = i + bx[k];
	// 				int ny = j + by[k];
	// 				if (board[nx][ny] == 0) meet_zero++;
	// 			}
	// 			next_board[i][j] -= meet_zero;
	// 			if (next_board[i][j] < 0)
	// 				next_board[i][j] = 0;
	// 		}
	// 	}
	// }
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < M; j++)
	// 	{
	// 		cout << next_board[i][j] << ' ';
	// 	}
	// 	cout << "\n";
	// }
	return 0;
}
