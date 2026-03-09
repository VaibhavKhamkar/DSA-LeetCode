/*
Problem: Two Sum
Platform: LeetCode
Link: https://leetcode.com/problems/two-sum/

Approach:
Use a hash map to store numbers and their indices.
For each element, check if the complement (target - nums[i]) exists.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];

            if(mp.count(complement)){
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
