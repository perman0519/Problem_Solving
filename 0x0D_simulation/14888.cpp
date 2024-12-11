#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int Arithmetic[4] = {0};
vector<int> vec;
int max_v = -1000000000;
int min_v = 1000000000;
int num[11] = {0};
int visited[4] = {0};

void recur(int cur) {
	if (cur == n - 1) {
		int result = vec[0];
		for (int i = 0; i < n - 1; i++) {
			if (num[i] == 0) {
				result += vec[i + 1];
			}
			else if (num[i] == 1) {
				result -= vec[i + 1];
			}
			else if (num[i] == 2) {
				result *= vec[i + 1];
			}
			else if (num[i] == 3) {
				result /= vec[i + 1];
			}
		}
		max_v = max(max_v, result);
		min_v = min(min_v, result);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (visited[i] < Arithmetic[i]) {
				visited[i]++;
				num[cur] = i;
				recur(cur + 1);
				visited[i]--;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n = 0;
		cin >> n;
		vec.push_back(n);
	}
	//0: +, 1: -, 2: *, 3: /
	for (int i = 0; i < 4; i++) {
		cin >> Arithmetic[i];
	}
	recur(0);
	cout << max_v << endl;
	cout << min_v << endl;
}
