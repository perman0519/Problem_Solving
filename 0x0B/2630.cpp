#include <iostream>
#include <vector>
using namespace std;

int r1 = 0, r2 = 0;

void recur(int n, int start_x, int start_y, vector<vector<int> >&vec) {
	if (n == 0)
		return ;
	int start_num = vec[start_x][start_y];
	for (int i = start_x; i < start_x + n; i++) {
		for (int j = start_y; j < start_y + n; j++) {
			if (start_num != vec[i][j]) {
				int nx = n / 2;
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						recur(nx, start_x + (k *nx), start_y + (l * nx), vec);
					}
				}
				return;
			}
		}
	}
	if (start_num == 1)
		r2++;
	else
		r1++;
}

 int main() {
	int n;
	cin >> n;
	vector<vector<int> > vec = vector<vector<int> >(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> vec[i][j];
	}
	recur(n, 0, 0, vec);
	cout << r1 << endl << r2;

	return 0;
 }
