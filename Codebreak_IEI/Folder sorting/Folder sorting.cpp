#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<string>& logs)
{
  int level = 0;
  for (const string& log : logs)
  {
    if (log == "./") {
      // Stay
      continue;
    } else if (log == "../")
    {
      level = max(0, level - 1);
    } else {
      level++;
    }
  }
  return level;
}

int main()
{
  string input;
  getline(cin, input);
  input.erase(input.begin());
  input.erase(input.end() - 1);
  vector<string> logs;
  stringstream ss(input);
  string log;
  while (getline(ss, log, ','))
  {
    logs.push_back(log.substr(1, log.size() - 2));
  }
  cout << minOperations(logs) << endl;
  return 0;
}