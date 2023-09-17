"""
Given an integer array, the values of the array need to separated into two subsets A and B whose intersection 
is null and whose unions the entire array. The sum of values in set A must be strictly greater than sum of values 
in set B, and number of elements in set A must be minimal. Return the values in set A.
Complete following function definition for the same.

For eg. Given arr ={3,7,5,6,2}, here A would be {6,7}.
Given arr = {2,3,4,4,5,9,7,8,6,10,4,5,10,10,8,4,6,4,10,1}, here A would be {8, 8, 9, 10, 10, 10, 10}.
"""

from collections import Counter
class Solution:
    def subSetA(self, arr):
        tmp = Counter(arr)
        items = list(tmp.items())

        items = sorted(items, key=lambda x: x[1])
        capacity = len(arr)//2
        maxWeight = sum(arr)/2
        knapsackMartrix = [[0 for x in range(0, capacity + 1 )] for y in range(0, len(items)+1)]
        for i in range(1, len(items) + 1):
            weight = items[i-1][1]
            value = items[i-1][1]*items[i-1][0]

            for c in range(0, capacity+1):
                if weight > c:
                    knapsackMartrix[i][c] = knapsackMartrix[i-1][c]

                else:
                    knapsackMartrix[i][c] = max(
                        knapsackMartrix[i-1][c], knapsackMartrix[i-1][c-weight] + value
                    )

                    if knapsackMartrix[i][c] > maxWeight:
                        return self.getItems(knapsackMartrix, items, i, c)

        return self.getItems(knapsackMartrix, items, len(knapsackMartrix)-1, len(knapsackMartrix[0])-1)

    def getItems(self, knapsackMartrix, items, i , c):
        tmp = []

        while i > 0:
            if knapsackMartrix[i][c] == knapsackMartrix[i-1][c]:
                i-=1
            else:

                tmp += [items[i-1][0]]*items[i-1][1]
                c-=items[i-1][1]
                i-=1
            if c==0:
                break

        return sorted(tmp)


if __name__ == "__main__":
    # arr = [5,5,5,10,10,10,11]
    # arr = [2,2,4,5,5,11]
    # arr = [2,5,5,9]
    # arr = [2,3,4,4,5,9,7,8,6,10,4,5,10,10,8,4,6,4,10,1]
    arr = [3,7,5,6,2]
    result = Solution().subSetA(arr)
    print(result)