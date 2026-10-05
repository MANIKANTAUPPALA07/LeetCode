class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<int> pre(n);
        vector<int> suf(n);
        for(int i = 0;i < n;i++) {
            if(i % k == 0) pre[i] = nums[i];
            else pre[i] = max(pre[i-1],nums[i]);
        }

        suf[n-1] = nums[n-1];
        for(int i = n-2;i >= 0;i--) {
            if(i % k == k-1) suf[i] = nums[i];
            else suf[i] = max(suf[i+1],nums[i]);
        }
        
        for(int i = k-1;i < n;i++) {
            ans.push_back(max(pre[i],suf[i - k + 1]));
        }
        return ans;
    }
};