# https://www.codingninjas.com/studio/library/distinct-passwords

mod=10**9+7
n = 2
k=3
distinct_passwords=1
for i in range(n):
    distinct_passwords*=(k-i)
    distinct_passwords%=mod
print(distinct_passwords)

# Time Complexity : O(N)
# Space Complexity : O(1)