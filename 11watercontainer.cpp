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