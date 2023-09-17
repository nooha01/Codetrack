""" 
For each element of an array of non-negative integers, arrin], is calculated as:
pre[i] = arr[1JIJ⊕ arrl2JIJO . . . ⊕arrli]
Here x ⊕ y is the bitwise XOR of x and y. The array pref[n] contains the prefix XOR of all elements in arr[n]where 1 s is n.
Given the array pref, find the original array arr.
Note: There is always a unique arr for a given pref.
"""

def findOriginalArray(pref):
    n = len(pref)
    arr = [0] * n

    # Calculate arr[0] directly
    arr[0] = pref[0]

    # Calculate arr[i] for i > 0
    for i in range(1, n):
        arr[i] = arr[i - 1] ^ pref[i]

    return arr

"""
Given the pref array, which contains the prefix XOR of some original array arr, we want to reverse this process to 
find the original arr. To do this, we can take advantage of the properties of the bitwise XOR operation. 
Specifically, we'll use the fact that if c = a ⊕ b, then a = b ⊕ c and b = a ⊕ c. 
We'll iterate through the pref array and use these properties to calculate the original values of arr.
"""

########################

"""
Suppose we have pref = [3, 6, 1, 7]. Using the solution:

Initialize arr = [0, 0, 0, 0].

Calculate arr[0] directly as arr[0] = pref[0], so arr = [3, 0, 0, 0].

For i > 0:

Calculate arr[1] as arr[0] ⊕ pref[1], which is 3 ⊕ 6 = 5. So, arr = [3, 5, 0, 0].
Calculate arr[2] as arr[1] ⊕ pref[2], which is 5 ⊕ 1 = 4. So, arr = [3, 5, 4, 0].
Calculate arr[3] as arr[2] ⊕ pref[3], which is 4 ⊕ 7 = 3. So, arr = [3, 5, 4, 3].
The final arr is [3, 5, 4, 3], which represents the original array from which the pref array was derived.
"""