/*
Validate Token: A function takes time (hh: mm) and token, both in string type, as arguments.
I was to write a code in C/C++/Java/Python to check:
If the length of the token was 3.
If the time was before 12 noon, the first character of the token should be an alphabet, the second character should be a symbol or space, and the third character should be a number.
If the time was after 12 noon, the first character of the token should be a number, the second character should be a symbol or space, and the third character should be an alphabet.
The program would print “Validate token” if all conditions were met. Else, it was to display “Invalid token”.
*/

#include <iostream>
#include <string>
using namespace std;

bool isValidToken(string time, string token)
{
    if (token.length() != 3)
    {
        return false;
    }

    if (time < "12:00")
    {
        if (!isalpha(token[0]) || !isspace(token[1]) || !isdigit(token[2]))
        {
            return false;
        }
    }
    else
    {
        if (!isdigit(token[0]) || !isspace(token[1]) || !isalpha(token[2]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string time, token;

    cout << "Enter time (hh:mm): ";
    cin >> time;

    cout << "Enter token: ";
    cin >> token;

    if (isValidToken(time, token))
    {
        cout << "Validate token" << endl;
    }
    else
    {
        cout << "Invalid token" << endl;
    }

    return 0;
}
