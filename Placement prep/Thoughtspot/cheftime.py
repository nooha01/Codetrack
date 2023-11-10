# https://practice.geeksforgeeks.org/problems/minimum-time-to-fulfil-all-orders/1

class Solution:
    @staticmethod
    def findMinTime(n, l, arr):
        s, e = 0, 10000007
        ans = -1

        # Loop to implement binary search
        while s <= e:
            mid = (s + e) // 2
            if Solution.isPossible(n, arr, l, mid):
                ans = mid
                e = mid - 1
            else:
                s = mid + 1
        return ans

    @staticmethod
    def isPossible(p, cook, n, mid):
        cnt = 0
        for i in range(n):
            c = 0
            time = mid
            perpratas = cook[i]
            while time > 0:
                time = time - perpratas
                if time >= 0:
                    c += 1
                    perpratas += cook[i]
            cnt += c
            if cnt >= p:
                return True
        return False
    
class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        l = int(input())
        
        
        arr=IntArray().Input(l)
        
        obj = Solution()
        res = obj.findMinTime(n, l, arr)
        
        print(res)
        
"""
We will iterate from 1 to 10000000 then check for every ith minute  if chefs can make all of the N donuts
For every ith minute, count the number of donuts each chef can make.
Sum up all the donuts made by all the chef and check whether it is greater or equal to N
We can easily calculate that the answer will lie between 10000000 for the given constraints.
"""