#include <iostream>
#include <vector>
using namespace std;

void recur(int n, int start_x, int start_y, vector<vector<int> >&vec) {
	if (n == 1) {
		cout << vec[start_x][start_y];
		return;
	}
	int start_num = vec[start_x][start_y];
	for (int i = start_x; i < start_x + n; i++) {
		for (int j = start_y; j < start_y + n; j++) {
			if (start_num != vec[i][j]) {
				cout << "(";
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						recur(n >> 1, start_x + (k * n / 2), start_y + (l * n / 2), vec);
					}
				}
				cout << ")";
				return;
			}
		}
	}
	cout << start_num;
}

int main(void) {
	int n;
	cin >> n;
	vector<vector<int> > vec(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			vec[i][j] = str[j] - '0';
		}
	}
	recur(n, 0, 0, vec);
	return 0;
}
