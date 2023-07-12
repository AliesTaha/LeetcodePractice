/*
11. Container With Most Water
Medium
You are given an integer array height of length n. There are n vertical lines drawn such that
the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Ex) 1
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water
(blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1



class Solution {
public:
    int maxArea(vector<int>& height) {

    }
};

*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        for (int i = 0; i < height.size()-1; i++)
        {
            int present = height[i];
            int max = 0;
            int area =0;

            for (int j = i+1; j < height.size()-1; j++)
            {
                int next=height[j];
                int length= j-i;
                int area= (present<next) ? present* length : next*length;
                if (max<area){
                    max=area;
                }

            }
        }
        return max;
    }
};

// Optimized solution
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        int left = 0;

        // Right is second last one;
        int right = height.size() - 1;

        // Keep going till left is less than right
        while (left < right)
        {
            int currentArea = min(height[left], height[right]) * (right - left);
            max = std::max(max, currentArea);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max;
    }
};

// Solution doesn't pass time complexity
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int currentArea = min(height[i], height[j]) * (j - i);
                max = std::max(max, currentArea);
            }
        }
        return max;
    }
};

/*
min(height[i], height[j]) calculates the minimum height between the two lines
represented by indices i and j. The minimum height is chosen because the area of water that can
be held between the lines is determined by the shorter line (as the water level cannot exceed
the height of the shorter line).
*/