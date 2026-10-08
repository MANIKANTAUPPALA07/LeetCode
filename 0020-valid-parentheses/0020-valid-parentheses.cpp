class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        if(s[0] == ')' || s[0] == '}' || s[0] == ']' || s[n-1] == '(' || s[n-1] == '{' || s[n-1] == '['){
            return false;
        }
        for(int i = 0;i < n;i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else{
                if(!st.empty()) {
                    char top = st.top();
                    if(s[i] == ')') {
                        if(top == '(') {
                            st.pop();
                            continue;
                        }
                        return false;
                    }
                    else if(s[i] == '}') {
                        if(top == '{') {
                            st.pop();
                            continue;
                        }
                        return false;
                    }
                    else if(s[i] == ']') {
                        if(top == '[') {
                            st.pop();
                            continue;
                        }
                        return false;
                    }
                }
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};