#include <iostream>
#include <vector>
using namespace std;
int r1 = 0, r0 = 0, r2 = 0;

void recur(int n, int start_x, int start_y, vector<vector<int> >&vec) {
	if (n == 0)
		return ;
	int start_num = vec[start_x][start_y];
	for (int i = start_x; i < start_x + n; i++) {
		for (int j = start_y; j < start_y + n; j++) {
			if (start_num != vec[i][j]) {
				int nx =n / 3;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						recur(nx, start_x + (k * nx), start_y + (l * nx), vec);
					}
				}
				return ;
			}
		}
	}
	if (start_num == 1)
		r2++;
	else if (start_num == 0)
		r1++;
	else
		r0++;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int> > vec = vector<vector<int> >(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}
	recur(n, 0, 0, vec);
	cout << r0 << endl << r1 << endl << r2;
}
