#include <bits/stdc++.h>
using namespace std;
int main(void) {
	cout.sync_with_stdio(0);
	cin.tie(0);
	list<char> li;
	string str;
	int num;
	getline(cin, str);
	for (char c : str) {
		li.push_back(c);
	}
	cin >> num;
	auto it = li.end();
	string cmd;
	getline(cin, cmd);
	for (int i = 0; i < num; i++) {
		getline(cin, cmd);
		if (cmd[0] == 'P') {
			if (it == li.end()) {
				li.push_back(cmd[2]);
				it = li.end();
			}
			else {
				li.insert(it, cmd[2]);
			}
		}
		else if (cmd[0] == 'L') {
			if (it != li.begin())
				it--;
		}
		else if (cmd[0] == 'B') {
			if (it != li.begin()) {
				it = li.erase(--it);
			}
		}
		else { //D
			if (it != li.end())
				it++;
		}
	}
	for (auto it = li.begin(); it != li.end(); it++) {
		cout << *it;
	}
}
