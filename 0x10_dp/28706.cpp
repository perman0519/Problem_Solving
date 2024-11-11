#include <iostream>
#include <string.h>
using namespace std;
// N개의 턴
// 각 턴에 2가지의 선택중 하나
// "+ v" : K + v
// "* v" : K * v
// K가 7의 배수

// int dp[10000][200000][7];

int prv[7] = {0};
int nxt[7] = {0};
int main() {
	cout.tie(0);
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 7; i++) {
			prv[i] = 0;
			nxt[i] = 0;
		}
		int N;
		cin >> N;
		prv[1] = 1;
		for (int i = 1; i <= N; i++) {
			int v1, v2;
			char op1, op2;
			cin >> op1 >> v1 >> op2 >> v2;
			for (int j = 0; j < 7; j++) {
				if (prv[j]) {
					if (op1 == '*') {
						int k = (j * v1) % 7;
						nxt[k] = 1;
					}
					else {
						int k = (j + v1) % 7;
						nxt[k] = 1;
					}

					if (op2 == '*') {
						int k = (j * v2) % 7;
						nxt[k] = 1;
					}
					else {
						int k = (j + v2) % 7;
						nxt[k] = 1;
					}
				}
			}
			for (int i = 0; i < 7; i++) {
				prv[i] = nxt[i];
				nxt[i] = 0;
			}
		}
		if (prv[0])
			cout << "LUCKY\n";
		else
			cout << "UNLUCKY\n";
	}
	return 0;
}
