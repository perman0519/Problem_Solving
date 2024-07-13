#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string word;
	cin >> word;
	int alpha[26];
	fill(alpha, alpha+26, 0);
	for (char c : word)
		alpha[c - '97'] += 1;
	for (int i : alpha)
		cout << i << ' ';
}
