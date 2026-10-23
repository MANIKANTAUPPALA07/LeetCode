class Solution {
public:
    int Ans(int i,int n,int k,vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        i = (i+k-1) % nums.size();
        nums.erase(nums.begin()+i);
        return Ans(i,n,k,nums);
    }
    int findTheWinner(int n, int k) {
        vector<int> nums;
        for(int i = 1;i <= n;i++) {
            nums.push_back(i);
        }
        return Ans(0,n,k,nums);
    }
};