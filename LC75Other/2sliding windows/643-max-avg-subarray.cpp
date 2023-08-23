/*
643. Maximum Average Subarray I
Companies
You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average
value and return this value. Any answer with a calculation error less than 10-5 will be accepted.



Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000


Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
*/

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sz = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < sz; i++)
        {
            int sum = 0;
            if (i <= sz - k)
                for (int j = 0; j < k; j++)
                {
                    sum += nums[i + j];
                    cout << "num " << nums[i] << endl;
                }
            maxi = max(maxi, sum);
            cout << maxi << endl;
        }

        // 4 48 48 48 48 48

        double x = maxi;
        return (double)(x / (double)k);
    }
};

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        double ans = sum;

        for (int i = k; i < nums.size(); ++i)
        {
            sum = sum + nums[i] - nums[i - k];
            ans = max(ans, sum);
        }

        return ans / k;
    }
};