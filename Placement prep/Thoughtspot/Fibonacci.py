# https://leetcode.com/problems/fibonacci-number/description/
# dynamic programming

class Solution:
    def fib(self, n: int) -> int:
        def fib(n):
            if Fib[n] != -1:
                return Fib[n]
            Fib[n] = fib(n-1) + fib(n-2)
            return Fib[n]
        if n==0:
            return 0
        if n==1:
            return 1
        Fib = [-1 for _ in range(n+1)]
        Fib[0] = 0
        Fib[1] = 1
        return fib(n)
        
# normal solution

def fib(self, n: int) -> int:
    first = 0
    second = 1
    if(n==0):
        return 0
    if(n==1):
        return 1
    if(n==2):
        return first+second
    third = first + second
    for i in range(2,n):
        first = second
        second = third
        third = first + second
    return third
        