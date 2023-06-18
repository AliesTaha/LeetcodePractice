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