class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX; // Initialize minPrice to a very high value
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                // Update the minimum price encountered so far
                minPrice = prices[i];
            }
            else
            {
                // Calculate the profit if sold on this day
                int currentProfit = prices[i] - minPrice;
                // Update the maximum profit if necessary
                maxProfit = max(maxProfit, currentProfit);
            }
        }

        return maxProfit;
    }
};