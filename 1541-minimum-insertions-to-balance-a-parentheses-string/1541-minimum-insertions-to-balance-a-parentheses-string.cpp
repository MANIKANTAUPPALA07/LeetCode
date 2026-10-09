class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<char> st;
        // stack<char> st1;
        int s2 = 0;
        int ans = 0;
        for(int i = 0;i < n;i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }
            else{
                if(!st.empty()) {
                    if(i + 1 < n && s[i+1] == ')') {
                        i++;
                    }
                    else{
                        ans++;
                    }
                    st.pop();
                }
                else{
                    if(i+1 < n && s[i+1] == ')') {
                        ans++;
                        i++;
                    }
                    else{
                        ans += 2;
                    }
                }
                
            }
        }

        return ans += (2 * st.size());
    }
};