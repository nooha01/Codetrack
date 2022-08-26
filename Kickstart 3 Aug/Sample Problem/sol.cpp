#include <iostream>
#include <vector>

using namespace std;

void test() {
  int N, M;
  cin >> N >> M;
  vector<int> C(N);
  for (int i = 0; i < N; i++)
  {
    cin >> C[i];
  }
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += C[i];
  }
  int modulo = sum % M;
  cout << modulo << "\n";
}

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++)
  {
    cout << "Case #" << i << ": ";
    test();
  }
}

