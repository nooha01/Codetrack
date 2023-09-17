/*
Given an integer array, the values of the array need to separated into two subsets A and B whose intersection
is null and whose unions the entire array. The sum of values in set A must be strictly greater than sum of
values in set B, and number of elements in set A must be minimal. Return the values in set A.
Complete following function definition for the same.

For eg. Given arr ={3,7,5,6,2}, here A would be {6,7}.
Given arr = {2,3,4,4,5,9,7,8,6,10,4,5,10,10,8,4,6,4,10,1}, here A would be {8, 8, 9, 10, 10, 10, 10}.
*/

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> subsetA(vector<int> arr)
// {
//     std::sort(arr.begin(), arr.end());

//     // generate the knapsack items and find the max weight
//     struct Item
//     {
//         int value, weight, actual;
//     };
//     vector<Item> items;
//     int last = 0, max_weight = 0;
//     for (int item : arr)
//     {
//         max_weight += item;
//         if (items.size() == 0 || item != last)
//         {
//             items.push_back(Item{1, item, item});
//         }
//         else
//         {
//             items[items.size() - 1].value++;
//             items[items.size() - 1].weight += item;
//         }
//         last = item;
//     }
//     max_weight = (max_weight - 1) / 2;

//     // iterative 0/1 knapsack
//     vector<vector<int>> dp(items.size(), vector<int>(max_weight + 1, 0));
//     for (int i = 0; i < items.size(); i++)
//     {
//         for (int weight = 0; weight <= max_weight; weight++)
//         {
//             int skip = (i == 0) ? 0 : dp[i - 1][weight];
//             int include = 0;
//             if (items[i].weight <= weight)
//             {
//                 include = items[i].value;
//                 if (i > 0)
//                     include += dp[i - 1][weight - items[i].weight];
//             }
//             dp[i][weight] = std::max(include, skip);
//         }
//     }

//     // retrieve the items that were included in B
//     unordered_set<int> B;
//     int weight = max_weight;
//     for (int i = items.size() - 1; i > 0; i--)
//     {
//         if (dp[i - 1][weight] != dp[i][weight])
//         {
//             B.insert(items[i].actual);
//             weight -= items[i].weight;
//         }
//     }
//     if (weight > 0)
//         B.insert(items[0].actual);

//     // now invert B to get A
//     vector<int> A;
//     for (int num : arr)
//     {
//         if (B.find(num) == B.end())
//             A.push_back(num);
//     }

//     return A;
// }

#include <bits/stdc++.h>
using namespace std;

// Define a custom data structure to represent items for the knapsack
struct Item
{
    int value, weight, actual;
};

// Function to find a subset A from the given array arr
vector<int> subsetA(vector<int> arr)
{
    // Sort the input array in ascending order
    sort(arr.begin(), arr.end());

    // Initialize variables to calculate the knapsack
    vector<Item> items; // Stores the items for the knapsack
    int last = 0;       // Keeps track of the last element
    int maxWeight = 0;  // Maximum possible weight for knapsack

    // Create items for the knapsack and calculate maxWeight
    for (int item : arr)
    {
        maxWeight += item;
        if (items.empty() || item != last)
        {
            items.push_back(Item{1, item, item});
        }
        else
        {
            items[items.size() - 1].value++;
            items[items.size() - 1].weight += item;
        }
        last = item;
    }
    maxWeight = (maxWeight - 1) / 2;

    // Initialize a 2D vector for dynamic programming (0/1 knapsack)
    vector<vector<int>> dp(items.size(), vector<int>(maxWeight + 1, 0));

    // Fill the dynamic programming table
    for (int i = 0; i < items.size(); i++)
    {
        for (int weight = 0; weight <= maxWeight; weight++)
        {
            int skip = (i == 0) ? 0 : dp[i - 1][weight];
            int include = 0;
            if (items[i].weight <= weight)
            {
                include = items[i].value;
                if (i > 0)
                {
                    include += dp[i - 1][weight - items[i].weight];
                }
            }
            dp[i][weight] = max(include, skip);
        }
    }

    // Retrieve the items that were included in set B
    unordered_set<int> B;
    int weight = maxWeight;
    for (int i = items.size() - 1; i > 0; i--)
    {
        if (dp[i - 1][weight] != dp[i][weight])
        {
            B.insert(items[i].actual);
            weight -= items[i].weight;
        }
    }
    if (weight > 0)
    {
        B.insert(items[0].actual);
    }

    // Create set A by inverting set B
    vector<int> A;
    for (int num : arr)
    {
        if (B.find(num) == B.end())
        {
            A.push_back(num);
        }
    }

    return A;
}
