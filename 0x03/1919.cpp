#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	int arr1[26], arr2[26];
	fill(arr1, arr1 + 26, 0);
	fill(arr2, arr2 + 26, 0);
	for (size_t i = 0; i < s1.length(); i++)
	{
		arr1[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.length(); i++)
	{
		arr2[s2[i] - 'a']++;
	}
	int ret = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] != arr2[i])
			ret += abs(arr1[i] - arr2[i]);
	}
	cout << ret;
}
