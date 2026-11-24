class Solution {
public:
    // __int128 pro(int a,int b,vector<int>& nums) {
    //     __int128 p = 1;
    //     for(int i = a;i <= b;i++) {
    //         p *= nums[i];
    //     }
    //     return p;
    // }

    // int gcddd(int a,int b,vector<int>& nums) {
    //     int gcdd = nums[a];
    //     for(int i = a+1;i <= b;i++) {
    //         gcdd = gcd(gcdd, nums[i]);
    //     }
    //     return gcdd;
    // }

    // __int128 lcm(int a,int b,vector<int>& nums) {
    //     __int128 lcmm = nums[a];
    //     for(int i = a+1;i <= b;i++) {
    //         lcmm = (lcmm / gcd((long long)lcmm, (long long)nums[i])) * nums[i];
    //     }
    //     return lcmm;
    // }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        for(int i = 0;i < n;i++) {
            // int pro = nums[i];
            for(int j = i+1;j < n;j++) {
                bool isValid = true;
                for(int k = i;k < j;k++) {
                    if(gcd(nums[k],nums[j]) != 1) {
                        isValid = false;
                        break;
                    } 
                }

                if(!isValid) break;

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};