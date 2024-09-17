#include <iostream>
using namespace std;

int n;
int arr[15][15];
bool is_used1[30];
bool is_used2[30];
bool is_used3[30];

int cnt = 0;

void recur(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (is_used1[i] || is_used2[cur + i] || is_used3[cur - i + n - 1]) {
			continue;
		}
		else {
			is_used1[i] = true;
			is_used2[cur + i] = true;
			is_used3[cur - i + n - 1] = true;
			recur(cur + 1);
			is_used1[i] = false;
			is_used2[cur + i] = false;
			is_used3[cur - i + n - 1] = false;
		}
	}
}

int main(void) {
	cin >> n;
	recur(0);
	cout << cnt;
}
