# https://leetcode.com/problems/next-greater-element-i/

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        temp = [-1] * len(nums1)
        for i in nums1:
            for j in range(len(nums2)):
                if i == nums2[j]:
                    for k in range(j + 1, len(nums2)):
                        if nums2[k] > nums2[j]:
                            temp[nums1.index(i)] = nums2[k]
                            break
        return temp
