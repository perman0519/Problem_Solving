#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b;
	int ret1 = 1, ret2 = 1;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		ret1 += a;
		ret2 += b;
		if (ret1 < ret2) {
			swap(ret1, ret2);
		}
		else if (ret1 == ret2) {
			ret2 -= 1;
		}
	}
	cout << ret1 << " " << ret2 << endl;
}
