#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
bool visited[9];
int ret[9];

void recur(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << ret[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int prev = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == prev) continue;
		if (arr[i] < ret[cur - 1]) continue;
		ret[cur] = arr[i];
		recur(cur + 1);
		prev = arr[i];
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	recur(0);
}
