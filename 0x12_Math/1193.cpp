#include <bits/stdc++.h>
using namespace std;

int x;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x;
	int s = 1;
	int m = 1;
	int count = 1;
	if (x == 1) {
		cout << s << '/' << m << endl;
		return 0;
	}
	int n = 2;
	while(true) {
		if (n % 2 == 0) {
			m = n;
		}
		else
			s = n;
		count++;
		if (count == x) {
			cout << s << '/' << m << endl;
			return 0;
		}
		for (int i = 1; i < n; i++) {
			if (n % 2 == 0) {
				s++;
				m--;
			}
			else {
				s--;
				m++;
			}
			count++;
			if (count == x) {
				cout << s << '/' << m << endl;
				return 0;
			}
		}
		n++;
	}
	return 0;
}
