// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

/*
1) Create an empty stack and push -1 to it.
   The first element of the stack is used
   to provide a base for the next valid string.
2) Initialize result as 0.
3) If the character is '(' i.e. str[i] == '('),
   push index'i' to the stack.

2) Else (if the character is ')')
   a) Pop an item from the stack (Most of the
      time an opening bracket)
   b) If the stack is not empty, then find the
      length of current valid substring by taking
      the difference between the current index and
      top of the stack. If current length is more
      than the result, then update the result.
   c) If the stack is empty, push the current index
      as a base for the next valid substring.
3) Return result.
*/

#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string str)
{
    int n = str.length();

    // Create a stack and push -1 as initial index to it.
    stack<int> stk;
    stk.push(-1);

    int result = 0;

    for (int i = 0; i < n; i++)
    {

        if (str[i] == '(')
            stk.push(i);
        else
        {
            // Pop the previous opening bracket's index
            if (!stk.empty())
            {
                stk.pop();
            }

            // Check if this length formed with base of current valid substring is more than max so far
            if (!stk.empty())
                result = max(result, i - stk.top());

            // If stack is empty. push current index as base for next valid substring (if any)
            else
                stk.push(i);
        }
    }
    return result;
}

int main()
{
    string str = "((()()";
    cout << findMaxLen(str) << endl;
    str = "()(()))))";
    cout << findMaxLen(str) << endl;
    return 0;
}

/*
Time Complexity: O(N), here N is the length of string.
Auxiliary Space: O(N)
*/

//////////////////////

/*
Another approach in O(1) auxiliary space and O(N) Time complexity:

The idea to solve this problem is to traverse the string on and keep track of the count of open parentheses and close parentheses with the help of two counters left and right respectively.
First, the string is traversed from the left towards the right and for every “(” encountered, the left counter is incremented by 1 and for every “)” the right counter is incremented by 1.
Whenever the left becomes equal to right, the length of the current valid string is calculated and if it greater than the current longest substring, then value of required longest substring is updated with current string length.
If the right counter becomes greater than the left counter, then the set of parentheses has become invalid and hence the left and right counters are set to 0.
After the above process, the string is similarly traversed from right to left and similar procedure is applied.
*/