#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 1; t1 <= t; ++t1) {
        int m, n, p;
        cin >> m >> n >> p;

        vector<vector<int>>ad;

        vector<int>used;
        ad.resize(n + m);
        used.resize(n);
        for (int i = 0; i < n + m; ++i) {
            string s; cin >> s;
            for (int j = 0; j < n + m; ++j) {
                if (j == i)continue;
                if (s[j] == 'Y') {
                    ad[j].push_back(i);
                }
            }
        }
        vector<int>ans(p, -1);
        for (int i = 0; i < p; ++i) {
            int a, b; cin >> a >> b; --a, --b;
            vector<int>dist(n + m, n + m + 214);
            dist[a] = 0;
            queue<int>q;
            q.push(a);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto v : ad[u]) {
                    if (dist[v] > dist[u] + 1) {
                        if (v < m) {
                            q.push(v);
                        }
                        dist[v] = dist[u] + 1;
                    }
                }
            }
            if (dist[b] != n + m + 214) {
                int man = dist[b] - 1;
                ans[i] = 0;
                while (man > 3) {
                    ++ans[i];
                    man -= (man + 2) / 3;
                }
                ans[i] += man;
            }
        }


        cout << "Case #" << t1 << ":";
        for (auto el : ans) {
            cout << ' ' << el;
        }
        cout << '\n';
    }

}
