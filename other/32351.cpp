#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n, k;
	double pastbpm;
	double ret = 0.0f;
	vector<double> s;
	vector<int> m;
	cin >> n >> pastbpm >> k;
	int past = 1;
	for (int i = 0; i < k; i++) {
		int next;
		double nextbpm;
		cin >> next >> nextbpm;
		ret += (next - past) * 4 * (60 / pastbpm);
		past = next;
		pastbpm = nextbpm;
	}
	ret += (n - past + 1) * 4 * (60 / pastbpm);
	std::cout << std::fixed << std::setprecision(12) << ret << std::endl;
}
