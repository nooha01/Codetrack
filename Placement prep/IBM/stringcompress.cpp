/*
Consider a string, S, that is a series of characters, each followed by its frequency as an integer.
The string is not compressed correctly, so there may be multiple occurrences of the same character.
A properly compressed string will consist of one instance of each character in alphabetical order followed
by the total count of that character within the string.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

string compressString(const string &input)
{
    map<char, int> charCount;

    // Parse the input string
    for (size_t i = 0; i < input.length(); i++)
    {
        char currentChar = input[i];
        int count = 0;

        // Calculate the frequency
        while (i + 1 < input.length() && isdigit(input[i + 1]))
        {
            count = count * 10 + (input[i + 1] - '0');
            i++;
        }

        // Update the character count
        charCount[currentChar] += (count == 0) ? 1 : count;
    }

    // Create the compressed string
    string compressed;
    for (const auto &pair : charCount)
    {
        compressed += pair.first;
        if (pair.second > 1)
        {
            compressed += to_string(pair.second);
        }
    }

    return compressed;
}

int main()
{
    string input;
    cout << "Enter the improperly compressed string: ";
    cin >> input;

    string compressed = compressString(input);
    cout << "Properly compressed string: " << compressed << endl;

    return 0;
}
