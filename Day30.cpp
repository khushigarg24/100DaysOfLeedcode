//122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};

//121  Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;

        for(int i=1;i<prices.size();i++){
            int diff=prices[i]-mini;
             profit=max(profit,diff);
             mini=min(mini,prices[i]);
        }
        return profit;
    }
};