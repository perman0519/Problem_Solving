#include <bits/stdc++.h>
using namespace std;

void f2(deque<int> &dq) {
	int front = dq.front();
	dq.pop_front();
	dq.push_back(front);
}

void f3(deque<int> &dq) {
	int back = dq.back();
	dq.pop_back();
	dq.push_front(back);
}

int main() {
	cout.sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	deque<int> dq;
	deque<int> position;
	for (int i = 0; i < N; i++)
	{
		dq.push_back(i + 1);
	}
	int s;
	for (int i = 0; i < M; i++)
	{
		cin >> s;
		position.push_back(s);
	}
	int ret = 0;
	while (!position.empty()) {
		int c = position.front();
		int left = 0, right = 0;
		for (size_t i = 0; i < dq.size(); i++) {
			if (dq[i] == c) {
				left = i;
				right = dq.size() - i;
				break;
			}
		}
		while (dq.front() != c) {
			if (left <= right) {
				f2(dq);
			}
			else {
				f3(dq);
			}
			ret++;
		}
		if (dq.front() == c) {
			position.pop_front();
			dq.pop_front();
		}
	}
	cout << ret;
}


// 1 6 3 2 7 9 8 4 10 5
// 1 2 3 4 5 6 7 8 9 10
// [2 3 4 5 6 7 8 9 10] 9 / 2 = 6 > 4
// [4 5 6 7 8 9 10 2 3]
// 6 > front 6 > back
// 10 > front 10 > back
// [10 2 3 4 5 6 7 8 9]
// 6 - 10 == -4
// 6 - 9 == -3
// 1 6 3 2 7 9 8 4 10 5

// 10 2 3 4 5 6 7 8 9
// 9 10 2 3 4 5 6 7 8
// 8 9 10 2 3 4 5 6 7
// 7 8 9 10 2 3 4 5 6
// 6 7 8 9 10 2 3 4 5

// 5 7 8 9 10 2 3 4
// 4 5 7 8 9 10 2 3
// 3 4 5 7 8 9 10 2

// 2 4 5 7 8 9 10

// 10 4 5 7 8 9
// 9 10 4 5 7 8
// 8 9 10 4 5 7
// 7 8 9 10 4 5

// 5 8 9 10 4
// 4 5 8 9 10
// 10 4 5 8 9
// 9 10 4 5 8

// 8 10 4 5

// 5 10 4
// 4 5 10

// 10 5

// 21
