#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	deque<pair<int, bool> > dq(2 * n, {0, false});
	for (int i = 0; i < 2 * n; i++) {
		cin >> dq[i].first;
	}
	int ret = 0;
	while (true) {
		// 1.회전
		pair<int, bool> p = dq.back();
		dq.pop_back();
		dq.push_front(p);
		// 가장먼저 올라간 로봇부터 이동
		if (dq[n - 1].second == true)
			dq[n - 1].second = false;
		for (int i = 2 * n - 2; i >= 0; i--) {
			if (dq[i].second == false)
				continue;
			if (dq[i + 1].second == false && dq[i + 1].first > 0) {
				dq[i].second = false;
				dq[i + 1].second = true;
				dq[i + 1].first--;
			}
		}
		if (dq[n - 1].second == true)
			dq[n - 1].second = false;
		//3 로봇 올리기
		if (dq[0].first > 0) {
			dq[0].second = true;
			dq[0].first--;
		}
		// 내구성 0이 k이상인 수 계산
		int c = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (dq[i].first == 0)
				c++;
		}
		ret++;
		if (c >= k)
			break;
	}
	cout << ret;
	return 0;
}
