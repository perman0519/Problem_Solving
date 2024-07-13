#include <bits/stdc++.h>
using namespace std;
int main()  {
	cout.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		list<char> li;
		cin >> str;
		auto it = li.begin();
		for (char c : str)
		{
			if (c == '<') {
				if (it != li.begin())
					it--;
			}
			else if (c == '>') {
				if (it != li.end())
					it++;
			}
			else if (c == '-') {
				if (it != li.begin())
					it = li.erase(--it);
			}
			else {
				it = li.insert(it, c);
				it++;
			}
		}
		for (char c : li)
		{
			cout << c;
		}
		cout << '\n';
	}
}
