class Solution {
public:
    int min_price = INT_MAX;
    int Solve(int idx,int budget,vector<vector<int>>& items,vector<int>& free,vector<vector<int>>& dp) {
        if(idx == items.size()) {
            return budget/min_price;
        }

        if(dp[idx][budget] != -1) {
            return dp[idx][budget];
        }
        int np = Solve(idx+1,budget,items,free,dp);

        int p = 0;
        if(budget >= items[idx][1]) {
            p = 1+free[idx] + Solve(idx+1,budget - items[idx][1],items,free,dp);
        }

        return dp[idx][budget] = max(p,np);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(j != i && items[j][0] % items[i][0] == 0) {
                    free[i]++;
                }
            }
        }

        for(int i = 0;i < n;i++) {
            min_price = min(min_price,items[i][1]);
        }

        vector<vector<int>> dp(n , vector<int> (budget+1 , -1));
        return Solve(0,budget,items,free,dp);
    }
};