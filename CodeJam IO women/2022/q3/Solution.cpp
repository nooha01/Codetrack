#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<pair<int, int>>> &g, vector<long long> &d, long long cur, int p) {
  d[v] = cur;
  for (auto to: g[v]) {
    if (to.first == p) continue;
    dfs(to.first, g, d, cur + to.second, v);
  }
}

int main() {

  //  freopen("input", "r", stdin);
  //  freopen("output", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int z_ = 1; z_ <= t; ++z_) {
      cout << "Case #" << z_ << ": ";

      int n;
      cin >> n;
      vector<vector<pair<int, int>>> g(n);
      long long sum = 0;
      for (int i = 0; i < n - 1; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
        sum += l;
      }
      long long maxd = 0;
      for (int i = 0; i < n; ++i) {
        vector<long long> d(n, 0);
        dfs(i, g, d, 0, i);
        for (int j = 0; j < n; ++j) {
          maxd = max(maxd, d[j]);
        }
      }
      long long ans = 2 * sum - maxd;
      cout << ans << endl;
    }

    return 0;
}
