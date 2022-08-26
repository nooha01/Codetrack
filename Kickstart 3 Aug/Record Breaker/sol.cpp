#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t, t1 = 1;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		vector<int> arrMax(n);
		arrMax[0] = v[0];

		for (int i = 1; i < n; i++) {
			arrMax[i] = max(arrMax[i - 1], v[i]);
		}

		int count = 0;

		for (int i = 1; i < n - 1; i++) {
			if (v[i] > arrMax[i - 1] && v[i] > v[i + 1]) {
				count++;
			}
		}

		if (n >= 1 && v[0] > v[1])
			count++;
		if (n >= 2 && v[n - 1] > arrMax[n - 2])
			count++;

		cout << "Case #" << t1++ << ": " << count << endl;
	}

	return 0;
}
