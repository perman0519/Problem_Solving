#include <iostream>
#include <vector>
using namespace std;

void find_node_par(int now, vector<vector<int> > &tree, vector<bool> &visited, vector<int> &par) {
    if (visited[now] == true) {
        return ;
    }
    visited[now] = true;
    for (auto next : tree[now]) {
        if (par[next] == 0)
            par[next] = now;
        find_node_par(next, tree, visited, par);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > tree(n + 1, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    vector<int> par(n + 1, 0);
    vector<bool> visited(n + 1, false);
    find_node_par(1, tree, visited, par);
    for (int i = 2; i <= n; i++) {
        cout << par[i] << '\n';
    }
    return 0;
}