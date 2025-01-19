#include <iostream>
#include <deque>
using namespace std;

int find_maximp(deque<pair<int, int> > &deq) {
    int ret = 0;
    for (auto p : deq) {
        if (ret < p.second)
            ret = p.second;
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        deque<pair<int, int> > deq;
        int max_imp = 0;
        for (int i = 0; i < n; i++) {
            int imp;
            cin >> imp;
            if (max_imp < imp)
                max_imp = imp;
            deq.push_back({i, imp});
        }
        int cnt = 0;
        while (true) {
            if (max_imp == deq.front().second) {
                cnt++;
                if (deq.front().first == q) {
                    cout << cnt << '\n';
                    break;
                }
                deq.pop_front();
                max_imp = find_maximp(deq);
            }
            else {
                auto p = deq.front();
                deq.pop_front();
                deq.push_back(p);
            }
        }
    }
    return 0;
}