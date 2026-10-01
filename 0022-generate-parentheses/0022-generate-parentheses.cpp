class Solution {
public:
    void Fun(int n,int open,int cls,vector<string>& ans,string s) {
        if(open == n && cls == n) {
            ans.push_back(s);
            return;
        }

        //pick
        if(open < n) {
            s.push_back('(');
            Fun(n,open+1,cls,ans,s);
            s.pop_back();
        }

        if(open > cls) {
            s.push_back(')');
            Fun(n,open,cls+1,ans,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        Fun(n,0,0,ans,s);
        return ans;
    }
};