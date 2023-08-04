// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    vector<int> sub;
    for(int i=0;i<nums.size();i++)
    {
        if(sub.empty() || sub[sub.size()-1]<nums[i])
        {
            sub.push_back(nums[i]);
        }
        else
        {
            auto t = lower_bound(sub.begin(), sub.end(), nums[i]);
            *t=nums[i];
        }
    }
    return sub.size();
    }
};