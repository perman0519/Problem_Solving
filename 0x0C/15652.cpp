#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
int arr[9];

void recur(int cur, int start) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		arr[cur] = i;
		recur(cur + 1, i);
	}
}

int main(void) {
	cin >> n >> m;
	recur(0, 1);
}
