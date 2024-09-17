#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<int> arr(20);
int visited[20];
int cnt = 0;

void recur(int cur, int tot) {
	if (tot == s) {
		cnt++;
	}
	if (cur == n) {
		return;
	}
	for (int i = cur; i < n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			recur(i + 1, tot + arr[i]);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	recur(0, 0);
	if (s == 0)
		cnt--;
	cout << cnt;
}
