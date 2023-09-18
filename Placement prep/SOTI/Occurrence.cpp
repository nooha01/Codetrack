// https://www.geeksforgeeks.org/program-count-occurrence-given-character-string/

// using direct function

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Strineegee";
    char c = 'e';
    cout << count(str.begin(), str.end(), c);
    return 0;
}

// using recursion

/*
Base Case:
if str.length == 0
    return 0

int count = 0;

if (s[0] == ch)
    count++;
count += countinString(ch, s.substr(1));

    return count;
*/
