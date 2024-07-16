#include <bits/stdc++.h>
using namespace std;
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int st[100001];
	int head = 0;
	int tail = 0;
	int size = 0;
	int N;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		string ins;
		cin >> ins;
		int q;
		if (ins == "push") {
			cin >> q;
			st[tail++] = q;
		}
		else if (ins == "pop") {
			if (head == tail) {
				cout << -1 << "\n";
			}
			else {
				cout << st[head] << "\n";
				head++;
			}
		}
		else if (ins == "size") {
			cout << tail - head << "\n";
		}
		else if (ins == "empty") {
			if (head == tail) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (ins == "front") {
			if (head == tail) {
				cout << -1 << "\n";
			}
			else {
				cout << st[head] << "\n";
			}
		}
		else if (ins == "back") {
			if (head == tail) {
				cout << -1 << "\n";
			}
			else {
				cout << st[tail - 1] << "\n";
			}
		}
	}
}
