#include <iostream>
#include <vector>
#include <string>
using namespace std;

void recur(int n, int start_x, int start_y, vector<vector<char> >&vec) {
	if (n == 3) {
		vec[start_x][start_y + 2] = '*';
		vec[start_x + 1][start_y + 1] = '*';
		vec[start_x + 1][start_y + 3] = '*';
		for (int i = 0; i < 5; i++) {
			vec[start_x + 2][start_y + i] = '*';
		}
		return;
	}
	int next_n = n / 2;
	recur(next_n, start_x, start_y, vec);
	recur(next_n, start_x + next_n, start_y - next_n, vec);
	recur(next_n, start_x + next_n, start_y + next_n, vec);
}

int main(void) {
	int n;
	cin >> n;
	vector<vector<char> > vec(n, vector<char>(n * 2 - 1, ' '));
	recur(n, 0, n - 3, vec);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			cout << vec[i][j];
		}
		cout << '\n';
	}
}
