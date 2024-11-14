#include <iostream>
#include <vector>
using namespace std;
// 소수 구하기
// m 이상 n 이하의 소수를 모두 출력하는 프로그램
// 2 <= m <= n <= 1,000,000
int main() {
	int m, n;
	cin >> m >> n;
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (prime[i])
			cout << i << '\n';
	}
	return 0;
}
