/*
217. Contains Duplicate
Given an integer array nums, return true if any value
appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> dic;

        for (int i = 0; i < nums.size(); i++)
        {
            dic[nums[i]] += 1;
        }

        for (auto it = dic.begin(); it != dic.end(); it++)
        {
            if (it->second > 1)
                return true;
        }
        return false;
    }
};