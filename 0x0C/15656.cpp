#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n, m;
int arr[9];
int ret[9];
void recur(int cur) {
	if (m == cur) {
		for (int i = 0; i < m; i++) {
			cout << ret[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		ret[cur] = arr[i];
		recur(cur + 1);
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	recur(0);
}
