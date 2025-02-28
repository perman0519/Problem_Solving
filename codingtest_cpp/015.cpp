#include <queue>
#include <iostream>

using namespace std;

int solution(int N, int K) {
	int ret = 0;
	queue<int> que;
	for (int i = 0; i < N; i++)
		que.push(i + 1);
	while (!que.empty()) {
		for (int i = 0; i < K - 1; i++) {
			que.push(que.front());
			que.pop();
		}
		ret = que.front();
		que.pop();
	}
	return ret;
}
int main() {
	cout << solution(5, 3) << endl;
	return 0;
}
