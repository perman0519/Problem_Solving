#include <bits/stdc++.h>
using namespace std;
int main(void) {
	cout.sync_with_stdio(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	list<int> li;
	for (int i = 0; i < n; i++)
	{
		li.push_back(i + 1);
	}
	int remove = k;
	cout << '<';
	auto it = li.erase(find(li.begin(), li.end(), k));
	cout << remove;
	while (li.size() != 0) {
		for (int i = 1; i < k; i++)
		{
			if (it != li.end())
				it++;
			else {
				it = li.begin();
				it++;
			}
		}
		if (it ==  li.end())
			it = li.begin();
		remove = *it;
		it = li.erase(it);
		cout << ", " << remove;
	}
	cout << '>';
}
