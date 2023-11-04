# https://leetcode.com/problems/can-place-flowers/description/

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count=0
        N = len(flowerbed)
        if n==0:
            return True
        for i in range(N):
            if(flowerbed[i]==0):
                if (i == 0 or flowerbed[i - 1] == 0) and (i == N - 1 or flowerbed[i + 1] == 0):
                    flowerbed[i]=1
                    count += 1
        if(count>=n):
            return True
        else:
            return False
        