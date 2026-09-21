class Solution {
public:
    
    void DFS(int i,vector<int>& nums,vector<int>& vis,vector<vector<int>>& ans,vector<int> &temp,int n) {
        if(i == n) {
            ans.push_back(temp);
            return;
        }

        for(int k = 0;k < n;k++) {
            if(vis[k] == 0) {
                vis[k] = 1;
                temp.push_back(nums[k]);
                DFS(i+1,nums,vis,ans,temp,n);
                temp.pop_back();
                vis[k] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n);
        vector<vector<int>> ans;
        vector<int> temp;
        DFS(0,nums,vis,ans,temp,n);

        return ans;
    }
};