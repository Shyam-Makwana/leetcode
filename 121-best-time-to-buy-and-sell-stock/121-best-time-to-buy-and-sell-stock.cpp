class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, profit=0;
        for(int i: prices){
            mini = min(i, mini);
            profit = max(profit, i-mini);
        }
        return profit;
    }
};