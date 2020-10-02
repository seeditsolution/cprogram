/* Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one. */


class Solution {
public:
    int maxProfit(vector<int>& v) {
        int profit=0;
        int mini=INT_MAX;
        for(int i=0;i<v.size();i++){
            mini=min(mini,v[i]);
            profit=max(profit,(v[i]-mini));
            }
        return profit; 
        }
       
    
};
