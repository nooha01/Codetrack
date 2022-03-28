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
      int n;
      cin >> n;
      vector<string> c(2 * n);
      for (int i = 0; i < 2 * n; ++i) {
        cin >> c[i];
      }
      int x = 0;
      int y = 0;
      int z = 0;
      int t = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (c[i][j] == 'I') x++;
        }
        for (int j = n; j < 2 * n; ++j) {
          if (c[i][j] == 'I') y++;
        }
      }
      for (int i = n; i < 2 * n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (c[i][j] == 'I') z++;
        }
        for (int j = n; j < 2 * n; ++j) {
          if (c[i][j] == 'I') t++;
        }
      }
      int ans = 2 * n * 2 * n * 2;
      for (int a = 0; a <= n * n; ++a) {
        for (int b = 0; b <= n * n; ++b) {
          int xx = max(x - a, a - x);
          int yy = max(y - b, b - y);
          int zz = max(z - b, b - z);
          int tt = max(t - a, a - t);
          ans = min(ans, xx + yy + zz + tt);
        }
      }
      cout << ans << endl;
    }

    return 0;
}
