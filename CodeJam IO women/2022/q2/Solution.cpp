#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int z_ = 1; z_ <= t; ++z_) {
      cout << "Case #" << z_ << ": ";

      int d, n, u;
      cin >> d >> n >> u;
      vector<int> m(d), l(d), e(d), o(n);
      for (int i = 0; i < d; ++i) {
        cin >> m[i] >> l[i] >> e[i];
      }
      for (int i = 0; i < n; ++i) {
        cin >> o[i];
      }
      priority_queue<pair<int, int>> q;
      int cur = 0;
      int ans = n;
      for (int i = 0; i < n; ++i) {
        while (cur < d && m[cur] <= o[i]) {
          q.push({-(m[cur] + e[cur]), l[cur]});
          cur++;
        }
        int cnt = u;
        while (!q.empty() && cnt > 0) {
          pair<int, int> p = q.top();
          q.pop();
          if (-p.first <= o[i]) {
            continue;
          }
          if (p.second <= cnt) {
            cnt -= p.second;
          } else {
            p.second -= cnt;
            cnt = 0;
            q.push(p);
          }
        }
        if (cnt > 0) {
          ans = i;
          break;
        }
      }
      cout << ans << endl;
    }

    return 0;
}
