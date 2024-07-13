#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		bool t = true;
		string a, b;
		cin >> a >> b;
		int arr1[100];
		int arr2[100];
		fill(arr1, arr1 + 100, 0);
		fill(arr2, arr2 + 100, 0);
		for (char i : a) {
			arr1[i - 'a']++;
		}
		for (char i : b) {
			arr2[i - 'a']++;
		}
		for (int i = 0; i < 30; i++)
		{
			if (arr1[i] != arr2[i]) {
				cout << "Impossible\n";
				t  = false;
				break;
			}
		}
		if (t == true)
			cout << "Possible\n";
	}
}
