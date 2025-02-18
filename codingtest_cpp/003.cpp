#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	int ns = numbers.size();
	for (int i = 0; i < ns; i++) {
		for (int j = i + 1; j < ns; j++) {
			answer.push_back(numbers[i] + numbers[j]);
		}
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	return answer;
}

int main() {
	int n;
	cin >> n;
	vector<int> lst(n, 0);
	for (int i = 0; i < n; i++) cin >> lst[i];
	lst = solution(lst);
	for (auto n : lst)
		cout << n << ' ';
	cout << '\n';
	return 0;
}
