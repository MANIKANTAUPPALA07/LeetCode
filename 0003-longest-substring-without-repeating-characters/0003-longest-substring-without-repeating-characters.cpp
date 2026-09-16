class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char , int> mpp;
        int maxi = 0;
        int left = 0;
        for(int right = 0;right < n;right++){
            mpp[s[right]]++;
            while(mpp[s[right]] > 1){
                mpp[s[left]]--;
                left++;
            }
            maxi = max(maxi , right - left + 1);
        }

        return maxi;
    }
};