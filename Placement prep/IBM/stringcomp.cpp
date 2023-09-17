/*
Consider a string, S, that is a series of characters, each followed by its frequency as an integer.
The string is not compressed correctly, so there may be multiple occurrences of the same character.
A properly compressed string will consist of one instance of each character in alphabetical order followed
by the total count of that character within the string.
*/

#include <iostream>
#include <string>
#include <map>

std::string compressString(const std::string &input)
{
    std::map<char, int> charCount;

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
    std::string compressed;
    for (const auto &pair : charCount)
    {
        compressed += pair.first;
        if (pair.second > 1)
        {
            compressed += std::to_string(pair.second);
        }
    }

    return compressed;
}

int main()
{
    std::string input;
    std::cout << "Enter the improperly compressed string: ";
    std::cin >> input;

    std::string compressed = compressString(input);
    std::cout << "Properly compressed string: " << compressed << std::endl;

    return 0;
}
