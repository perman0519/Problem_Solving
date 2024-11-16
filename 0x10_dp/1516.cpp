#include <iostream>
#include <vector>
using namespace std;

// 각 건물이 지어질 시간을 미리 가지고있는다. 선 조건 건물이 없는 건물부터
int b[502];

int main() {
	int n;
	cin >> n;
	vector<pair<int, vector<int>> > v;
	for (int i = 0; i < n; i++) {
		pair<int, vector<int> > p;
		int time;
		cin >> time;
		p.first = time;
		vector<int> tmp;
		int num = 0;
		cin >> num;
		while (num != -1) {
			tmp.push_back(num);
			cin >> num;
		}
		p.second = tmp;
		v.push_back(p);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second.size() == 0) {
			b[i] = v[i].first;
			cnt++;
		}
	}
	while (true) {
		for (int i = 0; i < n; i++) {
			vector<int> &now_v = v[i].second;
			if (now_v.size() == 1 && b[now_v[0] - 1] != 0) {
				int maxTime = b[now_v[0] - 1];
				now_v.pop_back();
				b[i] = maxTime + v[i].first;
				cnt++;
			}

			if (now_v.size() > 1) {
				bool allBuilt = true;
				int maxTime = 0;
				for (int j = 0; j < now_v.size(); j++) {
					if (b[now_v[j] - 1] == 0) {
						allBuilt = false;
						break;
					}
					maxTime = max(maxTime, b[now_v[j] - 1]);
				}

				if (allBuilt) {
					b[i] = maxTime + v[i].first;
					now_v.clear();
					cnt++;
				}
			}
		}
		if (cnt == n)
			break;
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << '\n';
	}
	return 0;
}
