/*
Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.length() - 1;
        ()
        {
            if nums
                [i]
        }
    }
} class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        //-1,0,3,5,9,12
        int left = 0;
        int right = nums.size() - 1;
        // 0, 5
        //                  1-> 6]
        for (int i = 0; i < nums.size(); i++)
        {
            // 1
            int halfway = ((right + left) / 2);
            if (target > nums[halfway])
            {
                left = halfway + 1;
                // left=2
                continue;
            }
            else if (target < nums[halfway])
            {
                right = halfway - 1;
                continue;
            }
            else if (target == nums[halfway])
            {
                return halfway;
            }
        }
        return -1;
    }
};