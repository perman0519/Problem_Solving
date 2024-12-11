#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void slide_left(vector<vector<int> > &table) {
	queue<int> q;
	for (auto &v : table) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != 0)
				q.push(v[i]);
		}
		int now = 0;
		if (!q.empty()) {
			now = q.front(); q.pop();
		}
		int i = 0;
		bool check = false;
		while (!q.empty()) {
			if (now == q.front()) {
				q.pop();
				v[i++] = now << 1;
				check = true;
				if (!q.empty()) {
					check = false;
					now = q.front(); q.pop();
				}
			}
			else {
				v[i] = now;
				i++;
				now = q.front(); q.pop();
				check = false;
			}
		}
		if (check == false)
			v[i++] = now;
		for (int j = i; j < v.size(); j++)
			v[j] = 0;
	}
}

void slide_right(vector<vector<int> > &table) {
	for (auto &v : table) {
		queue<int> q;
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] != 0)
				q.push(v[i]);
		}
		int now = 0;
		if (!q.empty()) {
			now = q.front(); q.pop();
		}
		int i = v.size();
		bool check = false;
		while (!q.empty()) {
			if (now == q.front()) {
				q.pop();
				v[--i] = now * 2;
				check = true;
				if (!q.empty()) {
					check = false;
					now = q.front(); q.pop();
				}
			}
			else {
				v[--i] = now;
				now = q.front(); q.pop();
				check = false;
			}
		}
		if (check == false)
			v[--i] = now;
		for (int j = 0; j < i; j++)
			v[j] = 0;
	}
}

void slide_down(vector<vector<int> > &table) {
	int n = table[0].size();
	for (int z = 0; z < n; z++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			v.push_back(table[j][z]);
		}
		queue<int> q;
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] != 0)
				q.push(v[i]);
		}
		int now = 0;
		if (!q.empty()) {
			now = q.front(); q.pop();
		}
		int i = v.size();
		bool check = false;
		while (!q.empty()) {
			if (now == q.front()) {
				q.pop();
				v[--i] = now * 2;
				check = true;
				if (!q.empty()) {
					check = false;
					now = q.front(); q.pop();
				}
			}
			else {
				v[--i] = now;
				now = q.front(); q.pop();
				check = false;
			}
		}
		if (check == false)
			v[--i] = now;
		for (int j = 0; j < i; j++)
			v[j] = 0;
		for (int j = 0; j < n; j++) {
			table[j][z] = v[j];
		}
	}
}

void slide_up(vector<vector<int> > &table) {
	int n = table[0].size();
	for (int z = 0; z < n; z++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			v.push_back(table[j][z]);
		}
		queue<int> q;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != 0)
				q.push(v[i]);
		}
		int now = 0;
		if (!q.empty()) {
			now = q.front(); q.pop();
		}
		int i = 0;
		bool check = false;
		while (!q.empty()) {
			if (now == q.front()) {
				q.pop();
				v[i++] = now << 1;
				check = true;
				if (!q.empty()) {
					check = false;
					now = q.front(); q.pop();
				}
			}
			else {
				v[i] = now;
				i++;
				now = q.front(); q.pop();
				check = false;
			}
		}
		if (check == false)
			v[i++] = now;
		for (int j = i; j < v.size(); j++)
			v[j] = 0;
		for (int j = 0; j < n; j++) {
			table[j][z] = v[j];
		}
	}
}

int ret = 0;

void dfs(int count, vector<vector<int> > &table) {
	if (count == 5) {
		for (auto &v : table) {
			for (auto i : v) {
				if (ret < i)
					ret = i;
			}
		}
		return ;
	}
	else {
		int n = table[0].size();
		vector<vector<int> > tmp_table(n, vector<int>(n, 0));
		for (int k = 0; k < n; k++) {
			for (int s = 0; s < n; s++) {
				tmp_table[k][s] = table[k][s];
			}
		}
		for (int i = 0; i < 4; i++) {
			switch (i) {
				case 0:
					slide_down(table);
					break;
				case 1:
					slide_up(table);
					break;
				case 2:
					slide_left(table);
					break;
				case 3:
					slide_right(table);
					break;
			}
			dfs(count + 1, table);
			for (int k = 0; k < n; k++) {
				for (int s = 0; s < n; s++) {
					table[k][s] = tmp_table[k][s];
				}
			}
		}
	}
}

int main() {
	vector<vector<int> > table;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			v.push_back(t);
		}
		table.push_back(v);
	}
	dfs(0, table);
	cout << ret;
}
