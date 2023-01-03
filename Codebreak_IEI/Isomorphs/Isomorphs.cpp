#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    
    unordered_map<char, char> map;
    unordered_set<char> set;
    
    for (int i = 0; i < s.length(); i++)
    {
        char one = s[i], two = t[i];
        if (map.find(one) != map.end())
        {
            if (map[one] != two) {
                return false;
            }
        }
        else {
            if (set.find(two) != set.end()) {
                return false;
            }
            map[one] = two;
            set.insert(two);
        }
    }
    return true;
}
 
int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    cout << (isIsomorphic(s,t) ? "true" : "false") << endl;
    return 0;
}