#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e6 + 9;
int n;
int a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        ans += cur;
        if (i < n - 1 && a[i + 1] != a[i])
            cur++;
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        cout << "Case #" << j + 1 << ": ";
        solve();
        cout << "\n";
    }
}

