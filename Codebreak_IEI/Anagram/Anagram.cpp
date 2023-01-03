#include <bits/stdc++.h>
using namespace std;

bool Anagram(string s, string t)
{
  if (s.length() != t.length())
  {
    return false;
  }
  unordered_map<char, int> s_count;
  for (char c : s)
  {
    s_count[c]++;
  }
  for (char c : t)
  {
    if (s_count.count(c) == 0)
      return false;
    s_count[c]--;
  }
  for (auto& p : s_count) 
  {
    if (p.second != 0) 
      return false;
  }
  return true;
}

int main() {
  cout << boolalpha; 
  string s,t;
  cin >> s;
  cin >> t;
  cout << Anagram(s, t) << endl;
}