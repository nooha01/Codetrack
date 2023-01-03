#include <iostream>
#include <vector>

using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> costs(n);
  for (int i = 0; i < n; i++)
  {
    cin >> costs[i];
  }

  vector<int> levels(m), mp(m);
  for (int i = 0; i < m; i++)
  {
    cin >> levels[i] >> mp[i];
  }
  for (int i = 0; i < m; i++) {
    int level = levels[i];
    int points = mp[i];
    while (1) {
      points -= costs[level - 1];
      if (points < 0) {
        cout << level << endl;
        break;
      }
      level += 1;
      if (level > n) {
        cout << "Never" << endl;
        break;
      }
    }
  }

  return 0;
}