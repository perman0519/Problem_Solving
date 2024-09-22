#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
// char ret[4];
char ret[16];

void recur(int cur, int start, vector<char>& vec, int consonant, int vowel) {
	if (cur == l) {
		if (consonant < 2 || vowel < 1)
			return;
		for (int i = 0; i < l; i++) {
			cout << ret[i];
		}
		cout << '\n';
		return;
	}
	int prev = -1;
	for (int i = start; i < c; i++) {
		if (cur > 0 && ret[cur - 1] > vec[i]) continue;
		ret[cur] = vec[i];
		prev = vec[i];
		if (vec[i] == 'a' || vec[i] == 'e' || vec[i] == 'i' || vec[i] == 'o' || vec[i] == 'u') {
			recur(cur + 1, i + 1, vec, consonant, vowel + 1);
		} else {
			recur(cur + 1, i + 1, vec, consonant + 1, vowel);
		}
	}
}

int main() {
	cin >> l >> c;
	vector<char> vec(c);
	for (int i = 0; i < c; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	recur(0, 0, vec, 0, 0);
}
