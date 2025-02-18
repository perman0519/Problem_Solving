#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
	// vector<int> ret(arr.begin(), arr.end());
	sort(arr.begin(), arr.end());

	return arr;
}


int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	arr = solution(arr);
	for (int n : arr)
		cout << n << ' ';
	cout << '\n';

	return 0;
}
