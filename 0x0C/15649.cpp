#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void recur(int x) {
	if (x == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			arr[x] = i;
			recur(x + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	recur(0);
}

