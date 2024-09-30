#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n], b[m], ret[n + m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (a[i] < b[j])
			ret[k++] = a[i++];
		else ret[k++] = b[j++];
	}
	while (i < n)
		ret[k++] = a[i++];
	while (j < m)
		ret[k++] = b[j++];
	for (int i = 0; i < n + m; i++) cout << ret[i] << ' ';
}
