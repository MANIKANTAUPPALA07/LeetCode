class Solution {
public:
    void subSets(int idx,vector<int>& nums,vector<vector<int>>& answer,vector<int>& subset){

        if(idx == nums.size()){
            answer.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        subSets(idx + 1,nums,answer,subset);
        subset.pop_back();

        
        subSets(idx + 1,nums,answer,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;
        vector<int> subset;
        int idx = 0;
        subSets(idx,nums,answer,subset);
        return answer;
    }
};