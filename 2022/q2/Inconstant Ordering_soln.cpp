#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 1; t1 <= t; ++t1) {
        int n; cin >> n;
        vector<int> mas(n);
        for (int i = 0; i < n; ++i) {
            cin >> mas[i];
        }
        string ans = "A";
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < mas[i] - 1; ++j) {
                    ans += 'B' + j;
                }
                if (i == n - 1) ans += 'A' + mas[i];
                else ans += 'A' + max(mas[i], mas[i + 1]);
            } else {
                for (int j = mas[i] - 1; j >= 0; --j) {
                    ans += 'A' + j;
                }
            }
        }

        cout << "Case #" << t1 << ": " << ans << '\n';

    }

}
