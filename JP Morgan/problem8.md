# Problem: Best Time to Buy and Sell Stock

## Problem Description


You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0

Constraints:

- 1 <= prices.length <= 105
- 0 <= prices[i] <= 104

<!-- --------------------------solution in C++----------------------------- -->

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  
        int maxProfit = 0;       
        
         for (int price : prices) {
             minPrice = min(minPrice, price);
             int profit = price - minPrice;
             maxProfit = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
};