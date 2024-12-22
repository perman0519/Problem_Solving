#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long k, n;
    cin >> k >> n;
    vector<long long> vk(k, 0);
    long long total = 0;
    for (long long i = 0; i < k; i++) {
        cin >> vk[i];
        total += vk[i];
    }
    long long start = 1;
    long long end = *max_element(vk.begin(), vk.end());
    while (start <= end) {
        long long mid = (start + end) / 2;
        long long cnt = 0;
        for (auto line : vk)
            cnt += line / mid;
        if (cnt < n)
            end = mid - 1;
        else
            start = mid + 1;
    }
    cout << end;
    return 0;
}