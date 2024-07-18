#include <bits/stdc++.h>
using namespace std;

int main() {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int MX = 5000;
	int dq[2 * MX + 1];
	int head = MX, tail = MX;
	int N;
	cin >> N;
	string str;
	int size = 0;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> str;
		if (str == "push_back") {
			cin >> x;
			dq[tail++] = x;
			size++;
			continue;
		}
		else if (str == "push_front") {
			cin >> x;
			dq[--head] = x;
			size++;
			continue;
		}
		else if (str == "pop_back") {
			if (size != 0) {
				cout << dq[tail-- - 1];
				size--;
			}
			else
				cout << -1;
		}
		else if (str == "pop_front") {
			if (size != 0) {
				cout << dq[head++];
				size--;
			}
			else
				cout << -1;
		}
		else if (str == "size") {
			cout << size;
		}
		else if (str == "empty") {
			if (size == 0)
				cout << 1;
			else
				cout << 0;

		}
		else if (str == "front") {
			if (size != 0) {
				cout << dq[head];
			}
			else
				cout << -1;
		}
		else { //back
			if (size != 0) {
				cout << dq[tail - 1];
			}
			else
				cout << -1;
		}
		cout << '\n';
	}
}
