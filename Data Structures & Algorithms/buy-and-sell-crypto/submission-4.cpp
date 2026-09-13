class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize minprice to a large value to find the lowest price
        int minprice = INT_MAX;  
        
        // Initialize maxprofit to 0, as no profit is made at the start
        int maxprofit = 0;

        // Loop through the prices array to calculate the maximum profit
        for (int price : prices) {
            // Update minprice if the current price is lower than the previous minprice
            minprice = min(minprice, price);               // Track the lowest price encountered

            // Calculate the profit if we sell at the current price and buy at minprice
            maxprofit = max(maxprofit, price - minprice);   // Update max profit if this profit is higher
        }

        // Return the maximum profit found
        return maxprofit;  
    }
};
