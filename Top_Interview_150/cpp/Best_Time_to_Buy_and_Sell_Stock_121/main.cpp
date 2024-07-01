#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

using namespace std;

int maxProfit(vector<int>& prices)
{
    int min_buy_in_price = prices[0];
    int max_profit = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        max_profit = max(max_profit, prices[i] - min_buy_in_price);
        if(prices[i] < min_buy_in_price)
        {
            min_buy_in_price = prices[i];
        }
    }
    return max_profit;
}

int main()
{
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << maxProfit(prices1) << endl;
    vector<int> prices2 = {7,6,4,3,1};
    cout << maxProfit(prices2) << endl;
}