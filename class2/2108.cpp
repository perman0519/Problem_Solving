#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

double arithmetic_mean(vector<int> &vec) {
	double sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}
	double ret_d = sum / vec.size();
	ret_d = round(ret_d);
	if (signbit(ret_d) && ret_d == 0.0) {
		ret_d = 0x0;
	}
	return ret_d;
}

int median(vector<int> &vec) {
	return vec[vec.size() / 2];
}

// 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
int mode(vector<int> &vec) {
	vector<int> mode_vec(8001, 0);
	for (int i = 0; i < vec.size(); i++) {
		mode_vec[vec[i] + 4000]++;
	}
	int max = 0;
	for (int i = 0; i < mode_vec.size(); i++) {
		if (mode_vec[i] > max) {
			max = mode_vec[i];
		}
	}
	int cnt = 0;
	int mode = 0;
	for (int i = 0; i < mode_vec.size(); i++) {
		if (mode_vec[i] == max) {
			cnt++;
			mode = i - 4000;
		}
		if (cnt == 2) {
			break;
		}
	}
	return mode;
}

int ragne(vector<int> &vec) {
	return vec[vec.size() - 1] - vec[0];
}

int main() {
	cout.sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << arithmetic_mean(v) << '\n';
	cout << median(v) << '\n';
	cout << mode(v) << '\n';
	cout << ragne(v) << '\n';
	return 0;
}
