#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ret = 0;

void recur(int cur, vector<pair<int, int> > &vec) {
	if (cur == n) {
			int count = 0;
			for (int i = 0; i < n; i++) {
				if (vec[i].first <= 0) {
					count++;
				}
			}
			ret = max(ret, count);
			return ;
	}
	if (vec[cur].first <= 0) {
		recur(cur + 1, vec);
		return ;
	}
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (vec[i].first <= 0 || cur == i) continue;
		vec[cur].first -= vec[i].second;
		vec[i].first -= vec[cur].second;
		check = true;
		recur(cur + 1, vec);
		vec[cur].first += vec[i].second;
		vec[i].first += vec[cur].second;
	}
	if (!check) {
		recur(cur + 1, vec);
	}
}

int main() {
	cin >> n;
	vector<pair<int, int> > vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}
	recur(0,vec);
	cout << ret << endl;
}
