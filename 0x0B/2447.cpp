#include <iostream>
#include <vector>
#include <string>
using namespace std;

void recur(int n, int start_x, int start_y, vector<vector<char> >&vec) {
	if (n == 3) {
		for (int i = start_x; i < start_x + n; i++) {
			for (int j = start_y; j < start_y + n; j++) {
				if (i == start_x + 1 && j == start_y + 1) {
					vec[i][j] = ' ';
				}
				else {
					vec[i][j] = '*';
				}
			}
		}
		return ;
	}
	for (int i = 0; i <3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			recur(n / 3, start_x + (i * n / 3), start_y + (j * n / 3), vec);
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<char> > vec(n, vector<char>(n, ' '));
	recur(n, 0, 0, vec);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << vec[i][j];
		}
		cout << '\n';
	}
}
