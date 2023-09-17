
# Consider a string, S, that is a series of characters, each followed by its frequency as an integer. 
# The string is not compressed correctly, so there may be multiple occurrences of the same character. 
# A properly compressed string will consist of one instance of each character in alphabetical order followed 
# by the total count of that character within the string.


def compress_string(input_str):
    # Initialize an empty dictionary to store character frequencies
    char_freq = {}
    i = 0

    # Loop through the input string
    while i < len(input_str):
        # Get the current character
        char = input_str[i]

        # Initialize a variable to store the frequency
        freq = 0

        # Move to the next position to read the frequency digits
        i += 1

        # Read all consecutive digits to get the frequency
        while i < len(input_str) and input_str[i].isdigit():
            freq = freq * 10 + int(input_str[i])
            i += 1

        # Update the character frequency in the dictionary
        if char in char_freq:
            char_freq[char] += freq
        else:
            char_freq[char] = freq

    # Sort characters alphabetically
    sorted_chars = sorted(char_freq.keys())

    # Generate the compressed string
    compressed_str = ''
    for char in sorted_chars:
        compressed_str += char + str(char_freq[char])

    return compressed_str

# Example usage:
input_str = "a3b2c1a2"
compressed_result = compress_string(input_str)
print(compressed_result)  # Output: "a5b2c1"
