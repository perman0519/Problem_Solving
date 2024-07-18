#include <bits/stdc++.h>
using namespace std;
int main(void) {
	cout.sync_with_stdio(0);
	list<int> li;
	int N;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		li.push_back(i + 1);
	}
	int front;
	while (li.size() != 1) {
		li.pop_front();
		front = li.front();
		li.pop_front();
		li.push_back(front);
	}
	cout << li.front();
}
//  1 2 3 4 5 6
//  2 3 4 5 6
//  3 4 5 6 2
//  4 5 6 2
//  5 6 2 4
//  6 2 4
//  2 4 6
//  4 6
//  6 4
//  4
