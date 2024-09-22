#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ret[6];
void recur(int cur, int start, vector<int>& vec) {
	if (cur == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ret[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < vec.size(); i++) {
		ret[cur] = vec[i];
		recur(cur + 1, i + 1, vec);
	}
}

int main() {
	int k;
	cin >> k;
	while (k != 0) {
		vector<int> vec(k);
		for (int i = 0; i < k; i++) {
			cin >> vec[i];
		}
		recur(0, 0, vec);
		cout << '\n';
		cin >> k;
	}
}
