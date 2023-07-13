class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Make a hashmap, one of them will have the numbers, one will have the index
        unordered_map<int, int> dic;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int goal = target - num;

            // iterator points to the dictionary key value pair. it->first and it->second is the value
            auto it = dic.find(goal);

            if (it != dic.end())
            {
                return {it->second, i};
            }
            else
            {
                dic[num] = i;
            }
        }
        return {};
    }
};
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
////////////////////
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    }
};
////////////////////
*/

// Solution Hashmaps
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Unordered map to store numbers and their indices
        unordered_map<int, int> dic;

        // Loop through the vector
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int goal = target - num;

            // Check if the 'goal' value exists in the map
            auto it = dic.find(goal);

            if (it != dic.end())
            {
                // 'goal' value found in the map
                // Return a vector with the indices of the two numbers
                return {it->second, i};
            }
            else
            {
                // 'goal' value not found in the map
                // Add the current number and its index to the map
                dic[num] = i;
            }
        }

        // If no solution found, return an empty vector
        return {};
    }
};

// Solution 1
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> result;

        for (auto it1 = nums.begin(); it1 != nums.end(); it1++)
        {
            // Find the number that is target-*it1
            // If not found, set value to nums.end()
            // Start searching at it1+1
            auto it2 = find(it1 + 1, nums.end(), target - *it1);
            if (it2 != nums.end())
            {

                // Note that the value of an iterator is not the same as the value of the index

                // Iterators have some arbitrary value, but are in relation to one another

                // I am pushing, for example, 342-340 and 345-340 to return 2,5
                result.push_back(it1 - nums.begin());
                result.push_back(it2 - nums.begin());
                break;
            }
        }
        return result;
    }
};

// Solution 2
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;

        for (auto it1 = nums.begin(); it1 != nums.end(); ++it1)
        {
            for (auto it2 = it1 + 1; it2 != nums.end(); ++it2)
            {
                if (*it1 + *it2 == target)
                {
                    result.push_back(it1 - nums.begin());
                    result.push_back(it2 - nums.begin());
                    return result;
                }
            }
        }

        return result; // Empty vector if no solution found
    }
};
