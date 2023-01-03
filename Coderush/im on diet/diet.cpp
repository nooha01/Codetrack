#include <iostream>
using namespace std;

int main() {
    int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    int items = 0;
    while (m > 0) {
      if (m >= 32) {
        items++;
        m -= 32;
      } else if (m >= 16) {
        items++;
        m -= 16;
      } else if (m >= 8) {
        items++;
        m -= 8;
      } else if (m >= 4) {
        items++;
        m -= 4;
      } else if (m >= 2) {
        items++;
        m -= 2;
      } else if (m >= 1) {
        items++;
        m -= 1;
      }
    }

    cout << items << endl;
  }

  return 0;
}