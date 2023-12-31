class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ans, max = INT_MIN;

        unordered_map<int, int> dic;

        for (int i = 0; i < nums.size(); i++)
        {
            dic[nums[i]] += 1;
        }

        for (auto it = dic.begin(); it != dic.end(); it++)
        {
            if (it->second > max)
            {
                max = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int maxi=INT_MIN;
        int ans;
        unordered_map<int, int> dic;

        for (int i = 0; i < nums.size(); i++){
            dic[nums[i]]++;
        }

        for (auto it= dic.begin(); it!=dic.end(); it++){
            maxi=max(it->second, maxi);
            if (maxi==(it->second))
                ans=it->first;
        }
        return ans;
    }};
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ans, max = INT_MIN;
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++)
        {
            dic[nums[i]] += 1;
        }

        for (auto it = dic.begin(); it != dic.end(); ++it)
        {
            if ((it->second) > max)
            {
                max = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};