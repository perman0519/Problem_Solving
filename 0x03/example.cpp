#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N) {
	int ret[100];
	fill(ret, ret+100, 0);
	for (int i = 0; i < N; i++)
	{
		if (ret[100 - arr[i]] == 1)
			return 1;
		ret[arr[i]] = 1;
		// if (arr[i] > 50) {
		// 	ret[100 - arr[i]] += 1;
		// 	if (ret[100 - arr[i]] == 2)
		// 		return 1;
		// }
		// else {
		// 	ret[arr[i]] += 1;
		// 	if (ret[arr[i]] == 2)
		// 		return 1;
		// }
	}
	return 0;
}

int main(void) {
	int arr[] = {1, 52, 48};
	cout << func2(arr, 3);
	int arr2[] = {50, 42};
	cout << func2(arr2, 2);
	int arr3[] = {4, 13, 63, 87};
	cout << func2(arr3, 4);
	int arr4[] = {1,4, 13, 63, 83, 99};
	cout << func2(arr4, 6);
}
